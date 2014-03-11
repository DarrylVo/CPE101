#ifndef COMMANDLINE_H
#define COMMANDLINE_H

void cline(int argc, char **argv);

int scan_file(FILE* fp,struct sphere sphere, struct sphere spheres[]); 

int is_double(char const input[]);

void check_arg(double arg[], char **argv, int argc);

FILE* open_file(char *argv);

#endif
