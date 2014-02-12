#include "logic.h"

int is_even(int n)
{
   return  (n%=2)==0;
}

int is_between(int a, int b, int c)
{
   return ( (a>b && a<c) || (a>c && a<b) );
}

int in_an_interval(int n)
{
   return( (n>=2 && n<9) || (n>47 && n<92) || (n>12 && n<=19) || (n>=101 &&  n<=103) );
}
