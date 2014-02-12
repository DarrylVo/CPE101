/* Darryl Vo
 * Lab 3
 * CPE 101 section 5
 */

#include "conditional.h"

double min(double a, double b)
{
   if(a<=b)
   {
      return a;
   }
   else
   {
      return b;
   }
}

double max(double a, double b)
{
   if(a>=b)
   {
      return a;
   }
   else
   {
      return b;
   }
}

double max_of_three(double a, double b, double c)
{
   if(a>=b && a>=c)
   {
      return a;
   }
   else if(b>=a && b>=c)
   {
      return b;
   }
   else if(c>=a && c>=b)
   {
      return c;
   }
   return 0;
}

int rental_late_fee(int a)
{
   if(a<=0)
   {
      return 0;
   }
   else if(a<=9)
   {
      return 5;
   }
   else if(a<=15)
   {
      return 7;
   }
   else if(a<=24)
   {
      return 19;
   }
   else if(a>24)
   {
      return 100;
   }
   return 0;
}
