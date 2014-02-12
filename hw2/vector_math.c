/* Assignment: HW2
 * CPE 101 Section 5
 * Darryl Vo
 */

#include "data.h"
#include "vector_math.h"
#include <math.h>
struct vector scale_vector(struct vector v, double scalar)
{
   struct vector nv;
   nv.x=v.x*scalar;
   nv.y=v.y*scalar;
   nv.z=v.z*scalar;
   return nv;
}

double dot_vector(struct vector v1, struct vector v2)
{
   double a = v1.x*v2.x;
   double b = v1.y*v2.y;
   double c = v1.z*v2.z;
   return a+b+c;
}

double length_vector(struct vector v)
{
   double a = v.x*v.x;
   double b = v.y*v.y;
   double c = v.z*v.z;
   return sqrt(a+b+c);
}

struct vector normalize_vector(struct vector v)
{
   double a = length_vector(v);
   struct vector new_vector;
   new_vector.x=v.x/a;
   new_vector.y=v.y/a;
   new_vector.z=v.z/a;
   return new_vector;
}

struct vector difference_point(struct point p1, struct point p2)
{
   struct vector v;
   v.x=p1.x-p2.x;
   v.y=p1.y-p2.y;
   v.z=p1.z-p2.z;
   return v;
}

struct vector difference_vector(struct vector v1, struct vector v2)
{
   struct vector v;
   v.x=v1.x-v2.x;
   v.y=v1.y-v2.y;
   v.z=v1.z-v2.z;
   return v;
}

struct point translate_point(struct point p, struct vector v)
{
   struct point p1;
   p1.x=p.x+v.x;
   p1.y=p.y+v.y;
   p1.z=p.z+v.z;
   return p1;
}
   
struct vector vector_from_to(struct point from, struct point to)
{
   struct vector v;
   v.x = to.x-from.x;
   v.y = to.y-from.y;
   v.z = to.z-from.z;
   return v;
}
