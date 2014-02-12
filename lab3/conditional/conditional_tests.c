#include <stdio.h>
#include "checkit.h"
#include "conditional.h"

void test_min()
{
   checkit_double(min(2.3,3.3),2.3);
   checkit_double(min(5.5,4.4),4.4);
   checkit_double(min(1.1,1.1),1.1);
}

void test_max()
{
   checkit_double(max(1.1,2.2),2.2);
   checkit_double(max(5.5,2.2),5.5);
   checkit_double(max(4.4,4.4),4.4);
}

void test_rental_late_fee()
{
   checkit_int(rental_late_fee(0),0);
   checkit_int(rental_late_fee(8),5);
   checkit_int(rental_late_fee(9),5);
   checkit_int(rental_late_fee(12),7);
   checkit_int(rental_late_fee(15),7);
   checkit_int(rental_late_fee(20),19);
   checkit_int(rental_late_fee(24),19);
   checkit_int(rental_late_fee(25),100);
}

void test_max_of_three()
{
   checkit_double(max_of_three(1.1,2.2,3.3),3.3);
   checkit_double(max_of_three(1.1,3.3,2.2),3.3);
   checkit_double(max_of_three(2.2,1.1,3.3),3.3);
   checkit_double(max_of_three(2.2,3.3,1.1),3.3);
   checkit_double(max_of_three(3.3,1.1,2.2),3.3);
   checkit_double(max_of_three(3.3,2.2,1.1),3.3);
   checkit_double(max_of_three(3.3,2.2,2.2),3.3);
   checkit_double(max_of_three(3.3,3.3,3.3),3.3);
}

void test_cases(void)
{
   test_min();
   test_max();
   test_rental_late_fee();
   test_max_of_three();
}

int main(int argc, char **argv)
{
   test_cases();

   return 0;
}
