/* Darryl Vo
 * CPE 101 section 5
 * HW2
 */

#include "data.h"
#include "checkit.h"
#include "vector_math.h"
#include "collisions.h"
#include "cast.h"

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
   struct color c = create_color(0.2,0.3,0.4);
   struct finish f = create_finish(0.2,0.3,0.4,0.5);
   struct sphere c1 = create_sphere(center,4.4,c,f);
   checkit_double(c1.center.x,1.1);
   checkit_double(c1.center.y,2.2);
   checkit_double(c1.center.z,3.3);
   checkit_double(c1.radius,4.4);
   checkit_double(c1.color.r,0.2); 
   checkit_double(c1.color.g,0.3); 
   checkit_double(c1.color.b,0.4);
   checkit_double(c1.finish.ambient,0.2);
   checkit_double(c1.finish.diffuse,0.3);
   checkit_double(c1.finish.specular,0.4);
   checkit_double(c1.finish.roughness,0.5);
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
   struct color c1 = create_color(0.0,0.0,0.0);
   struct finish f1 = create_finish(0.3,0.4,0.5,0.6);
   struct sphere s1 = create_sphere(ps1,3.1,c1,f1);
   struct maybe_point mp1 = sphere_intersection_point(r1,s1);
   checkit_boolean(mp1.isPoint,0);
 
   //both t's positive
   struct point p2 = create_point(0.1,0.1,0.1);
   struct vector v2 = create_vector(1.2,1.2,1.2);
   struct ray r2 = create_ray(p2,v2);
   struct point ps2 = create_point(5.3,5.3,5.3);
   struct color c2 = create_color(0.0,0.0,0.0);
   struct finish f2 = create_finish(0.3,0.4,0.5,0.6);
   struct sphere s2 = create_sphere(ps2,2.4,c2,f2);
   struct maybe_point mp2 = sphere_intersection_point(r2,s2);
   checkit_boolean(mp2.isPoint,1); 
   checkit_double(mp2.p.x,3.914359);

   //one t positive one t negative
   struct point p3 = create_point(1.1,2.2,3.3);
   struct vector v3 = create_vector(1.2,1.1,1.1);
   struct ray r3 = create_ray(p3,v3);
   struct point ps3 = create_point(2.3,2.4,2.5);
   struct color c3 = create_color(0.0,0.0,0.0);
   struct finish f3 = create_finish(0.6,0.2,0.5,0.6);
   struct sphere s3 = create_sphere(ps3,5.6,c3,f3);
   struct maybe_point mp3 = sphere_intersection_point(r3,s3);
   checkit_boolean(mp3.isPoint,1);
   checkit_double(mp3.p.x,4.654131);
 
   //both t's are negative
   struct point p4 = create_point(-.1,-.1,-.1);
   struct vector v4 = create_vector(-1.2,0.2,0.2);
   struct ray r4 = create_ray(p4,v4);
   struct point ps4 = create_point(5.2,0.3,0.3);
   struct color c4 = create_color(0.0,0.0,0.0);
   struct finish f4 = create_finish(0.2,0.1,0.5,0.6);
   struct sphere s4 = create_sphere(ps4,4.8,c4,f4);
   struct maybe_point mp4 = sphere_intersection_point(r4,s4);
   checkit_boolean(mp4.isPoint,0);
}

void test_find_intersection_points()
{
   
   struct point p5 = create_point(1.1,2.2,3.3);
   struct vector v5 = create_vector(1.2,1.1,1.1);
   struct ray r5 = create_ray(p5,v5);
  
   struct point ps5 = create_point(-3.3,-4.4,-3.5);
   struct color c5 = create_color(0.0,0.0,0.0);
   struct finish f5 = create_finish(0.3,0.9,0.5,0.6);
   struct sphere s5 = create_sphere(ps5,1.1,c5,f5);
  
   struct point ps6 = create_point(3.3,4.3,3.2);
   struct color c6 = create_color(0.2,0.3,0.4);
   struct finish f6 = create_finish(0.5,0.8,0.5,0.6);
   struct sphere s6 = create_sphere(ps6,4.8,c6,f6);
   
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
   checkit_double(hit_spheres[0].color.r,0.2);
   checkit_double(hit_spheres[0].color.g,0.3);
   checkit_double(hit_spheres[0].color.b,0.4);
   checkit_double(hit_spheres[0].finish.ambient,0.5);
   checkit_double(hit_spheres[0].finish.diffuse,0.8);
   checkit_double(intersection_points[0].x,5.325828);
   checkit_double(intersection_points[0].y,6.073675);
   checkit_double(intersection_points[0].z,7.173675);
}

void test_sphere_normal_at_point()
{
   struct point ps7 = create_point(0.1,0.1,0.1);
   struct color c7 = create_color(0.0,0.0,0.0);
   struct finish f7 = create_finish(0.2,0.3,0.4,0.5);
   struct sphere s7 = create_sphere(ps7,5.2,c7,f7);

   struct point tp1 = create_point(2.2,1.3,4.703259715);

   struct vector normal = sphere_normal_at_point(s7,tp1);
   checkit_double(normal.x,0.403846154);
   checkit_double(normal.y,0.230769231);
   checkit_double(normal.z,0.885242253);
}

void test_convert_color()
{
   checkit_int(convert_color(0.7),178);
   checkit_int(convert_color(0.0),0);
   checkit_int(convert_color(1.0),255);
   checkit_int(convert_color(0.9),229);
}

void test_add_ambient()
{
   struct color c1 = create_color(0.1,0.2,0.3);
   struct color ambient1 = create_color(0.4,0.5,0.6);  
   struct finish f1 = create_finish(0.2,0.8,0.7,0.6);
   struct color tc1 = add_ambience(c1,ambient1,f1);
   checkit_double(tc1.r,0.008);
   checkit_double(tc1.g,0.02);
   checkit_double(tc1.b,0.036);


   struct color c2 = create_color(0.6,0.1,0.2);
   struct color ambient2 = create_color(0.3,0.1,0.2);  
   struct finish f2 = create_finish(0.1,0.3,0.4,0.5);
   struct color tc2 = add_ambience(c2,ambient2,f2);
   checkit_double(tc2.r,0.018);
   checkit_double(tc2.g,0.001);
   checkit_double(tc2.b,0.004);
}

void test_add_light()
{
   struct color c1 = create_color(0.1,0.3,0.2);
   struct color ambient1 = create_color(0.1,0.5,0.6);
   struct finish f1 = create_finish(0.2,0.8,0.7,0.2);
   struct color tc1 = add_ambience(c1,ambient1,f1);
   struct point lp = create_point(100,-100,100);
   struct color lc = create_color(0.8,0.7,0.6);
   struct light light = create_light(lp,lc);
   double q = 3.45;
   struct color tc2 = add_light(c1,tc1,light,q,f1);
   checkit_double(tc2.r,0.2228);
   checkit_double(tc2.g,0.6096);
   checkit_double(tc2.b,0.3552);

   struct color c2 = create_color(0.3,0.8,0.1);
   struct color ambient2 = create_color(0.4,0.3,0.9);
   struct finish f2 = create_finish(0.1,0.9,0.4,0.3);
   struct color tc3 = add_ambience(c2,ambient2,f2);
   struct point lp1 = create_point(100,-102,300);
   struct color lc1 = create_color(0.8,0.57,0.3);
   struct light light1 = create_light(lp1,lc1);
   double q1 = 2.28;
   struct color tc4 = add_light(c2,tc3,light1,q1,f2);
   checkit_double(tc4.r,0.504480);
   checkit_double(tc4.g,0.959712);
   checkit_double(tc4.b,0.070560);
}

void test_add_spec()
{
   struct color c1 = create_color(0.1,0.2,0.3);
   
   struct point lp = create_point(100,-100,100);
   struct color lc = create_color(0.9,0.8,0.7);
   struct light light = create_light(lp,lc);
   
   struct point ps = create_point(6.7,-7.6,2.3);
   struct color cs = create_color(0.2,0.3,0.4);
   struct finish fs = create_finish(0.3,0.6,0.2,0.8);
   struct sphere s1 = create_sphere(ps,3.2,cs,fs);

   double c_spec = 0.3;

   struct color tc1 = add_spec(c1,light,s1.finish.specular,c_spec,s1.finish.roughness);
   checkit_double(tc1.r,0.139964);
   checkit_double(tc1.g,0.235524);
   checkit_double(tc1.b,0.331083);

   struct color c2 = create_color(0.3,0.4,0.1);
   
   struct point lp2 = create_point(50,-100,100);
   struct color lc2 = create_color(0.5,0.3,0.2);
   struct light light2 = create_light(lp2,lc2);
   
   struct point ps2 = create_point(4.2,-10.3,5.6);
   struct color cs2 = create_color(0.3,0.1,0.9);
   struct finish fs2 = create_finish(0.1,0.3,0.7,0.1);
   struct sphere s2 = create_sphere(ps2,5.6,cs2,fs2);

   double c_spec2 = 0.52;

   struct color tc2 = add_spec(c2,light2,s2.finish.specular,c_spec2,s2.finish.roughness);
   checkit_double(tc2.r,0.300506);
   checkit_double(tc2.g,0.400304);
   checkit_double(tc2.b,0.100202);
}

void test_cast_ray()
{
   struct point p1 = create_point(1.2,2.1,1.4); 
   struct vector v1 = create_vector(1.1,2.3,1.6);
   struct ray r1 = create_ray(p1,v1);

   struct point ps1 = create_point(4.5,4.2,4.6);
   struct color c1 = create_color(0.1,0.2,0.3);
   struct finish f1 = create_finish(0.7,0.8,0.1,0.2);
   struct sphere s1 = create_sphere(ps1,2.1,c1,f1); 

   struct point ps2 = create_point(-2.4,-3.1,2.6);
   struct color c2 = create_color(0.4,0.5,0.6);
   struct finish f2 = create_finish(0.5,0.6,0.3,0.4);
   struct sphere s2 = create_sphere(ps2,2.2,c2,f2);

   struct point ps3 = create_point(1.3,2.4,1.1);
   struct color c3 = create_color(0.7,0.8,0.9);
   struct finish f3 = create_finish(0.3,0.4,0.5,0.6);
   struct sphere s3 = create_sphere(ps3,1.1,c3,f3);

   struct sphere spheres[]={s1,s2,s3};

   struct color ambient = create_color(0.2,0.3,0.4);

   struct point pl= create_point(100,-100,100);
   struct color cl= create_color(1.5,1.5,1.5);
   struct light light = create_light(pl,cl);
   
   struct point eye = create_point(100,-100,100);
   struct color tc1 = cast_ray(r1,spheres,3,ambient,light,eye);
   checkit_double(tc1.r,0.687759);
   checkit_double(tc1.g,0.736985);
   checkit_double(tc1.b,0.792220);
   

   struct point p2 = create_point(-0.5,-1.2,-1.5);
   struct vector v2 = create_vector(-1.2,-2.4,-1.6);
   struct ray r2 = create_ray(p2,v2);
   
   struct point ps4 = create_point(1.4,3.2,6.7);
   struct color c4 = create_color(0.1,0.4,0.3);
   struct finish f4 = create_finish(0.4,0.3,0.9,0.8);
   struct sphere s4 = create_sphere(ps4,2.1,c4,f4);

   struct point ps5 = create_point(-2.2,-2.6,-2.1);
   struct color c5 = create_color(0.3,0.2,0.1);
   struct finish f5 = create_finish(0.1,0.2,0.3,0.4);
   struct sphere s5 = create_sphere(ps5,2.3,c5,f5);

   struct point ps6 = create_point(-5.5,-6.6,-7.7);
   struct color c6 = create_color(0.9,0.8,0.7);
   struct finish f6 = create_finish(0.5,0.6,0.1,0.2);
   struct sphere s6 = create_sphere(ps6,1.2,c6,f6);

   struct sphere spheres2[]={s4,s5,s6};

   struct color ambient1 = create_color(0.3,0.2,0.6);

   struct color tc2 = cast_ray(r2,spheres2,3,ambient1,light,eye);
   checkit_double(tc2.r,0.455937);
   checkit_double(tc2.g,0.449070);
   checkit_double(tc2.b,0.449203);

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
   test_cast_ray();
   test_convert_color();
   test_add_ambient();
   test_add_light();
   test_add_spec();
}

int main(int argc, char **argv)
{
   test_cases();
   return 0;
}
