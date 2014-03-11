#ifndef FADE_P_H
#define FADE_P_H
#include <stdio.h>
#include <stdlib.h>
void fade(int argc, char **argv);

void arg(int argc, char **argv, int p[]);

FILE* open_file(char **argv);

FILE* create_file();

void header_print(FILE* fp, FILE* fp2, int h[]);

void write(FILE* fp, FILE* fp2,int p[], int h[]);

int scale (int c, int x, int y, int p[]);


#endif
