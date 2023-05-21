#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_INPUT = 100;

void getInput(char uname[])
{
  printf("Enter user name :");
  scanf("%s", uname);
}

void getUserId(char uname[])
{
  char command[MAX_INPUT] = "id -u ";
  strcat(command, uname);
  system(command);
}

int main()
{
  char uname[MAX_INPUT] = "";
  getInput(uname);
  getUserId(uname);
  return 0;
}