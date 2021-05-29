#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userAccount.h"

int StartUp ();
void SignUp(FILE * fp);
void Login(FILE * fp);

int main(int argc, char const *argv[])
{
  FILE *fp;
  int choice;


  start : choice = StartUp();

  switch (choice)
  {
  case 1:
    SignUp(fp);
    break;
  case 2:
    Login(fp);
  case 0:
    printf("Goodbye!");
    return 1;
  default:
    printf("Incorrect input enter please enter a given input!\n");
    goto start;
    break;
  }

  return 0;
}

int StartUp()
{
  int answer;

  printf("Welcome!\n");
  printf("If you would like to sign up press 1.\n");
  printf("If you would like to login press 2.\n");
  printf("If you would like to exit press 0.\n");
  scanf(" %i\n", &answer);

  return answer;
}

void SignUp(FILE * fp)
{

}

void Login(FILE * fp)
{
  fopen(fp, 'r' );
  
}