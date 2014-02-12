#include "map.h"
#include <math.h>
void square_all(double const input[], int size, double result[])
{
   int i;
   for(i=0;i<size;i++)
   {
      result[i]=input[i]*input[i];
   }
}

void add_n_all(double n, double const input[], int size, double result[])
{
   int i;
   for(i=0;i<size;i++)
   {
      result[i]=n+input[i];
   }
}

void distance_all(struct point const input[], int size, double result[])
{
   int i;
   for(i=0;i<size;i++)
   {   
      result[i]=sqrt( (input[i].x*input[i].x)+(input[i].y*input[i].y) ) ; 
   }
         

}
