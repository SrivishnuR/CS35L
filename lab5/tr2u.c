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

  int ch;
  int result = read(0, &ch, 1);

  while(result != 0) {
    for (i = 0; i < strlen(from); i++){
      if (from[i] == (char)ch)
        ch = to[i];
    }

    write(1, &ch, 1);
    result = read(0, &ch, 1);
  }

  return 0;
}
