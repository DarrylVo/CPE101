/* 
 * Darryl Vo
 * Lab Quiz 2
 */
#ifndef RECT_H
#define RECT_H

struct point
{
   int x;
   int y;
};

struct point create_point(int x, int y);

struct rect
{
   struct point ll;
   int w;
   int h;
};

struct rect create_rect(struct point ll,int w, int h);

double distance(struct point p1, struct point p2);

int largest_rect(struct rect a_rect[],int size);

void closest_corners(struct rect r1, struct rect r2, struct point a_p[]);

#endif
