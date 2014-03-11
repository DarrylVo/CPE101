#include "string.h"
#include <stdio.h>
void str_rot_13(char const input[],char result[])
{
   int i;
   for(i=0;input[i];i++)
   {
     
      if( (input[i]>='a'&&input[i]<'n')||(input[i]>='A'&&input[i]<'N'))
      {
         result[i]=input[i]+13;

      }   
      else if((input[i]>='n'&&input[i]<='z')||(input[i]>='N'&&input[i]<='Z'))
      {
         result[i]=input[i]-13;
      }
      else
      {
         result[i]=input[i];
       
      }
      result[i+1]=0;
  }
}

void str_cat_101(char const input1[], char const input2[], char result[])
{
   int i;
   for(i=0;input1[i];i++)
   {
      result[i]=input1[i];     
   }
  // i++;
   int i2;
   for(i2=0;input2[i2];i2++)
   {
      result[i]=input2[i2];
      i++;
   }
   result[i]=0;

}
