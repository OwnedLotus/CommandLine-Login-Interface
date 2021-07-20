/*
  This program is created as a basic login interface build to
  utilize a file database and scan the database to check if the 
  user exists.

  If the user does not exist, there is a user creation part of 
  the program.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//adds specific functionality to the program see "userAccount.h"
#include "userAccount.h" 

int StartUp ();
void SignUp(FILE *fp);
void Login(FILE *fp);
void FileClose(FILE *fp);

char* cmdInput(int argc, char const *argv[]);

void HelpFunct();

int main(int argc, char const *argv[])
{ 
  //creating the file
  FILE *fp;
  
  //creating the variables
  int choice;
  int i;
  char read = 'r';
  char readWrite = "r+";

  //creating the strings for the program
  char *dataBaseName = "login.txt";
  char *buffer[MAXSTRING];
  char userName[MAXSTRING];
  char password[MAXSTRING];

  //using GOTO for error prevention this is the menu interface 
  //for user input and returns the int as the var choice
  start : choice = StartUp();

  fp = dataBaseName;

  fopen(&dataBaseName, readWrite);

  //Interperating user generated actions that progress the program
  switch (choice)
  {
  case 1:
    SignUp(fp);
    break;

  case 2:
    Login(fp);
    break;

  case 0:
    printf("Goodbye!");
    return 0;

  //error checker for bad input back to the GOTO "start" menu
  default:
    printf("Incorrect input enter please enter a given input!\n");
    goto start;
    break;
  }

  return 0;
}

//Starting up the menu to the program
int StartUp()
{
  int answer;

  //prompts the user for information on the function
  printf("Welcome!\n");
  printf("If you would like to sign up press 1.\n");
  printf("If you would like to login press 2.\n");
  printf("If you would like to exit press 0.\n");
  scanf(" %i\n", &answer);

  return answer;
}

//starts the sign up sequence of the program
void SignUp(FILE *fp)
{
  userAccount user1;


  printf("Please Enter the Information in the Form!");
  
  FileClose(fp);
}
//starts the login sequence of the program
void Login(FILE *fp)
{  
  FileClose(fp);
}

//whenever called this closes the file for the program
void FileClose(FILE *fp)
{
  fclose(fp);
}

//a function that takes the cmdline inputs from the user and makes decisions based on arguments provided
//If no commands specified, program is to continue on as originally planned.
//If argument is specified then the program will jump to desired location based on user cmd input
char* cmdInput(int argc, char const *argv[])
{
  switch (argc)
  {
  case 0:
    puts("No input specified: Continuing on with normal operations");

    break;
  case 1:
    if (argv[1] == "signup")
    {
      puts("Sign up inputted!");
    }
    else if (argv[1] == "login")
    {
      puts("Login Inputted!");
    }else if (argv[1] == "help")
    {
      HelpFunct();
    }
  default:
    puts("Too many arguments inputted. Program is shutting down");
    return 0;
    break;
  }
}

void HelpFunct()
{
  puts("Helpful text.");
  return 0;
}