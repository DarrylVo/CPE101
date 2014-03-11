#include <stdio.h>
void print_all(int argc, char *argv[])
{
   int i;
  
   for(i=0;i<argc;i++)
   {
      printf("%s\n",argv[i]);

   }


}

int main(int argc, char *argv[])
{
   print_all(argc, argv); 

}
