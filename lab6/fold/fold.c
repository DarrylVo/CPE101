#include "fold.h"
#include "point.h"
#include <math.h>
double sum(double const input[], int size)
{
   int i;
   double summative=0;
   for(i=0;i<size;i++)
   {
      summative = summative+input[i];
   }
   return summative;
}  

int index_of_smallest(double const input[], int size)
{
   int i;
   int index=0;
   if(size<=0)
   {
      return -1;
   }
   for(i=0;i<size;i++)
   {
      if(input[i]<input[index])
      {
         index=i;
      }
      
   }

   return index;
}

int nearest_origin(struct point const input[], int size)
{
   int i;
   int index;
   for(i=0,index=0;i<size;i++)
   {
      double a = sqrt( input[i].x*input[i].x + input[i].y*input[i].y )
      double b = sqrt( 
      if(




} 
