#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_INPUT = 100;
const int BUF = 256;

void getInput(char uname[])
{
  printf("Enter user name :");
  scanf("%s", uname);
}

void getUserId(char uname[])
{
  char res[BUF];
  char command[MAX_INPUT] = "id -u ";
  strcat(command, uname);
  strcat(command, " 2>&1");

  FILE *file = popen(command, "r");
  if (file)
  {
    if (fgets(res, BUF, file))
    {
      if (res[0] != 'i')
      {
        int userId = atoi(res);
        printf("%d\n", userId);
      }
      else
      {
        printf("no such user found\n");
      }
    }

    pclose(file);
  }
}
int main()
{
  char uname[MAX_INPUT] = "";
  getInput(uname);
  getUserId(uname);
  return 0;
}