#include "data.h"

struct point create_point(double x, double y, double z)
{
   struct point p1;
   p1.x=x;
   p1.y=y;
   p1.z=z;
   return p1;
}

struct vector create_vector(double x, double y, double z)
{
   struct vector v1;
   v1.x=x;
   v1.y=y;
   v1.z=z;
   return v1;
}

struct ray create_ray(struct point p, struct vector dir)
{
   struct ray r1;
   r1.p=p;
   r1.dir=dir;
   return r1;
}

struct sphere create_sphere(struct point center, double radius, struct color color)
{
   struct sphere s1;
   s1.center=center;
   s1.radius=radius;
   s1.color=color;
   return s1;
}

struct color create_color(double r, double g, double b)
{
   struct color c1;
   c1.r=r;
   c1.g=g;
   c1.b=b;
   return c1;
}
