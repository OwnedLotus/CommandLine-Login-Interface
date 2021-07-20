#include <stdio.h>
#include "string.h"

int main(int argc, char const **argv)
{
  if( argc == 1)
  {
    puts(argv[0]);
  } 
  else
  {
    puts("no input given");
  }
  return 0;
}