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
#include "UserAccount.h" 

int StartUp ();
void SignUp(FILE *fp);
void Login(FILE *fp);
void FileClose(FILE *fp);
void WriteToFile(UserAccount user);

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
  int i = 0;
  char ch;

  printf("Please Enter the Information in the Form!");

  
  

  UserAccount user;

  user.id == i;

  printf("Enter the UserName: \n");
  scanf(" %s", user.username);

  printf("Enter the Password: \n");
  scanf(" %s", user.password);

  printf("Enter the users First Name: \n");
  scanf(" %s", user.firstName);

  printf("Enter the users Last Name: \n");
  scanf(" %s", user.lastName);

  printf("Would you like to save the account");
  printf("y/n \n");
  scanf(" %c", &ch);

  if (ch == 'y')
  {
    
  }
  else if (ch == 'n')
  {
    return 0;
  }
  else
  {
    printf("Bad Input detected");
  }
  
  
  FileClose(fp);
}

//starts the login sequence of the program
void Login(FILE *fp)
{  
  int lines;
  char ch;
  char userArray[4][MAXSTRING];

  if (fp == NULL)
    {
      puts("File Failed to Open: File may not exist or was inputted incorrectly!");
      puts("Please Try Again!");

      return 0;
    }
    else
    {      
      while (ch != EOF)
      {
        if (ch == '\n')
        {
          lines++;
        }
        ch = fgetc(fp);
      }
    }

    if(lines <= 4)
    {
      rewind(fp);

      for (int i = 0; i < lines; i++)
      {
        for (int j = 0; j < MAXSTRING; j++)
        {
          while ((ch = fgetchar()) != EOF)
          {
            if (ch != '\n')
            {
              userArray[i][j] = ch;
            }
            else if (ch =='\n')
            {
              break;
            }
          }            
        } 
      }
    }

    UserAccount user;
    user.id = 0;
    user.username = userArray[0];
    user.password = userArray[1];
    user.firstName = userArray[2];
    user.lastName = userArray[3];


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