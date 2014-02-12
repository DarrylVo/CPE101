#include <stdio.h>
#include "checkit.h"
#include "logic.h"

void test_is_even()
{
   checkit_boolean(is_even(4),1);
   checkit_boolean(is_even(3),0);
}

void test_is_between()
{
   checkit_boolean(is_between(2,1,3),1);
   checkit_boolean(is_between(4,5,3),1);
   checkit_boolean(is_between(7,2,3),0);
   checkit_boolean(is_between(7,5,2),0);
   checkit_boolean(is_between(7,7,8),0);
   checkit_boolean(is_between(3,3,3),0);
}

void test_in_an_interval()
{
   checkit_int(in_an_interval(1),0);
   checkit_int(in_an_interval(2),1);
   checkit_int(in_an_interval(8),1);
   checkit_int(in_an_interval(9),0);
   checkit_int(in_an_interval(10),0);
   checkit_int(in_an_interval(44),0);
   checkit_int(in_an_interval(47),0);
   checkit_int(in_an_interval(49),1);
   checkit_int(in_an_interval(92),0);
   checkit_int(in_an_interval(94),0);
   checkit_int(in_an_interval(11),0);
   checkit_int(in_an_interval(12),0);
   checkit_int(in_an_interval(15),1);
   checkit_int(in_an_interval(19),1);
   checkit_int(in_an_interval(20),0);
   checkit_int(in_an_interval(100),0);
   checkit_int(in_an_interval(101),1);
   checkit_int(in_an_interval(102),1);
   checkit_int(in_an_interval(103),1);
   checkit_int(in_an_interval(104),0);
}

void test_cases(void)
{
   test_is_even();
   test_is_between();
   test_in_an_interval();
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
