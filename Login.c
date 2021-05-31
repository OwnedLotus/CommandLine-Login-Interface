#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userAccount.h"

int StartUp ();
void SignUp(FILE *fp);
void Login(FILE *fp);
void FileClose(FILE *fp);

int main(int argc, char const *argv[])
{
  FILE *fp;
  char *dataBaseName = "login.txt";
  int choice;
  char read = 'r';
  char readWrite = "r+";

  start : choice = StartUp();

  fp = dataBaseName;

  switch (choice)
  {
  case 1:
    fopen(fp, readWrite);
    SignUp(fp);
    break;

  case 2:
    fopen(fp, read);
    Login(fp);
    break;

  case 0:
    printf("Goodbye!");
    return 0;

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

void SignUp(FILE *fp)
{
  FileClose(fp);
  userAccount user1;

  printf("Please Enter the Information in the Form!");
  

}

void Login(FILE *fp)
{  
  FileClose(fp);
}

void FileClose(FILE *fp)
{
  fclose(fp);
}