/*
 * Darryl Vo
 * Lab Quiz 2
 */

#include "rect.h"
#include <math.h>
struct point create_point(int x, int y)
{
   struct point p;
   p.x=x;
   p.y=y;
   return p;
}

struct rect create_rect(struct point ll, int w, int h)
{
   struct rect r;
   r.ll=ll;
   r.w=w;
   r.h=h;
   return r;   
}

double distance(struct point p1, struct point p2)
{
   double a = (p1.x-p2.x)*(p1.x-p2.x);   
   double b = (p1.y-p2.y)*(p1.y-p2.y);
   return sqrt(a+b);


}

int largest_rect(struct rect a_rect[], int size)
{
   if(size==0)
   {
      return -1;
   }
   else
   {
      int i;
      int index=0;
      for(i=0;i<size;i++)
      {
         int a = a_rect[i].w*a_rect[i].h;
         int b = a_rect[index].w*a_rect[index].h;
         if (a>b)
         {
            index=i;
         }
      }
      return index;
   
   }

}

void closest_corners(struct rect r1, struct rect r2, struct point a_p[])
{
   struct point one_one = r1.ll;
   struct point one_two= create_point(r1.ll.x,r1.ll.y+r1.h);
   struct point one_three= create_point(r1.ll.x+r1.w,r1.ll.y+r1.h);
   struct point one_four = create_point(r1.ll.x+r1.w,r1.ll.y);

   struct point two_one = r2.ll;
   struct point two_two = create_point(r2.ll.x,r2.ll.y+r2.h);
   struct point two_three = create_point(r2.ll.x+r2.w,r2.ll.y+r2.h);
   struct point two_four = create_point(r2.ll.x+r2.w,r2.ll.y);

   struct point a1[]={one_one,one_two,one_three,one_four};
   struct point a2[]={two_one,two_two,two_three,two_four};
   int i;
   int index=0;
   int i2;
   int index2=0;
   for (i=0;i<4;i++)
   {
      for (i2=0;i2<4;i2++)
      {
         double a = distance(a1[index],a2[index2]);
         double b = distance(a1[i],a2[i2]);
         if (b<a)
         { 
            index=i;
            index2=i2;
         }

      }
      a_p[0]=a1[index];
      a_p[1]=a2[index2];
      
   }
   





}





