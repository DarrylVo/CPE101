#include "vector_math.h"
#include "data.h"
#include "collisions.h"
#include "cast.h"
#include <stdio.h>
#include <math.h>

int convert_color(double c)
{
   int d= c*255;
   if(d>=255)
   {
      return 255;
   }
   else
   {
      return d;
   }

}

struct color add_ambience(struct color color,struct color ambient, struct finish finish)
{
   
   
   struct color c2;
   c2.r=color.r*ambient.r*finish.ambient;
   c2.g=color.g*ambient.g*finish.ambient;
   c2.b=color.b*ambient.b*finish.ambient;
   return c2;
  
}

struct color add_light(struct color before_a, struct color after_a, struct light light, double dot, struct finish finish)
{
      struct color c2;
      c2.r=after_a.r+(before_a.r*light.color.r*dot*finish.diffuse);
      c2.g=after_a.g+(before_a.g*light.color.g*dot*finish.diffuse);
      c2.b=after_a.b+(before_a.b*light.color.b*dot*finish.diffuse);
      return c2;
}

struct color add_spec(struct color color, struct light light,double s_spec,double c_spec, double s_r)
{
   struct color c = color;
   
          
   c.r+=light.color.r*s_spec*pow(c_spec,1/s_r);
   c.g+=light.color.g*s_spec*pow(c_spec,1/s_r);
   c.b+=light.color.b*s_spec*pow(c_spec,1/s_r);
   return c;


}
  
struct color cast_ray(struct ray r, struct sphere spheres[], int num_spheres,struct color ambient,struct light light, struct point eye)
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
      intersection_points[index]=translate_point(intersection_points[index],scale_vector(sphere_normal_at_point(hit_spheres[index],intersection_points[index]),0.01));
        
      struct vector n = sphere_normal_at_point(hit_spheres[index],intersection_points[index]);
      struct vector ldir = normalize_vector(vector_from_to(intersection_points[index],light.p));     
      double q = dot_vector(n,ldir);


      struct vector reflect =  difference_vector(scale_vector(n,2*q),ldir);

      struct vector vdir = normalize_vector(vector_from_to(eye,intersection_points[index]));

      double spec = dot_vector(reflect,vdir);

      struct ray r2 = create_ray(intersection_points[index],ldir);
      if(q>0)
      {
         int i2;
         for(i2=0;i2<num_spheres;i2++)
         {
            double distance = length_vector(vector_from_to(intersection_points[index],light.p));
            struct maybe_point mp = sphere_intersection_point(r2,spheres[i2]);
            double distance2 = length_vector(difference_point(r2.p,mp.p));
            if(mp.isPoint==1&&distance>distance2)
            {
               struct color col= add_ambience(hit_spheres[index].color,ambient,hit_spheres[index].finish);
               return col;
            }
         }	
         struct color ce = add_ambience(hit_spheres[index].color,ambient,hit_spheres[index].finish);
         struct color ce2 = add_light(hit_spheres[index].color,ce,light,q,hit_spheres[index].finish);
         struct color ce3= add_spec(ce2,light,hit_spheres[index].finish.specular,spec,hit_spheres[index].finish.roughness);
         return ce3; 
     }  
     else
     {
        struct color col2= add_ambience(hit_spheres[index].color,ambient,hit_spheres[index].finish);
        return col2;
     } 
   }   
}

void cast_all_rays(double min_x, double max_x, double min_y, double max_y, int width, int height, struct point eye, struct sphere spheres[], int num_spheres,struct color ambient, struct light light)
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
         struct color c1 = cast_ray(r,spheres,num_spheres,ambient,light,eye);
         printf("%d\n%d\n%d\n",convert_color(c1.r),convert_color(c1.g),convert_color(c1.b));
         
      }
    }
}
   

