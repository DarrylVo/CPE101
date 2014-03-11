#include "puzzlesolve.h"
#include <stdio.h>
#include <stdlib.h>

FILE* open_file(char **argv)
{
   FILE* fp;
   fp=fopen(argv[1],"r");
   if(fp==NULL)
   {
      printf("cant open target file\n");
      exit(1);
   }
   else
   {
      return fp;
   }
}

FILE* create_file()
{
   FILE* fp;
   fp=fopen("hidden.ppm","w");
   return fp;

}

void header_print(FILE* fp, FILE* fp2)
{
   int w,h,m;
   char s;
   fscanf(fp,"%s %d %d %d",&s,&w,&h,&m);
   fprintf(fp2,"%s\n%d %d\n%d\n","P3",w,h,m);
   

}

void scan_print(FILE* fp, FILE* fp2)
{
   int r,g,b;
   while(fscanf(fp,"%d",&r)!=EOF)
   {
      r=r*10;
      if(r>255)
      {
         r=255;
      }
      
      fscanf(fp,"%d",&g);
      fscanf(fp,"%d",&b);
      g=r;
      b=r;
      fprintf(fp2,"%d\n%d\n%d\n",r,g,b);
   }


}

void decode_image(char **argv)
{
   FILE* fp=open_file(argv);
   FILE* fp2=create_file();
   header_print(fp,fp2);
   scan_print(fp,fp2);
   fclose(fp2); 


}
