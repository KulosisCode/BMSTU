#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE 200809L

int main(void)
{
  FILE *f;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  f = fopen("a.txt", "r");
  if (f)
  {
    while ((read = getline(&line, &len, f)) != -1)
    {
        printf("len %d, read %d\n", (int) len, (int) read);
        printf("%s", line);
    }
        
    free(line);
    fclose(f);
  }
  return 0;
}
