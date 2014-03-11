#include "data.h"
#include "vector_math.h"
#include "collisions.h"
#include "cast.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int is_double(char const input[])
{
   double a;
   if(input==NULL)
   {
      return 0;
   }
   else if(sscanf(input,"%lf",&a)==1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

void check_arg(double arg[],char **argv,int argc)
{
   struct point eye;
   int a=0;
   
   double min_x,max_x;
   double min_y,max_y;
   double width,height;
   int b=0;

   struct light light;
   int c=0;
   
   struct color ambient;   
   int d=0;

   int i;
   for(i=2;i<argc;i++)
   {
      if(strcmp(argv[i],"-eye")==0)
      {
         if(is_double(argv[i+1])==1)
         {   
            a=1;      
            eye.x=atof(argv[i+1]);
            if(is_double(argv[i+2])==1)
            {
               eye.y=atof(argv[i+2]);
               if(is_double(argv[i+3])==1)
               {
                  eye.z=atof(argv[i+3]);
               }
               else
               {
                  eye.z=-14;
               }
            }
            else
            {
               eye.y=0;
               eye.z=-14;
            }
         }
         else
         {
            eye=create_point(0,0,-14);
         }  
      }
      else if(strcmp(argv[i],"-view")==0)
      {
         if(is_double(argv[i+1])==1)
         {
            b=1;
            min_x=atof(argv[i+1]);
            if(is_double(argv[i+2])==1)
            {
               max_x=atof(argv[i+2]);
               if(is_double(argv[i+3])==1)
               {
                  min_y=atof(argv[i+3]);
                  if(is_double(argv[i+4])==1)
                  {
                     max_y=atof(argv[i+4]);
                     if(is_double(argv[i+5])==1)
                     {
                        width=atof(argv[i+5]);
                        if(is_double(argv[i+6])==1)
                        {
                           height=atof(argv[i+6]);
                        }
                        else
                        {
                           height=768;
                        }
                     }
                     else
                     {
                        width=1024;
                        height=768;
                     }
                  }
                  else
                  {
                     max_y=7.5;
                     width=1024;
                     height=768;
                  }
               }
               else 
               {
                  min_y=-7.5;
                  max_y=7.5;
                  width=1024;
                  height=768;
               }
            }
            else
            {
               max_x=10;
               min_y=-7.5;
               max_y=7.5;
               width=1024;
               height=768;
            }
         }
         else
         {
            min_x=-10;
            max_x=10;
            min_y=-7.5; 
            max_y=7.5;
            width=1024;
            height=768;
         }
      }
      else if(strcmp(argv[i],"-light")==0)
      {
         if(is_double(argv[i+1])==1)
         {
            c=1;
            light.p.x=atof(argv[i+1]);
            if(is_double(argv[i+2])==1)
            {
               light.p.y=atof(argv[i+2]);
               if(is_double(argv[i+3])==1)
               {
                  light.p.z=atof(argv[i+3]);
                  if(is_double(argv[i+4])==1)
                  {
                     light.color.r=atof(argv[i+4]);
                     if(is_double(argv[i+5])==1)
                     {
                        light.color.g=atof(argv[i+5]);
                        if(is_double(argv[i+6])==1)
                        {
                           light.color.b=atof(argv[i+6]);
                        }
                        else
                        {
                           light.color.b=1.5;                                                                                  
                        }
                     }
                     else
                     {
                        light.color.g=1.5;
                        light.color.b=1.5;                                                         
                     }
                  }
                  else
                  {
                     light.color.r=1.5;
                     light.color.g=1.5;
                     light.color.b=1.5;                                    
                  }
               }
               else 
               {
                  light.p.z=-100;
                  light.color.r=1.5;
                  light.color.g=1.5;
                  light.color.b=1.5;                 
               }
            }
            else
            {
               light.p.y=100;
               light.p.z=-100;
               light.color.r=1.5;
               light.color.g=1.5;
               light.color.b=1.5;
              
            }
         }
         else
         {
            light.p.x=-100;
            light.p.y=100;
            light.p.z=-100;
            light.color.r=1.5;
            light.color.g=1.5;
            light.color.b=1.5;
         }
      }
      else if(strcmp(argv[i],"-ambient")==0)
      {
         if(is_double(argv[i+1])==1)
         {
            d=1;
            ambient.r=atof(argv[i+1]);
            if(is_double(argv[i+2])==1)
            {
               ambient.g=atof(argv[i+2]);
               if(is_double(argv[i+3])==1)
               {
                  ambient.b=atof(argv[i+3]);
               }
               else
               {
                  ambient.b=1.0;
               }
            }
            else
            {
               ambient.g=1.0;
               ambient.b=1.0;
            }
         }
         else
         {
            ambient=create_color(1.0,1.0,1.0);
         }
      }
    


   }
   if(a==0)
   {
      eye=create_point(0,0,-14);
   }
   if(b==0)
   {
      min_x=-10;
      max_x=10;
      min_y=-7.5; 
      max_y=7.5;
      width=1024;
      height=768;
   }
   if(c==0)
   {
      light.p.x=-100;
      light.p.y=100;
      light.p.z=-100;
      light.color.r=1.5;
      light.color.g=1.5;
      light.color.b=1.5;
   }
   if(d==0)
   {
      ambient=create_color(1.0,1.0,1.0);
   }
   arg[0]=eye.x;
   arg[1]=eye.y;
   arg[2]=eye.z;
   arg[3]=min_x;
   arg[4]=max_x;
   arg[5]=min_y;
   arg[6]=max_y;
   arg[7]=width;
   arg[8]=height;
   arg[9]=light.p.x;
   arg[10]=light.p.y;
   arg[11]=light.p.z;
   arg[12]=light.color.r;
   arg[13]=light.color.g;
   arg[14]=light.color.b;
   arg[15]=ambient.r;
   arg[16]=ambient.g;
   arg[17]=ambient.b;
  


}

int scan_file(FILE* fp, struct sphere sphere, struct sphere spheres[])
{
   int counter=0;
   while( (fscanf(fp,"%lf",&sphere.center.x)!=EOF) &&(counter<10000))
   {
      fscanf(fp,"%lf",&sphere.center.y);
      fscanf(fp,"%lf",&sphere.center.z);
      fscanf(fp,"%lf",&sphere.radius);
      fscanf(fp,"%lf",&sphere.color.r);
      fscanf(fp,"%lf",&sphere.color.g);
      fscanf(fp,"%lf",&sphere.color.b);
      fscanf(fp,"%lf",&sphere.finish.ambient);
      fscanf(fp,"%lf",&sphere.finish.diffuse);
      fscanf(fp,"%lf",&sphere.finish.specular);
      fscanf(fp,"%lf",&sphere.finish.roughness);
      spheres[counter]=sphere;
     
      counter++;
   } 
   return counter;

}

FILE* open_file(char **argv)
{
   FILE *fp;
   fp =fopen(argv[1],"r");
   if(fp==NULL)
   {
      printf("cant open target file\n");
      exit(1);
   }  
   else
   {
      printf("opened target file!:D");
      return fp;
   } 
   

}

void cline(int argc, char **argv)
{
   FILE *fp;
   fp=open_file(argv);
   
   struct sphere sphere;
   struct sphere spheres[10000];
   int z =scan_file(fp,sphere,spheres);
   fclose(fp);
   
   double arg[18];
   check_arg(arg,argv, argc);
   struct point eye = create_point(arg[0],arg[1],arg[2]);
   struct color ambient=create_color(arg[15],arg[16],arg[17]);
   struct color lc = create_color(arg[12],arg[13],arg[14]);
   struct point lp = create_point(arg[9],arg[10],arg[11]);
   struct light light = create_light(lp,lc);
   cast_all_rays(arg[3],arg[4],arg[5],arg[6],arg[7],arg[8],eye,spheres,z,ambient,light);   
   
}



