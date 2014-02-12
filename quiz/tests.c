/* Darryl Vo
 * Lab Quiz 1
 */
#include "cone.h"
#include "checkit.h"

void  test_create_cone()
{
   struct cone c = create_cone(1.1,2.2);
   checkit_double(c.radius,1.1);
   checkit_double(c.height,2.2);
}

void test_cone_volume()
{
   struct cone c2 = create_cone(3.2,4.2);
   checkit_double(c2.radius,3.2);
   checkit_double(c2.height,4.2);
   checkit_double(cone_volume(c2),45.037862912);
}

void test_has_greater_volume_than()
{
   struct cone c3 = create_cone(2.2,3.3);
   checkit_boolean(has_greater_volume_than(c3,12.2),1);
   checkit_boolean(has_greater_volume_than(c3,20.2),0);
}

void test_max_of_three()
{
   struct cone c4 = create_cone(3.4,5.5);
   struct cone c5 = create_cone(1.1,2.3);
   struct cone c6 = create_cone(8.8,9.9);
   struct cone cmax = max_of_three(c4,c5,c6);
   checkit_double(cmax.radius,8.8);
   checkit_double(cmax.height,9.9);
}

void test_cases()
{
   test_create_cone();
   test_cone_volume();
   test_has_greater_volume_than();
   test_max_of_three();
}

int main()
{
   test_cases();
   return 0;
}
