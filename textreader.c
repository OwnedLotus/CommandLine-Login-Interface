#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
  FILE *fp;
  int c;

  fp = fopen("login.txt", "r");
  if (fp)
  {
    while ((c = getc(fp)) != EOF)
    {
      putchar(c);
    }
  }

  fclose(fp);

  return 0;
}
