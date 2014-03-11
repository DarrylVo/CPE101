#include "poly.h"
#include <stdio.h>
void poly_add2(double poly1[],int degree1, double poly2[], int degree2, double result[])
{
  
   if(degree1>degree2)
   { 
      int i;
      for(i=degree1;i>degree2;i--)
      {
         result[i]=poly1[i];
      }
      for(i=degree2;i>=0;i--)
      {
         result[i]=poly1[i]+poly2[i];
      }
   }
   
   else
   {
      int i;
      for(i=degree2;i>degree1;i--)
      {
         result[i]=poly2[i];
      }
      for(i=degree1;i>=0;i--)
      {
         result[i]=poly1[i]+poly2[i];
      }

   }

}

void poly_mult2(double poly1[],int degree1, double poly2[],int degree2,double result[])
{
   int c;
   for(c=degree1+degree2;c>=0;c--)
   {
      result[c]=0;
   }
   int i;
   int i2;   
   for(i=degree1;i>=0;i--)
   {
      for(i2=degree2;i2>=0;i2--)
      {           
         result[i+i2]+=poly1[i]*poly2[i2];     
      }
   }
}
