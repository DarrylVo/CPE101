#ifndef PUZZLESOLVE_H
#define PUZZLESOLVE_H
#include <stdio.h>
#include <stdlib.h>
FILE* open_file(char **argv);

void decode_image(char **argv);

FILE* create_file();

void header_print(FILE* fp, FILE* fp2);

void scan_print(FILE* fp, FILE* fp2);
#endif
