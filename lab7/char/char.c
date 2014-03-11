#include "char.h"

int is_lower_101(char c)
{
   if (c>='a'&&c<='z')
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

char char_rot_13(char c)
{
   if( (c>='a'&&c<'n')||(c>='A'&&c<='N'))
   {
      return c+13;

   }
   else if((c>='n'&&c<='z')||(c>='N'&&c<='Z'))
   {
      return c-13;
   }
   else
   {
      return c;
   }
}
