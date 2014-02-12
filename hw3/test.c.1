#include "checkit.h"
#include "data.h"
#include "vector_math.h"
#include "collisions.h"

void test_sphere_intersection1()
{
   struct point sp = create_point(0.0, 2.0, 0.0);
   struct sphere s = create_sphere(sp, 1.0);

   struct point rp = create_point(0.0, 0.0, 0.0);
   struct vector dir = create_vector(0.0, 1.0, 0.0);
   struct ray r = create_ray(rp, dir);

   struct maybe_point mp = sphere_intersection_point(r, s);

   printf(" Intersection 1: Along y-axis.\n");
   checkit_boolean(mp.isPoint, 1);
   checkit_double(mp.p.x, 0.0);
   checkit_double(mp.p.y, 1.0);
   checkit_double(mp.p.z, 0.0);
}

void test_sphere_intersection2()
{
   struct point sp = create_point(0.0, 0.0, 0.0);
   struct sphere s = create_sphere(sp, 1.0);

   struct point rp = create_point(0.0, 0.0, 0.0);
   struct vector dir = create_vector(1.0, 0.0, 0.0);
   struct ray r = create_ray(rp, dir);

   struct maybe_point mp = sphere_intersection_point(r, s);

   printf(" Intersection 2: From within sphere at origin.\n");
   checkit_boolean(mp.isPoint, 1);
   checkit_double(mp.p.x, 1.0);
   checkit_double(mp.p.y, 0.0);
   checkit_double(mp.p.z, 0.0);
}

void test_sphere_intersection3()
{
   struct point sp = create_point(1.0, 1.0, 0.0);
   struct sphere s = create_sphere(sp, 1.0);

   struct point rp = create_point(0.0, 0.0, 0.0);
   struct vector dir = create_vector(1.0, 0.0, 0.0);
   struct ray r = create_ray(rp, dir);

   struct maybe_point mp = sphere_intersection_point(r, s);

   printf(" Intersection 3: Single intersection point at <1,0,0>.\n");
   printf("\tWatch for precision issues.\n");
   checkit_boolean(mp.isPoint, 1);
   checkit_double(mp.p.x, 1.0);
   checkit_double(mp.p.y, 0.0);
   checkit_double(mp.p.z, 0.0);
}

void test_sphere_intersection4()
{
   struct point sp = create_point(2.0, 2.0, 0.0);
   struct sphere s = create_sphere(sp, 1.0);

   struct point rp = create_point(0.0, 0.0, 0.0);
   struct vector dir = create_vector(1.0, 0.0, 0.0);
   struct ray r = create_ray(rp, dir);

   struct maybe_point mp = sphere_intersection_point(r, s);

   printf(" Intersection 4: Does not intersect.\n");
   checkit_boolean(mp.isPoint, 0);
}

void test_sphere_intersection5()
{
   struct point sp = create_point(0.0, 0.0, 0.0);
   struct sphere s = create_sphere(sp, 4.0);

   struct point rp = create_point(0.0, 2.0, -4.0);
   struct vector dir = create_vector(0.658281, -0.557005, 0.506370);
   struct ray r = create_ray(rp, dir);

   struct maybe_point mp = sphere_intersection_point(r, s);

   printf(" Intersection 5: Sphere at origin.  Ray through sphere.\n");
   checkit_boolean(mp.isPoint, 1);
   checkit_double(mp.p.x, 0.47362624786864);
   checkit_double(mp.p.y, 1.599239329218808);
   checkit_double(mp.p.z, -3.635672117471643);
}

void test_sphere_intersection6()
{
   struct point sp = create_point(0.0, -2.0, 0.0);
   struct sphere s = create_sphere(sp, 1.0);

   struct point rp = create_point(0.0, 0.0, 0.0);
   struct vector dir = create_vector(0.0, 1.0, 0.0);
   struct ray r = create_ray(rp, dir);

   struct maybe_point mp = sphere_intersection_point(r, s);

   printf(" Intersection 6: Sphere \"behind\" ray.  No intersection.\n");
   checkit_boolean(mp.isPoint, 0);
}

void test_sphere_intersection()
{
   printf("=== SPHERE INTERSECTION POINT TESTS === \n");
   test_sphere_intersection1();
   printf("\n");
   test_sphere_intersection2();
   printf("\n");
   test_sphere_intersection3();
   printf("\n");
   test_sphere_intersection4();
   printf("\n");
   test_sphere_intersection5();
   printf("\n");
   test_sphere_intersection6();
   printf("\n");
}

void test_find_intersection_points1()
{
   int num_spheres = 4;
   struct sphere spheres[4];
   struct sphere hit_spheres[4];
   struct point intersection_points[4];
   struct ray r = create_ray(create_point(0.0, 0.0, 0.0),
      create_vector(0.0, 1.0, 0.0));
   int hits = 0;

   spheres[0] = create_sphere(create_point(0.0, 2.0, 0.0), 1.0);
   spheres[1] = create_sphere(create_point(0.0, 5.0, 0.0), 1.0);
   spheres[2] = create_sphere(create_point(0.0, -4.0, 0.0), 1.0);
   spheres[3] = create_sphere(create_point(0.0, 8.0, 0.0), 1.0);

   hits = find_intersection_points(spheres, num_spheres, r,
      hit_spheres, intersection_points);

   printf(" Find Intersection Points 1: Hits three (of four) spheres.\n");
   printf("\tThe order should match if directions were carefully followed.\n");
   checkit_int(hits, 3);
   checkit_double(hit_spheres[0].center.x, spheres[0].center.x);
   checkit_double(hit_spheres[0].center.y, spheres[0].center.y);
   checkit_double(hit_spheres[0].center.z, spheres[0].center.z);
   checkit_double(intersection_points[0].x, 0.0);
   checkit_double(intersection_points[0].y, 1.0);
   checkit_double(intersection_points[0].z, 0.0);

   checkit_double(hit_spheres[1].center.x, spheres[1].center.x);
   checkit_double(hit_spheres[1].center.y, spheres[1].center.y);
   checkit_double(hit_spheres[1].center.z, spheres[1].center.z);
   checkit_double(intersection_points[1].x, 0.0);
   checkit_double(intersection_points[1].y, 4.0);
   checkit_double(intersection_points[1].z, 0.0);

   checkit_double(hit_spheres[2].center.x, spheres[3].center.x);
   checkit_double(hit_spheres[2].center.y, spheres[3].center.y);
   checkit_double(hit_spheres[2].center.z, spheres[3].center.z);
   checkit_double(intersection_points[2].x, 0.0);
   checkit_double(intersection_points[2].y, 7.0);
   checkit_double(intersection_points[2].z, 0.0);
}

void test_find_intersection_points2()
{
   int num_spheres = 4;
   struct sphere spheres[4];
   struct sphere hit_spheres[4];
   struct point intersection_points[4];
   struct ray r = create_ray(create_point(0.0, 0.0, 0.0),
      create_vector(0.0, 0.0, 1.0));
   int hits = 0;

   spheres[0] = create_sphere(create_point(0.0, 2.0, 0.0), 1.0);
   spheres[1] = create_sphere(create_point(0.0, 5.0, 0.0), 1.0);
   spheres[2] = create_sphere(create_point(0.0, -4.0, 0.0), 1.0);
   spheres[3] = create_sphere(create_point(0.0, 8.0, 0.0), 1.0);

   hits = find_intersection_points(spheres, num_spheres, r,
      hit_spheres, intersection_points);

   printf(" Find Intersection Points 2: No hits.\n");
   checkit_int(hits, 0);
}

void test_find_intersection_points3()
{
   int num_spheres = 0;
   struct ray r = create_ray(create_point(0.0, 0.0, 0.0),
      create_vector(0.0, 0.0, 1.0));
   int hits = 0;

   hits = find_intersection_points(NULL, num_spheres, r, NULL, NULL);

   printf(" Find Intersection Points 3: Zero spheres passed.\n");
   checkit_int(hits, 0);
}

void test_find_intersection_points()
{
   printf("=== FIND INTERSECTION POINTS TESTS === \n");
   test_find_intersection_points1();
   printf("\n");
   test_find_intersection_points2();
   printf("\n");
   test_find_intersection_points3();
   printf("\n");
}

void test_sphere_normal1()
{
   struct point sp = create_point(0.0, 0.0, 0.0);
   struct sphere s = create_sphere(sp, 4.0);

   struct point p = create_point(0.0, 0.0, 4.0);

   struct vector n = sphere_normal_at_point(s, p);

   printf(" Normal 1: Along z-axis for origin-centered sphere.\n");
   checkit_double(n.x, 0.0);
   checkit_double(n.y, 0.0);
   checkit_double(n.z, 1.0);
}

void test_sphere_normal2()
{
   struct point sp = create_point(0.0, 0.0, 0.0);
   struct sphere s = create_sphere(sp, 4.0);

   struct point p = create_point(0.0, 4.0, 0.0);

   struct vector n = sphere_normal_at_point(s, p);

   printf(" Normal 2: Along y-axis for origin-centered sphere.\n");
   checkit_double(n.x, 0.0);
   checkit_double(n.y, 1.0);
   checkit_double(n.z, 0.0);
}

void test_sphere_normal3()
{
   struct point sp = create_point(0.0, 0.0, 0.0);
   struct sphere s = create_sphere(sp, 4.0);

   struct point p =
      create_point(0.47362624786864, 1.599239329218808, -3.635672117471643);

   struct vector n = sphere_normal_at_point(s, p);

   printf(" Normal 3: Less obvious test case.\n");
   checkit_double(n.x, 0.118406561967);
   checkit_double(n.y, 0.399809832305);
   checkit_double(n.z, -0.908918029368);
}

void test_sphere_normal()
{
   printf("=== SPHERE NORMAL TESTS === \n");
   test_sphere_normal1();
   printf("\n");
   test_sphere_normal2();
   printf("\n");
   test_sphere_normal3();
   printf("\n");
}

void test_cases()
{
   test_sphere_intersection();
   test_find_intersection_points();
   test_sphere_normal();
}

int main(void)
{
   test_cases();

   return 0;
}
