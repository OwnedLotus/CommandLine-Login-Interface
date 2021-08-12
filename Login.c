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
  FILE *fp;
  
  int choice;
  int i;
  char read = "r";
  char readWrite = "r+";

  char *dataBaseName = "login.txt";
  char *buffer[MAXSTRING];
  char userName[MAXSTRING];
  char password[MAXSTRING];

  start:
  choice = StartUp();

  fp = dataBaseName;

  fopen(&dataBaseName, readWrite);

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
  int i = 0;
  char ch;

  printf("Please Enter the Information in the Form!");

  UserAccount user;

  user.id == i;

  printf("Enter the UserName: \n");
  user.username = fgetc(stdin);

  printf("Enter the Password: \n");
  user.password = fgetc(stdin);

  printf("Enter the users First Name: \n");
  user.password = fgetc(stdin);

  printf("Enter the users Last Name: \n");
  user.password = fgetc(stdin);

  SAVE_ACCOUNT: 
  printf("Would you like to save the account: ");
  printf("y/n \n");
  ch = fgetc(stdin);

  if (ch == 'y')
  {
    puts("User Saved!");
  }
  else if (ch == 'n')
  {
    puts("Goodbye!");
    return 0;
  }
  else
  {
    printf("Bad Input detected. Please Try again!");
    goto SAVE_ACCOUNT;
  }
  
  FileClose(fp);
}

void Login(FILE *fp)
{  
  int lines;
  char ch;
  char userArray[4][MAXSTRING];

  char* userNameEnter, passwordEnter;

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

    puts("Please enter your Username and Password!");
    printf("Username: ");
    userNameEnter = fgets(10, MAXSTRING, stdin);
    printf("\nPassword: ");
    passwordEnter = fgets(10, MAXSTRING, stdin);

    if (userNameEnter == user.username && passwordEnter == user.password)
    {
      puts("Welcome back!"); // Replace this with application call
    }
    else
    {
      puts("Username or password was not accepted! Please try again!");
    }
    


  FileClose(fp);
}

void FileClose(FILE *fp)
{
  fclose(fp);
}

void HelpFunct()
{
  puts("Helpful text.");
  return 0;
}