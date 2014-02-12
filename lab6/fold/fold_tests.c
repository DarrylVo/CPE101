#include "checkit.h"
#include "fold.h"
#include "point.h"

void test_sum()
{
   double input1[]={2.3,0,1.2,-3.2,-2.1};
   double sum1=sum(input1,5);
   checkit_double(sum1,-1.8);

   double input2[]={-3.2,-4.5,0,2.2,3.3};
   double sum2=sum(input2,5);
   checkit_double(sum2,-2.2);
}

void test_index_of_smallest()
{
   double input3[]={-1.2,3.2,7.8,2.2};
   int a = index_of_smallest(input3,4);
   checkit_int(a,0);

   double input4[]={3.2,-9.8,-1.2,3.7};
   int b = index_of_smallest(input4,4);
   checkit_int(b,1);

   double input5[2];
   int c = index_of_smallest(input5,0);
   checkit_int(c,-1);
   
   double input6[]={9.8,1.3,0.3,12.2};
   int d = index_of_smallest(input6,4);
   checkit_int(d,2);
}

void test_nearest_origin()
{
   struct point p1 = create_point(3.2,4.5);
   struct point p2 = create_point(-3.2,-4.5);
   struct point p3 = create_point(-3.4,1.2);
   struct point p4 = create_point(-0.5,0.6);
   struct point p5 = create_point(5.6,-2.9);
   struct point input7[]={p1,p2,p3,p4,p5};
   int a = nearest_origin(input7,3); 



}

void test_cases()
{
   test_sum();
   test_index_of_smallest();
   test_nearest_origin();

}

int main ()
{
   test_cases();
   return 0;
}
