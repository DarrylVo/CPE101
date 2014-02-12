/* Darryl Vo
 * Lab Quiz 1
 */

#include "cone.h"

struct cone create_cone(double radius, double height)
{
   struct cone c;
   c.radius=radius;
   c.height=height;
   return c;
}

double cone_volume(struct cone c)
{
   double r = c.radius*c.radius;
   double h = c.height;
   double v = 3.141592*r*h/3;
   return v;
}

int has_greater_volume_than(struct cone c, double check)
{
   double v = cone_volume(c);
   if(v>check)
   {
      return 1;
   }
   else
   {
      return 0;
   }

}

struct cone max_of_three(struct cone c1, struct cone c2, struct cone c3)
{
   double a = cone_volume(c1);
   double b = cone_volume(c2);
   double c = cone_volume(c3);

   if(a>b && a>c)
   {
      return c1;
   }
   else if(b>a && b>c)
   {
      return c2;
   }
   else
   {
      return c3;
   }
}


