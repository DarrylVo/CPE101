#include "poly.h"
#include "checkit.h"


void test_poly_add2()
{
   double poly1[3]= {1.1,2.2,3.3};
   double poly2[3]= {4.4,5.5,6.6};
   double result1[3];
   poly_add2(poly1,poly2,result1);
   checkit_double(result1[0],5.5);
   checkit_double(result1[1],7.7);
   checkit_double(result1[2],9.9);

   double poly3[3]={2.1,3.1,4.1};
   double poly4[3]={-5.3,6.1,-7.3};
   double result2[3];
   poly_add2(poly3,poly4,result2);
   checkit_double(result2[0],-3.2);
   checkit_double(result2[1],9.2);
   checkit_double(result2[2],-3.2);
}

void test_poly_mult2()
{
   double poly5[3]={3.2,2.1,7.3};
   double poly6[3]={1.1,3.2,8.3};
   double result3[5];
   poly_mult2(poly5,poly6,result3);
   checkit_double(result3[4],60.59);
   checkit_double(result3[3],40.79);
   checkit_double(result3[2],41.31);
   checkit_double(result3[1],12.55);
   checkit_double(result3[0],3.52);

   double poly7[3]={-5.2,1.1,-2.9};
   double poly8[3]={-8.1,-7.8,1.7};
   double result4[5];
   poly_mult2(poly7,poly8,result4);
   checkit_double(result4[4],-4.93);
   checkit_double(result4[3],24.49);
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
