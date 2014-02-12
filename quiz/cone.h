/* Darryl Vo
 * Lab Quiz 1
 */
#ifndef CONE_H
#define CONE_H

struct cone
{
   double radius;
   double height;
};

struct cone create_cone(double radius, double height);

double cone_volume(struct cone c);

int has_greater_volume_than(struct cone c, double check);

struct cone max_of_three(struct cone c1, struct cone c2, struct cone c3);

#endif
