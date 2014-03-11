#include "poly.h"
#include "checkit.h"


void test_poly_add2()
{
   double poly1[]= {1.1,2.2,3.3};
   double poly2[]= {4.4,5.5,6.6,10.2};
   double result1[4];
   poly_add2(poly1,2,poly2,3,result1);
   checkit_double(result1[0], 5.5);
   checkit_double(result1[1],7.7);
   checkit_double(result1[2],9.9);
   checkit_double(result1[3],10.2);

   double poly3[]={2.1,3.1,4.1,6.2,7.1};
   double poly4[]={-5.3,6.1,-7.3};
   double result2[5];
   poly_add2(poly3,4,poly4,2,result2);
   checkit_double(result2[0],-3.2);
   checkit_double(result2[1],9.2);
   checkit_double(result2[2],-3.2);
   checkit_double(result2[3],6.2);
   checkit_double(result2[4],7.1);

}

void test_poly_mult2()
{
   double poly5[]={3.2,2.1,7.3,6.7};
   double poly6[]={1.1,3.2,8.3};
   double result3[6];
   poly_mult2(poly5,3,poly6,2,result3);
   checkit_double(result3[5],55.61);
   checkit_double(result3[4],82.03);
   checkit_double(result3[3],48.16);
   checkit_double(result3[2],41.31);
   checkit_double(result3[1],12.55);
   checkit_double(result3[0],3.52);

   double poly7[]={-5.2,1.1,-2.9};
   double poly8[]={-8.1,-7.8,1.7,-3.4,1.2};
   double result4[7];
   poly_mult2(poly7,2,poly8,4,result4);
   checkit_double(result4[6],-3.48);
   checkit_double(result4[5],11.18);
   checkit_double(result4[4],-14.91);
   checkit_double(result4[3],42.17);
   checkit_double(result4[2],6.07);
   checkit_double(result4[1],31.65);
   checkit_double(result4[0],42.12);

   
}

void test_cases()
{
   test_poly_add2();
   test_poly_mult2();
}

int main()
{
   test_cases();
   return 0;
}
