#include "filter.h"
#include "point.h"
#include "checkit.h"

void test_are_positive()
{
   double input1[]={-3.1,2.1,-1.1,0,3.3};   
   double result1[5];
   int a = are_positive(input1,5,result1);
   checkit_int(a,2);
   checkit_double(result1[0],2.1);
   checkit_double(result1[1],3.3);

   double input2[]={5.2,1.1,3.1,0,-4.4};
   double result2[5];
   int b = are_positive(input2,5,result2);
   checkit_int(b,3);
   checkit_double(result2[0],5.2);
   checkit_double(result2[1],1.1);
   checkit_double(result2[2],3.1);

}

void test_are_greater_than()
{
   double input3[]={-3.2,5.7,0,2.3,-1.2};
   double result3[5];
   int c = are_greater_than(2.1,input3,5,result3);
   checkit_int(c,2);
   checkit_boolean(result3[0],5.7);
   checkit_boolean(result3[1],2.3);

   double input4[]={1.1,-3.3,-7.5,4.5,7.8};
   double result4[5];
   int d = are_greater_than(3.3,input4,5,result4);
   checkit_int(d,2);
   checkit_boolean(result4[0],4.5);
   checkit_boolean(result4[1],7.8);
}

void test_are_in_first_quadrant()
{
   struct point p1 = create_point(-1.1,-2.2);
   struct point p2 = create_point(-3.2,1.4);
   struct point p3 = create_point(3.8,9.9);
   struct point p4 = create_point(4.5,-1.1);
   struct point input5[]={p1,p2,p3,p4};
   struct point result5[4];
   int e = are_in_first_quadrant(input5,4,result5);
   checkit_int(e,1);
   checkit_double(result5[0].x,3.8);
   checkit_double(result5[0].y,9.9);

   struct point p5 = create_point(0.0,0.0);
   struct point p6 = create_point(-1.1,-2.2);
   struct point p7 = create_point(4.5,1.2);
   struct point p8 = create_point(-3.3,4.2);
   struct point p9 = create_point(3.1,-9.9);
   struct point p10 = create_point(5.2,2.1);
   struct point input6[]={p5,p6,p7,p8,p9,p10};
   struct point result6[6];
   int f = are_in_first_quadrant(input6,6,result6);
   checkit_int(f,2);
   checkit_double(result6[0].x,4.5);
   checkit_double(result6[0].y,1.2);
   checkit_double(result6[1].x,5.2);
   checkit_double(result6[1].y,2.1);
}

void test_cases()
{
   test_are_positive();
   test_are_greater_than();
   test_are_in_first_quadrant();
}

int main()
{
   test_cases();
   return 0;
}
