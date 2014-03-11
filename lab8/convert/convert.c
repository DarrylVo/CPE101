#include "convert.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
double convert_double(char const input[], double default_value)
{
   double a;
   if(sscanf(input,"%lf",&a)==1)
   {
      return a;
   }
   else
   {
      return default_value;
   }


}
