#include "checkit.h"
#include "char.h"

void test_is_lower_101()
{
   checkit_boolean(is_lower_101('A'),0);
   checkit_boolean(is_lower_101('c'),1);
   checkit_boolean(is_lower_101('*'),0);

}

void test_char_rot_13()
{
   checkit_char(char_rot_13('a'),'n');
   checkit_char(char_rot_13('f'),'s');
   checkit_char(char_rot_13('C'),'P');
   checkit_char(char_rot_13('o'),'b');
   checkit_char(char_rot_13('W'),'J');
   checkit_char(char_rot_13('^'),'^');
   checkit_char(char_rot_13('n'),'a');
   checkit_char(char_rot_13('M'),'Z');
   checkit_char(char_rot_13('z'),'m');
   checkit_char(char_rot_13('Z'),'M'); 

}

void test_cases()
{
   test_is_lower_101();
   test_char_rot_13();
}

int main()
{
   test_cases();
   return 0;
}
