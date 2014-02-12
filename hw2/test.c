/* Darryl Vo
 * CPE 101 section 5
 * HW2
 */

#include "data.h"
#include "checkit.h"
#include "vector_math.h"

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

void test_scale_vector()
{
   struct vector v1 = create_vector(1.1,2.2,3.3);
   struct vector nv1 = scale_vector(v1,2.2);
   checkit_double(nv1.x,2.42);
   checkit_double(nv1.y,4.84);
   checkit_double(nv1.z,7.26);
 
   struct vector v2 = create_vector(4.4,5.5,6.6);
   struct vector nv2 = scale_vector(v2,3.3);
   checkit_double(nv2.x,14.52);
   checkit_double(nv2.y,18.15);
   checkit_double(nv2.z,21.78);
}

void test_dot_vector()
{
   struct vector v1 = create_vector(1.1,2.2,3.3);
   struct vector v2 = create_vector(4.4,5.5,6.6);
   checkit_double(dot_vector(v1,v2),38.72);

   struct vector v3 = create_vector(1.2,2.3,3.4);
   struct vector v4 = create_vector(4.5,5.6,6.7);
   checkit_double(dot_vector(v3,v4),41.06);
}

void test_length_vector()
{
   struct vector v1 = create_vector(1.1,2.2,3.3);
   checkit_double(length_vector(v1),4.1158231254);

   struct vector v2 = create_vector(4.4,5.5,6.6);
   checkit_double(length_vector(v2),9.652460);
}

void test_normalize_vector()
{
   struct vector v1 = create_vector(1.1,2.2,3.3);
   struct vector new_vector = normalize_vector(v1);
   checkit_double(new_vector.x,0.267261241915);
   checkit_double(new_vector.y,0.5345224838315157);
   checkit_double(new_vector.z,0.8017857878434);

   struct vector v2 = create_vector(1.3,2.3,3.1);
   struct vector new_vector2 = normalize_vector(v2);
   checkit_double(new_vector2.x,0.3191686005);
   checkit_double(new_vector2.y,0.56468286171);
   checkit_double(new_vector2.z,0.7610943550179);
}

void test_point_difference()
{
   struct point p1 = create_point(1.1,2.2,3.3);
   struct point p2 = create_point(4.4,5.5,6.6);
   struct vector v = difference_point(p1,p2);
   checkit_double(v.x,-3.3);
   checkit_double(v.y,-3.3);
   checkit_double(v.z,-3.3);

   struct point p3 = create_point(1.4,2.1,2.9);
   struct point p4 = create_point(4.2,1.2,3.7);
   struct vector v2 = difference_point(p3,p4);
   checkit_double(v2.x,-2.8);
   checkit_double(v2.y,0.9);
   checkit_double(v2.z,-0.8);
}


void test_vector_difference()
{
   struct vector v1 = create_vector(1.1,2.2,3.3);
   struct vector v2 = create_vector(4.4,5.5,6.6);
   struct vector v = difference_vector(v1,v2);
   checkit_double(v.x,-3.3);
   checkit_double(v.y,-3.3);
   checkit_double(v.z,-3.3);

   struct vector v3 = create_vector(1.4,2.1,2.9);
   struct vector v4 = create_vector(4.2,1.2,3.7);
   struct vector v5 = difference_vector(v3,v4);
   checkit_double(v5.x,-2.8);
   checkit_double(v5.y,0.9);
   checkit_double(v5.z,-0.8);
}

void test_translate_point()
{
   struct point p1 = create_point(3.2,1.3,2.5);
   struct vector v1 = create_vector(4.2,3.5,1.2);
   struct point np1 = translate_point(p1,v1);
   checkit_double(np1.x,7.4);
   checkit_double(np1.y,4.8);
   checkit_double(np1.z,3.7);

   struct point p2 = create_point(-3.2,3.1,-2.3);
   struct vector v2 = create_vector(4.5,-6.3,2.3);
   struct point np2 = translate_point(p2,v2);
   checkit_double(np2.x,1.3);
   checkit_double(np2.y,-3.2);
   checkit_double(np2.z,0);
}
   
void test_vector_from_to()
{
   struct point p1 = create_point(3.2,-2.2,1.3);
   struct point p2 = create_point(1.1,3.4,-2.2);
   struct vector nv1 = vector_from_to(p1,p2);
   checkit_double(nv1.x,-2.1);
   checkit_double(nv1.y,5.6);
   checkit_double(nv1.z,-3.5);

   struct point p3 = create_point(1.2,5.2,-2.2);
   struct point p4 = create_point(-2.1,3.1,5.2);
   struct vector nv2 = vector_from_to(p3,p4);
   checkit_double(nv2.x,-3.3);
   checkit_double(nv2.y,-2.1);
   checkit_double(nv2.z,7.4);
}

void test_cases()
{
   test_point();
   test_vector();
   test_ray();
   test_sphere();
   test_scale_vector();
   test_dot_vector();
   test_length_vector();
   test_normalize_vector();
   test_point_difference();
   test_vector_difference();
   test_translate_point();
   test_vector_from_to();
}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}
