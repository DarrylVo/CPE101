#ifndef DATA_H
#define DATA_H

struct point
{
   double x;
   double y;
   double z;
};

struct point create_point(double x, double y, double z);

struct vector
{
   double x;
   double y;
   double z;
};

struct vector create_vector(double x, double y, double z);

struct ray
{
   struct point p;
   struct vector dir;
};

struct ray create_ray (struct point p, struct vector dir);

struct color
{
   double r;
   double g;
   double b;
};

struct color create_color(double r, double g, double b);

struct sphere
{
   struct point center;
   double radius;
   struct color color;
};

struct sphere create_sphere(struct point center, double radius,struct color color);


#endif
