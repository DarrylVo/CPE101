#include "checkit.h"
#include "rect.h"
#include <math.h>

void test_largest_rect()
{
   struct point p1 = create_point(1,2);
   struct rect r1 = create_rect(p1,3,4);

   struct point p2 = create_point(3,4);
   struct rect r2 = create_rect(p2,6,7);

   struct point p3 = create_point(5,6);
   struct rect r3 = create_rect(p3,8,9);

   struct rect a_rect[]={r3,r1,r2};

   int a = largest_rect(a_rect,3);
   checkit_int(a,0);

}


void test_distance()
{
   struct point p1 = create_point(1,2);
   struct point p2 = create_point(3,4);
   double a = distance(p1,p2);
   checkit_double(a,2.828427125);


}

void test_cases()
{
   struct point p = create_point(1,2);
   checkit_double(p.x,1);
   checkit_double(p.y,2);
   struct point p2 = create_point(3,4);
   int w = 5;
   int h = 6;
   struct rect r = create_rect(p2,w,h);
   checkit_int(r.ll.x,3);
   checkit_int(r.ll.y,4);
   checkit_int(r.w,5);
   checkit_int(r.h,6);
   
   test_distance();
   test_largest_rect();

}

int main()
{
   test_cases();
   return 0;
}
