//defines the max length a string can pass in C99
#ifndef MAXSTRING
#define MAXSTRING 4095 
#endif

//creates a structure of userAccount to 
//define what is included for login information
typedef struct UserAccount
{
  int id;
  char* username;
  char* password;
  char* firstName;
  char* lastName;

} UserAccount;


int i = 5;

int *ptr = &i;

0x