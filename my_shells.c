#include <stdio.h>
#include <string.h>

const char SHELL_PATH[] = "/etc/shells";
const int BUF = 256;

void addShells(char line[], char res[BUF][BUF], int* curr)
{
   for (int i = 0; i < *curr; i++)
   {
      if (strcmp(line, res[i]) == 0)
      {
         return;
      }
   }
   strcpy(res[*curr], line);
   (*curr)++;
}

void getShell(char line[])
{
   for (int i = strlen(line) - 1; i > 0; i--)
   {
      if (line[i] == '/')
      {
         char res[BUF];
         for (int j = i + 1; j < strlen(line); j++)
         {
            res[j - (i + 1)] = line[j];
         }
         res[strlen(line) - (i + 1)] = '\0';
         strcpy(line, res);
         return;
      }
   }
   line[0] = '\0';
}

void readShells()
{
   FILE* shells = fopen(SHELL_PATH, "r");
   char line[BUF];
   char res[BUF][BUF];
   int curr = 0;
   if (shells)
   {
      while (fgets(line, sizeof(line), shells))
      {
         getShell(line);
         addShells(line, res, &curr);
      }
   }
   fclose(shells);
   for (int i = 0; i < curr; i++)
   {
      printf("%s", res[i]);
   }
}

int main()
{
   readShells();
   return 0;
}
