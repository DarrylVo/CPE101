#include "checkit.h"
#include "convert.h"
#include <string.h>





void test_convert_double()
{
   char s1[]={"3.4\0"};
   double a = convert_double(s1,4.2); 
   checkit_double(a,3.4);  

   char s2[]={"asdfcxzv\0"};
   double b = convert_double(s2,3.2);
   checkit_double(b,3.2);

   char s3[]={"asdfdfs3.4asdfasdf\0"};
   double c = convert_double(s3,32.1);
   checkit_double(c,32.1);

   char s4[]={"-3.2\0"};
   double d = convert_double(s4,4.2);
   checkit_double(d,-3.2);
}

int main()
{
   test_convert_double();
   return 0;
}
