#include "string.h"
#include "checkit.h"








void test_str_rot_13()
{
   char input[]={'a','o','C','Q','^',0};
   char result[6];
   str_rot_13(input,result);
   checkit_string(result,"nbPD^");
   char input2[]={"aAubp%ZncP\0"};
   char result2[11];
   str_rot_13(input2,result2);
   checkit_string(result2,"nNhoc%MapC");
}

void test_str_cat_101()
{
   char input1[]={"fucku\0"};
   char input2[]={"ilikeshit\0"};
   char result1[15];
   str_cat_101(input1,input2,result1);
   checkit_string(result1,"fuckuilikeshit");

   char input3[]={"weeeee&*&fack\0"};
   char input4[]={"fuckingshit!\0"};
   char result2[25];
   str_cat_101(input3,input4,result2);
   checkit_string(result2,"weeeee&*&fackfuckingshit!")

}

void test_cases()
{
   test_str_rot_13();
   test_str_cat_101();
}

int main(int argc, char *argvp[])
{
   test_cases();
   return 0;
}
