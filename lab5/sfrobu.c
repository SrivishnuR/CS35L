#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

int ignore = 0;

int compare(const void *arg1, const void *arg2);

int frobcmp(const char *arg1, const char *arg2);

int main(int argc, char *argv[]) {
  if(argc == 2 && **(argv + 1) == '-' && *(*(argv + 1) + 1) == 'f')
    ignore = 1;
  else if(argc != 1) {
    fprintf(stderr, "Options error\n");
    exit(1);
  }

  char **words = NULL;
  char *file = NULL;
  int wordCount = 0;
  unsigned int fsize = 0;
  int wordCounter, letters;
  char ch;

  struct stat fileInfo;
  ssize_t result;

  if(fstat(0, &fileInfo) < 0) {
    fprintf(stderr, "Error reading file\n");
    exit(1);
  }
  
  if(S_ISREG(fileInfo.st_mode) && (fsize = fileInfo.st_size) != 0) {
    file = (char*)realloc(file, fsize * sizeof(char));
    
    if(!file) {
      fprintf(stderr, "Memory allocation error\n");
      exit(1);
    }
    
    if(read(0, file, fsize) < 0) {
      fprintf(stderr, "Read error\n");
      exit(1);
    }
  }
  
  while ((result = read(0, &ch, 1)) != 0) {
    if (result < 0) {
      fprintf(stderr, "Read error\n");
      exit(1);
    }
    
    file = (char*)realloc(file, (fsize + 1) * sizeof(char));
    
    if (!file) {
      fprintf(stderr, "Memory allocation error\n");
      exit(1);
    }
    
    *(file + fsize) = ch;
    fsize++;
  }

  if (fsize > 0) {    
    if(*(file + fsize - 1) != ' ') {
      file = (char*)realloc(file, (fsize + 1) * sizeof(char));
      *(file + fsize) = ' ';
      fsize++;
    }
    
    if(*file != ' ')
      wordCount++;
    
    for(letters = 0; letters < fsize - 1; letters++) {
      if(*(file + letters) == ' ' && *(file + letters + 1) != ' ') {
	wordCount++;
      }
    }
    
    words = (char**)realloc(words, wordCount * sizeof(char*));
    
    if(!words) {
      fprintf(stderr, "Memory allocation error\n");
      exit(1);
    }
    
    wordCounter = 0;
    
    if(*file != ' ') {
      *(words + wordCounter) = file;
      wordCounter++;
    }
    
    for(letters = 0; letters < fsize - 1; letters++) {
      if(*(file + letters) == ' ' && *(file + letters + 1) != ' ') {
	*(words + wordCounter) = (file + letters + 1);
	wordCounter++;
      }
    }
  }
  
  qsort(words, wordCount, sizeof(char*), compare);
  
  for(wordCounter = 0; wordCounter < wordCount; wordCounter++) {
    letters = 0;
    
    while(*(*(words + wordCounter) + letters) != ' ')
      letters++;
    
    if (write(1, *(words + wordCounter), letters + 1) < 0) {
      fprintf(stderr, "Write error");
      exit(1);
    }
  }
  
  free(file);
  free(words);
}

int compare(const void *arg1, const void *arg2) {
  const char* a = *(const char**)arg1;
  const char* b = *(const char**)arg2;
  return frobcmp(a, b);
}

int frobcmp(const char *arg1, const char *arg2) {
  char arg1u, arg2u;

  while(1) {
    if(*arg1 == ' ' && *arg2 == ' ')
      return 0;
    
    if(*arg1 == ' ')
      return -1;
    
    if(*arg2 == ' ')
      return 1;
    
    arg1u = (*arg1 ^ 42);
    arg2u = (*arg2 ^ 42);
    
    if(ignore) {
      if(arg1u < UCHAR_MAX || arg1u == EOF)
	arg1u = toupper(arg1u);
      
      if(arg2u < UCHAR_MAX || arg2u == EOF)
	arg2u = toupper(arg2u);
    }
    
    if(arg1u != arg2u) {
      if(arg1u - arg2u > 0)
	return 1;
      else
	return -1;
    }
    
    arg1++;
    arg2++;
  }
}
