/* Darryl Vo
 * CPE 101 section 5
 * HW2
 */

#include "data.h"
#include "checkit.h"
#include "vector_math.h"
#include "collisions.h"

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

void test_sphere_intersection_point()
{
 
  //no intersection, t is an unreal number(s)
   struct point p1 = create_point(0.1,0.1,0.1);
   struct vector v1 = create_vector(1.2,0.2,0.2);
   struct ray r1 = create_ray(p1,v1); 
   struct point ps1 = create_point(10.3,10.3,10.3);
   struct sphere s1 = create_sphere(ps1,3.1);
   struct maybe_point mp1 = sphere_intersection_point(r1,s1);
   checkit_boolean(mp1.isPoint,0);
 
   //both t's positive
   struct point p2 = create_point(0.1,0.1,0.1);
   struct vector v2 = create_vector(1.2,1.2,1.2);
   struct ray r2 = create_ray(p2,v2);
   struct point ps2 = create_point(5.3,5.3,5.3);
   struct sphere s2 = create_sphere(ps2,2.4);
   struct maybe_point mp2 = sphere_intersection_point(r2,s2);
   checkit_boolean(mp2.isPoint,1); 
   checkit_double(mp2.p.x,3.914359);

   //one t positive one t negative
   struct point p3 = create_point(1.1,2.2,3.3);
   struct vector v3 = create_vector(1.2,1.1,1.1);
   struct ray r3 = create_ray(p3,v3);
   struct point ps3 = create_point(2.3,2.4,2.5);
   struct sphere s3 = create_sphere(ps3,5.6);
   struct maybe_point mp3 = sphere_intersection_point(r3,s3);
   checkit_boolean(mp3.isPoint,1);
   checkit_double(mp3.p.x,4.654131);
 
   //both t's are negative
   struct point p4 = create_point(-.1,-.1,-.1);
   struct vector v4 = create_vector(-1.2,0.2,0.2);
   struct ray r4 = create_ray(p4,v4);
   struct point ps4 = create_point(5.2,0.3,0.3);
   struct sphere s4 = create_sphere(ps4,4.8);
   struct maybe_point mp4 = sphere_intersection_point(r4,s4);
   checkit_boolean(mp4.isPoint,0);
}

void test_find_intersection_points()
{
   
   struct point p5 = create_point(1.1,2.2,3.3);
   struct vector v5 = create_vector(1.2,1.1,1.1);
   struct ray r5 = create_ray(p5,v5);
  
   struct point ps5 = create_point(-3.3,-4.4,-3.5);
   struct sphere s5 = create_sphere(ps5,1.1);
  
   struct point ps6 = create_point(3.3,4.3,3.2);
   struct sphere s6 = create_sphere(ps6,4.8);
   
   struct sphere spheres[2];
   spheres[0] = s5;
   spheres[1] = s6;

   struct sphere hit_spheres[2];
   struct point intersection_points[2];
   
   int a = find_intersection_points(spheres,2,r5,hit_spheres,intersection_points);
   
   checkit_int(a,1);
   checkit_double(hit_spheres[0].center.x,3.3);
   checkit_double(hit_spheres[0].center.y,4.3);
   checkit_double(hit_spheres[0].center.z,3.2);
   checkit_double(hit_spheres[0].radius,4.8);
   checkit_double(intersection_points[0].x,5.325828);
   checkit_double(intersection_points[0].y,6.073675);
   checkit_double(intersection_points[0].z,7.173675);
}

void test_sphere_normal_at_point()
{
   struct point ps7 = create_point(0.1,0.1,0.1);
   struct sphere s7 = create_sphere(ps7,5.2);

   struct point tp1 = create_point(2.2,1.3,4.703259715);

   struct vector normal = sphere_normal_at_point(s7,tp1);
   checkit_double(normal.x,0.403846154);
   checkit_double(normal.y,0.230769231);
   checkit_double(normal.z,0.885242253);
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
   test_sphere_intersection_point();
   test_find_intersection_points();
   test_sphere_normal_at_point();
}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}
