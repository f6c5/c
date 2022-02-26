#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main() {  
  FILE *fptr;
  int c;

  errno = 0;
  fptr = fopen("c:\\myfile.txt", "r");
  if (fptr == NULL) {
    fprintf(stderr, "Error opening file. %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  while ((c = getc(fptr)) != EOF) /* read the rest of the file */
    printf("%c", c);

  if (ferror(fptr)) {
    printf("I/O error reading file.");
    exit(EXIT_FAILURE);
  }
  else if (feof(fptr))
    printf("End of file reached.");

  fclose(fptr);
  return 0;
}
