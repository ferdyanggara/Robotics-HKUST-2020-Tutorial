#include <stdint.h>
#include <stdio.h>
#include <string.h>

// helper function
char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', 'A'};
int numbers[] = {1, 5, 10, 50, 100, 500, 1000};

int getInd(char c)
{
       int i = 0;
       while (i < strlen(symbols))
       {
              if (symbols[i] == c)
              {
                     return i;
              }
              i++;
       }
}

int roman_to_int(const char s[], int length)
{
       // Please complete the function body
       int result = 0;
       int i = 1;
       while (i < length)
       {
              int index1 = getInd(s[i - 1]);
              int index2 = getInd(s[i]);

              if (index1 >= index2)
              {
                     result += numbers[index1];
              }
              else
              {
                     result -= numbers[index1];
              }
              i++;
       }

       result += numbers[getInd(s[--length])];
       return result;
}

int main()
{
       char roman_num[] = "III";
       char roman_num_2[] = "CXXIII";
       char roman_num_3[] = "MMMCDLIX";

       printf("roman_to_int(%s) = %d\n", roman_num,
              roman_to_int(roman_num, strlen(roman_num)));
       printf("roman_to_int(%s) = %d\n", roman_num_2,
              roman_to_int(roman_num_2, strlen(roman_num_2)));
       printf("roman_to_int(%s) = %d\n", roman_num_3,
              roman_to_int(roman_num_3, strlen(roman_num_3)));
}