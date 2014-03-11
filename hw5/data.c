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

struct sphere create_sphere(struct point center, double radius, struct color color,struct finish finish)
{
   struct sphere s1;
   s1.center=center;
   s1.radius=radius;
   s1.color=color;
   s1.finish.ambient=finish.ambient;
   s1.finish.diffuse=finish.diffuse;
   s1.finish.specular=finish.specular;
   s1.finish.roughness=finish.roughness;
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

struct finish create_finish(double ambient, double diffuse, double specular, double roughness)
{
   struct finish f;
   f.ambient=ambient;
   f.diffuse=diffuse;
   f.specular=specular;
   f.roughness=roughness;
   return f;
}

struct light create_light(struct point p, struct color color)
{
   struct light l1;
   l1.p=p;
   l1.color = color;
   return l1;
}
