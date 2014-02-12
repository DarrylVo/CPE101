#include "vector_math.h"
#include "data.h"
#include "collisions.h"
#include "cast.h"
#include <stdio.h>

int convert_color(double c)
{
   return c*255.0;

}

struct color cast_ray(struct ray r, struct sphere spheres[], int num_spheres)
{
   struct sphere hit_spheres[num_spheres];
   struct point intersection_points[num_spheres];
   int a = find_intersection_points(spheres,num_spheres,r,hit_spheres,intersection_points);
   int i;
   int index;
   if(a<=0)
   {
      struct color c1 = create_color(1.0,1.0,1.0);
      return c1;
   }
   else
   {
      for(i=0,index=0;i<a;i++)
      {
         double c = length_vector(vector_from_to(r.p,intersection_points[i]));
         double b = length_vector(vector_from_to(r.p,intersection_points[index]));
         if(c<b)
         {
            index=i;
         }   

      }       
      return hit_spheres[index].color;
   }

}

void cast_all_rays(double min_x, double max_x, double min_y, double max_y, int width, int height, struct point eye, struct sphere spheres[], int num_spheres)
{
   printf("P3\n");
   printf("%d %d\n",width,height);
   printf("%d\n",255);
   double x;
   double y;
   for(y=max_y;y>min_y;y=y-(max_y-min_y)/height )
   {
      for(x=min_x;x<max_x;x=x+(max_x-min_x)/width )
      {
         struct point p = create_point(x,y,0);
         struct ray r = create_ray(eye,vector_from_to(eye,p));
         struct color c1 = cast_ray(r,spheres,num_spheres);
         printf("%d\n%d\n%d\n",convert_color(c1.r),convert_color(c1.g),convert_color(c1.b));
         
      }
    }
}
   

