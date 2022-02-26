#include <stdio.h>

int main() {
  FILE *fptr;
  char filename[50];
  char c;

  printf("Enter the filename of the file to create: ");
  gets(filename);
  fptr = fopen(filename, "w");

  /* write to file */
  fprintf(fptr, "Inventory\n");
  fprintf(fptr, "%d %s %f\n", 100, "Widget", 0.29);
  fputs("End of List", fptr);

  fclose(fptr);

  /* read the file contents */
  fptr = fopen(filename, "r");
  while ((c = getc(fptr)) != EOF)
    printf("%c", c);
  fclose(fptr);
  return 0;
}
