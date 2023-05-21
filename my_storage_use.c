#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int BUF = 256;

int getCapacity(char line[])
{
   int i = 0;
   int res = 0;
   while (line[i] != '%')
   {
      i++;
   }
   i--;
   int curr = 1;
   while (line[i] != ' ')
   {
      int intLine = line[i] - '0';
      res += curr * intLine;
      curr *= 10;
      i--;
   }
   return res;
}

void avgUse()
{
   FILE *output = fopen("a.txt", "r");
   char * line = NULL;
   size_t len = 0;
   int curr = 0;
   int currSum = 0;
   if (output)
   {
      while ((getline(&line, &len, output)) != -1)
      {
         if(curr > 0){
            currSum += getCapacity(line);
         }
         curr += 1;
      }
      fclose(output);
   }
   double res = currSum / curr;
   printf("%.2ft", res);
}

void getStorageData()
{
   char line[BUF];
   FILE *file = popen("df -h", "r");
   FILE *output = fopen("a.txt", "w");
   if (file && output)
   {
      while (fgets(line, BUF, file))
      {
         fprintf(output, "%s", line);
      }
      fclose(output);
      pclose(file);
   }
}

int main()
{
   getStorageData();
   avgUse();
}