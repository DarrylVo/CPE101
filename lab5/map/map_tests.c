#include "checkit.h"
#include "map.h"
#include "point.h"
void test_square_all()
{
   double input[]={1.3,3.2,-2.1,0.0};
   double result[4];
   square_all(input,4,result);
   checkit_double(result[0],1.69);
   checkit_double(result[1],10.24);
   checkit_double(result[2],4.41);
   checkit_double(result[3],0);

   double input2[]={-4.2,1.4,0.0,9.1,-2.1};
   double result2[5];
   square_all(input2,5,result2);
   checkit_double(result2[0],17.64);
   checkit_double(result2[1],1.96);
   checkit_double(result2[2],0.0);
   checkit_double(result2[3],82.81);
   checkit_double(result2[4],4.41);
}

void test_add_n_all()
{
   double input3[]={-3.2,1.4,0.0,4.5};
   double result3[4];
   add_n_all(3.1,input3,4,result3);
   checkit_double(result3[0],-0.1);
   checkit_double(result3[1],4.5);
   checkit_double(result3[2],3.1);
   checkit_double(result3[3],7.6);

   double input4[]={3.5,-6.2,0.0,9.8,-10.2};
   double result4[5];
   add_n_all(-1.3,input4,5,result4);
   checkit_double(result4[0],2.2);
   checkit_double(result4[1],-7.5);
   checkit_double(result4[2],-1.3);
   checkit_double(result4[3],8.5);
   checkit_double(result4[4],-11.5);
}

void test_distance_all()
{
   struct point p1 = create_point(-2.3,1.1);
   struct point p2 = create_point(-3.3,-4.5);
   struct point p3 = create_point(3.6,1.2);
   struct point input5[]={p1,p2,p3};
   double result5[3];
   distance_all(input5,3,result5);
   checkit_double(result5[0],2.54950976);
   checkit_double(result5[1],5.580322571);
   checkit_double(result5[2],3.79473319220);

   struct point p4 = create_point(4.5,2.2);
   struct point p5 = create_point(0,-3.2);
   struct point p6 = create_point(-2.2,1.9);
   struct point p7 = create_point(3.4,-6.5);
   struct point p8 = create_point(-6.6,-7.7);
   struct point p9 = create_point(2.1,0);
   struct point input6[]={p4,p5,p6,p7,p8,p9};
   double result6[6];
   distance_all(input6,6,result6);
   checkit_double(result6[0],5.00899191454);
   checkit_double(result6[1],3.2);
   checkit_double(result6[2],2.906883);
   checkit_double(result6[3],7.3355299);
   checkit_double(result6[4],10.14149890);
   checkit_double(result6[5],2.1);

}

void test_cases()
{
   test_square_all();
   test_add_n_all();
   test_distance_all();
}

int main()
{
   test_cases();
   return 0;
}
