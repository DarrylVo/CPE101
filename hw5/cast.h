#include "data.h"
#include "vector_math.h"
#include "collisions.h"
#ifndef CAST_H
#define CAST_H

struct color cast_ray(struct ray r, struct sphere spheres[], int num_spheres, struct color ambient, struct light light, struct point eye);

void cast_all_rays(double min_x, double max_x, double min_y, double max_y, int width, int height, struct point eye, struct sphere spheres[], int num_spheres, struct color ambient,struct light light);

int convert_color(double c);

struct color add_ambience(struct color color, struct color ambient, struct finish finish);

struct color add_light(struct color before_color, struct color after_color, struct light light, double dot, struct finish finish);

struct color add_spec(struct color color, struct light light, double s_spec,double c_spec,double s_r);
#endif
