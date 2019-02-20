#include <stdio.h>
#include <stdlib.h>

int compare(const void *arg1, const void *arg2);

int frobcmp(const char *arg1, const char *arg2);

int main() {
  char **words = NULL;
  int wordCount;
  char *word;
  int letters;
  char ch;

  wordCount = 0;
  do {
    letters = 0;

    word = NULL;
    while((ch = getchar()) != EOF && ch != ' ') {
      word = (char*)realloc(word, (letters + 1) * sizeof(char));
      *(word + letters) = ch;
      letters++;
      
      if (ferror(stdin)) {
	fprintf(stderr, "Read error");
	exit(1);
      }

      if (!word) {
	fprintf(stderr, "Memory allocation error");
	exit(1);
      }
    }
    
    if (word) {
      word = (char*)realloc(word, (letters + 1) * sizeof(char));
      *(word + letters) = ' ';
      
      words = (char**)realloc(words, (wordCount + 1) * sizeof(char*));    
      *(words + wordCount) = word;
      wordCount++;

      if (!word || !words) {
	fprintf(stderr, "Memory allocation error");
	exit(1);
      }
    }
  } while (ch != EOF);

  qsort(words, wordCount, sizeof(char*), compare);

  int i, j;
  
  for(i = 0; i < wordCount; i++) {
    j = 0;
    do {
      ch = *(*(words + i) + j);
      putchar(ch);
      j++;

      if (ferror(stdout)) {
	fprintf(stderr, "Write error");
	exit(1);
      }
    } while(ch != ' ');
    
    free(*(words + i));
  }
  
  free(words);
}

int compare(const void *arg1, const void *arg2) {
  const char* a = *(const char**)arg1;
  const char* b = *(const char**)arg2;
  return frobcmp(a, b);
}

int frobcmp(const char *arg1, const char *arg2) {
  while(1) {
    if(*arg1 == ' ' && *arg2 == ' ')
      return 0;

    if(*arg1 == ' ')
      return -1;

    if(*arg2 == ' ')
      return 1;

    if(*arg1 != *arg2) {
      if(((*arg1 ^ 42) - (*arg2 ^ 42)) > 0)
	return 1;
      else
	return -1;
    }

    arg1++;
    arg2++;
  }
}
