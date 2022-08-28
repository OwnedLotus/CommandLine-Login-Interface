/*
  This program is created as a basic login interface build to
  utilize a file database and scan the database to check if the 
  user exists.

  If the user does not exist, there is a user creation part of 
  the program.
*/

#include <stdio.h>

#include "UserAccount.h"

int StartUp ();
void SignUp(FILE *fp, UserAccount *user);
void Login(FILE *fp, UserAccount *user);
void FileClose(FILE *fp);
void WriteToFile(UserAccount user);

char* cmdInput(int argc, char const *argv[]);

void HelpFunct();

int main(int argc, char const *argv[])
{ 
  FILE *fp;
  UserAccount *user = malloc(sizeof(UserAccount) + 1);
  
  int choice;
  int i;

  char *dataBaseName = "login.txt";
  char buffer[MAXSTRING];
  char userName[MAXSTRING];
  char password[MAXSTRING];

  start:
  choice = StartUp();

  fopen(&fp, "r+");

  switch (choice)
  {
    case 1:
      SignUp(fp, user);
      break;

    case 2:
      Login(fp, user);
      break;

    case 0:
      printf("Goodbye!");
      return 0;

    default:
      printf("Incorrect input enter please enter a given input!\n");
      goto start;
      break;

  }

  free(user->username);
  free(user->password);
  free(user->firstName);
  free(user->lastName);
  free(user);

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

void SignUp(FILE *fp, UserAccount *user)
{
  int i = 0; //implement counter for id
  char ch;

  printf("Please Enter the Information in the Form!");

  user->id = i + 1;

  printf("Enter the UserName: \n");
  fgets(user->username = malloc(MAXSTRING + 1), MAXSTRING, stdin);

  printf("Enter the Password: \n");
  fgets(user->password = malloc(MAXSTRING + 1), MAXSTRING, stdin);

  printf("Enter the users First Name: \n");
  fgets(user->firstName = malloc(MAXSTRING + 1), MAXSTRING, stdin);

  printf("Enter the users Last Name: \n");
  fgets(user->lastName = malloc(MAXSTRING + 1), MAXSTRING, stdin);

  SAVE_ACCOUNT: 
  printf("Would you like to save the account: ");
  printf("y / n \n");
  ch = fgetc(stdin);

  if (ch == 'y')
  {
    //TODO!

    puts("User Saved!");
  }
  else if (ch == 'n')
  {
    //TODO!

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

//redo method
void Login(FILE *fp, UserAccount *user)
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

    puts("Please enter your Username and Password!");
    printf("Username: ");
    userNameEnter = fgets(10, MAXSTRING, stdin);
    printf("\nPassword: ");
    passwordEnter = fgets(10, MAXSTRING, stdin);

    if (userNameEnter == user->username && passwordEnter == user->password)
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