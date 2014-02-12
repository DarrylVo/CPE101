#include "data.h"
#include "checkit.h"
void test_point(void)
{
   struct point p1 = create_point(1.1,2.2,3.3);
   checkit_double(p1.x,1.1);
   checkit_double(p1.y,2.2);
   checkit_double(p1.z,3.3);

   struct point p2 = create_point(3.3,4.4,5.5);
   checkit_double(p2.x,3.3);
   checkit_double(p2.y,4.4);
   checkit_double(p2.z,5.5);
}

void test_vector(void)
{
   struct vector v1 = create_vector(1.1,2.2,3.3);
   checkit_double(v1.x,1.1);
   checkit_double(v1.y,2.2);
   checkit_double(v1.z,3.3);

   struct vector v2 = create_vector(4.4,5.5,6.6);
   checkit_double(v2.x,4.4);
   checkit_double(v2.y,5.5);
   checkit_double(v2.z,6.6);
}

void test_ray(void)
{
   struct point p = create_point(1.1,2.2,3.3);
   struct vector dir = create_vector(4.4,5.5,6.6);
   struct ray r1 = create_ray(p,dir);
   checkit_double(r1.p.x,1.1);
   checkit_double(r1.p.y,2.2);
   checkit_double(r1.p.z,3.3);
   checkit_double(r1.dir.x,4.4);
   checkit_double(r1.dir.y,5.5);
   checkit_double(r1.dir.z,6.6);
}

void test_sphere()
{
   struct point center = create_point(1.1,2.2,3.3);
   struct sphere c1 = create_sphere(center,4.4);
   checkit_double(c1.center.x,1.1);
   checkit_double(c1.center.y,2.2);
   checkit_double(c1.center.z,3.3);
   checkit_double(c1.radius,4.4);
}

void test_cases()
{
   test_point();
   test_vector();
   test_ray();
   test_sphere();

}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}
