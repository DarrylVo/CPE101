#include "data.h"
#include "vector_math.h"
#include "collisions.h"
#include <math.h>
#include <stdio.h>
struct maybe_point sphere_intersection_point(struct ray r, struct sphere s)
{
   double a = dot_vector(r.dir,r.dir);
 
   struct vector v=difference_point(r.p,s.center);
  
   double b = 2*dot_vector(v,r.dir);
 

   double c = dot_vector(v,v) - (s.radius*s.radius);
 

   if( (b*b-4*a*c)>0) //two real roots
   {
      double t1 = ( (-b+sqrt((b*b)-(4*a*c)))/(2*a));
    
      double t2 = ( (-b-sqrt((b*b)-(4*a*c)))/(2*a));
   
      if(t1>0 && t2>0) // ray hits sphere twice, need lower t value
      {  
         if(t1<=t2)
         {
            struct maybe_point mp5;
            mp5.isPoint=1;
            mp5.p=translate_point(r.p,scale_vector(r.dir,t1));
            return mp5;
         }   
         else
         {
            struct maybe_point mp6;
            mp6.isPoint=1;
            mp6.p=translate_point(r.p,scale_vector(r.dir,t2));
            return mp6;
         }
      }
      else if( (t1>0&&t2<0) || (t1<0&&t2>0) )  //t is positive and negative,need positive t value
      {
         if(t1>0)
         {
            struct maybe_point mp7;
            mp7.isPoint=1;
            mp7.p=translate_point(r.p,scale_vector(r.dir,t1));
            return mp7;
         }
         else
         {
            struct maybe_point mp8;
            mp8.isPoint=1;
            mp8.p=translate_point(r.p,scale_vector(r.dir,t2));
            return mp8;
         }
            
      }
      else  //no intersection, both t's negative
      {
         struct maybe_point mp1;
         mp1.isPoint=0;         
         mp1.p.x=0;
         mp1.p.y=0;
         mp1.p.z=0;
         return mp1;
      }
      
   }
   else if( (b*b-4*a*c)==0)//one real root
   {
      printf("oneroot!");
      double t3 = -b/2*a;
      if(t3>0)//t is positive, so the ray intersects sphere tangentially
      {
         struct maybe_point mp2;
         mp2.isPoint=1;
         mp2.p=translate_point(r.p,scale_vector(r.dir,t3));
    
         return mp2;
      }
      else //t is negative, so ray does not intersect sphere. 
           //also includes the case where t==0, where the ray starting
           //point is on the sphere. am going to treat like non-intersection
      {
         struct maybe_point mp3;
         mp3.isPoint=0;
         mp3.p.x=0;
         mp3.p.y=0;
         mp3.p.z=0;
         return mp3;
      }
   }
  
   else  // no real roots
   { 
      struct maybe_point mp;
      mp.isPoint=0;
      mp.p.x=0;
      mp.p.y=0;
      mp.p.z=0; 
      return mp;
   }   
}

int find_intersection_points(struct sphere spheres[], int num_spheres, struct ray r, struct sphere hit_spheres[],struct point intersection_points[])
{
   int i;
   int counter;
   for(i=0,counter=0;i<num_spheres;i++)
   {
      struct maybe_point mp = sphere_intersection_point(r,spheres[i]);
      if( mp.isPoint==1)
      {
        hit_spheres[counter]=spheres[i];
        intersection_points[counter]=mp.p; 
        counter++;
      }
   }
   return counter;

}

struct vector sphere_normal_at_point(struct sphere s, struct point p)
{
   struct vector v = normalize_vector(vector_from_to(s.center,p));
   return v;
}

