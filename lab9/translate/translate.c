#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* input(int argc, char **argv)
{
   FILE *fp;
   fp=fopen(argv[3],"r");
   if(fp==NULL)
   {
      printf("invalid file");
      exit(1);
   }
   else
   {
      return fp;
   }


}

FILE* output(int argc, char **argv)
{
   FILE *fp;
   fp=fopen("translate\0","w");  
   return fp;
}

void translate(int argc, char **argv)
{
   FILE *fp = input(argc,argv);
   

   FILE *fp2 = output(argc,argv);

   char *a = argv[1];
  

   char p;
   while( fscanf(fp,"%c",&p)!=EOF)
   {
      if(*a==p)
      {
         fprintf(fp2,"%s",argv[2]);
      }
      else
      {
         fprintf(fp2,"%c",p);
      }

   }
   

}



int main(int argc, char **argv)
{
   translate(argc,argv);
   return 0;
}
