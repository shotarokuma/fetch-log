#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int BUF = 256;

// read data and convert int type data
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

//caluclation of average
void avgUse()
{
   FILE *output = fopen("a.txt", "r");
   char *line = NULL;
   size_t len = 0;
   int curr = 0;
   int currSum = 0;
   if (output)
   {
      while ((getline(&line, &len, output)) != -1)
      {
         if (curr > 0)
         {
            currSum += getCapacity(line);
         }
         curr += 1;
      }
      fclose(output);
   }
   double res = currSum / (double)curr;
   printf("%.2f\n", res);
}

// modify data for output
void extractData(char line[])
{
   char fixedData[BUF]  = { '\0' };
   char filesystem[BUF]  = { '\0' };
   char size[BUF]  = { '\0' };
   char used[BUF]  = { '\0' };
   char avail[BUF]  = { '\0' };
   char use[BUF]  = { '\0' };
   char mounted_on[BUF]  = { '\0' };
   if(sscanf(line, "%s %s %s %s %s %*s %*s %*s %s", filesystem, size, used, avail, use, mounted_on) == 6) 
   {
      strcat(fixedData, filesystem);
      strcat(fixedData, " ");
      strcat(fixedData, size);
      strcat(fixedData, " ");
      strcat(fixedData, used);
      strcat(fixedData, " ");
      strcat(fixedData, avail);
      strcat(fixedData, " ");
      strcat(fixedData, use);
      strcat(fixedData, " ");
      strcat(fixedData, mounted_on);
      strcpy(line, fixedData);
      strcat(line, "\n");
   }
}

// fetch data of storage and write data on text file 
void getStorageData()
{
   char line[BUF];
   FILE *file = popen("df -h", "r");
   FILE *output = fopen("a.txt", "w");
   if (file && output)
   {
      while (fgets(line, BUF, file))
      {
         extractData(line);
         fprintf(output, "%s", line);
      }
      fclose(output);
      pclose(file);
   }
}

// main function
int main()
{
   getStorageData();
   avgUse();
}