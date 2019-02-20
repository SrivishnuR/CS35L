#include<stdio.h>
#include<string.h>

int main(int argc, char** argv) {
  int i, j;

  if (argc != 3) {
    fprintf(stderr, "Incorrect number of arguments");
    exit(1);
  }

  char *from = argv[1];
  char *to = argv[2];

  if(strlen(from) != strlen(to)) {
    fprintf(stderr, "From and to are not same length");
    exit(1);
  }

  for(i = 0; i < strlen(from) - 1; i++) {
    for(j = i + 1; j < strlen(from); j++) {
      if(from[i] == from[j]) {
	fprintf(stderr, "From has duplicate bytes");
	exit(1);
      }
    }
  }
  
  int ch = getchar();
  int translated = 0;

  while(ch != EOF) {
    for(i = 0; i < strlen(from); i++) {
      if(from[i] == ch) {
	putchar(to[i]);
	translated = 1;
      }
    }
    
    if(!translated) {
      putchar(ch);
    }
      
    translated = 0;
    ch = getchar();
  }
}
