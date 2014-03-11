#include <stdio.h>



void read_example()
{
   int x,y;
   printf("ENTER FIRST INTEGER:");
   int a = scanf("%d",&x);  
   if(a!=1)
   {
      printf("INVALID INPUT");
   }
   else
   { 
      printf("ENTER SECOND INTEGER:");
      int b = scanf("%d",&y);
   
      if(x>y&&b==1)
      {
         printf("%d\n",x);
      }   
      else if (y>x&&b==1)
      {
         printf("%d\n",y);
      }
      else
      {
         printf("INVALID INPUT\n");
      }        
   }   
   
   double o,p;
   printf("ENTER FIRST DOUBLE:");
   int j = scanf("%lf",&o);  
   if(j!=1)
   {
      printf("INVALID INPUT");
   }
   else
   { 
      printf("ENTER SECOND DOUBLE:");
      int k = scanf("%lf",&p);
   
      if(o>p&&k==1)
      {
         printf("%lf\n",o);
      }   
      else if (p>o&&k==1)
      {
         printf("%lf\n",p);
      }
      else
      {
         printf("INVALID INPUT");
      }        
   }   

  
} 
 

 

int main()
{
   read_example();
   return 0;
}
