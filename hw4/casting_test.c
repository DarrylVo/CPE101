#include "data.h"
#include "vector_math.h"
#include "collisions.h"
#include "cast.h"

void test_cast_all_rays()
{
   struct point eye = create_point(0.0,0.0,-14.0);
   
   struct point ps1 = create_point(1.0,1.0,0.0);
   struct color c1 = create_color(0.0,0.0,1.0);
   struct sphere s1 = create_sphere(ps1,2.0,c1);  
   
   struct point ps2 = create_point(0.5,1.5,-3.0);
   struct color c2 = create_color(1.0,0.0,0.0);
   struct sphere s2 = create_sphere(ps2,0.5,c2);
   
   struct sphere spheres[]={s1,s2};

   cast_all_rays(-10,10,-7.5,7.5,1024,768,eye,spheres,2);

   
}

int main()
{
   test_cast_all_rays();
   return 0;
}
