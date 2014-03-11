#include "point.h"
#include <stdlib.h>
#include <stdio.h>



int func(int argc, char **argv)
{
   FILE *fp;
   fp=fopen(argv[1],"r");
   if(fp==NULL)
   {
      printf("cant open file");
      exit(1);
   }
   double x; 
   double y;
   while( fscanf(fp,"%lf",&x)!=EOF)
   {
      fscanf(fp,"%lf",&y);
      if(x>0&&y>0)
      { 
         struct point p;
         p.x=x;
         p.y=y;
         printf("%f",p.x);
         printf(" ");
         printf("%f\n",p.y);
      }
   }
   fclose(fp);

   return 0;
}

int main(int argc, char **argv)
{
   func(argc, argv);
   
   return 0;
}
