#include <stdio.h>
#include <math.h>

#define oo 2000000000000

double min=oo;
long hash[200005]={0};

struct case1
{
 double x,y;
 long num;
}a1[200005]={{0,0,0}},a2[200005]={{0,0,0}};

long quick2(long x,long y)
{
 long i,j,l;
 struct case1 tmp;
 
 i=x;
 j=y;
 l=(x+y)/2;
 
 for(;i<=j;)
   {
    for(;a2[i].y<a2[l].y;i++);
    if(i<=j)
     {
      tmp=a2[i];
      a2[i]=a2[l];
      a2[l]=tmp;
      l=i++;
     }
    for(;a2[j].y>a2[l].y;j--);
    if(i<=j)
     {
      tmp=a2[j];
      a2[j]=a2[l];
      a2[l]=tmp;
      l=j--;
     }
   }
 return l;
}

void quicksort2(long x,long y)
{
 long l;
 
 if(x<y)
  {
   l=quick2(x,y);
   quicksort2(x,l-1);
   quicksort2(l+1,y);
  }
}

long quick1(long x,long y)
{
 long i,j,l;
 struct case1 tmp;
 
 i=x;
 j=y;
 l=(x+y)/2;
 
 for(;i<=j;)
   {
    for(;a1[i].x<a1[l].x;i++);
    if(i<=j)
     {
      tmp=a1[i];
      a1[i]=a1[l];
      a1[l]=tmp;
      l=i++;
     }
    for(;a1[j].x>a1[l].x;j--);
    if(i<=j)
     {
      tmp=a1[j];
      a1[j]=a1[l];
      a1[l]=tmp;
      l=j--;
     }
   }
 return l;
}

void quicksort1(long x,long y)
{
 long l;
 
 if(x<y)
  {
   l=quick1(x,y);
   quicksort1(x,l-1);
   quicksort1(l+1,y);
  }
}

int main()
{
 FILE *fp,*fo;
 
 long n,i,j;
 double x,y;
 
 fp=fopen("dark.in","r");
 fo=fopen("dark.out","w");
 
 fscanf(fp,"%ld",&n);
 
 for(i=1;i<=n;i++)
   {
    fscanf(fp,"%lf%lf",&x,&y);
    a1[i].x=x;
    a1[i].y=y;
    a1[i].num=i;
    a2[i].x=x;
    a2[i].y=y;
    a2[i].num=i;
   }
 
 quicksort1(1,n);
 quicksort2(1,n);
 
 for(i=1;i<=n;i++)
   hash[a2[i].num]=i;
 
 for(i=1;i<=n;i++)
   {
    for(j=i+1;(a1[j].x<=a2[hash[a1[i].num]+1].x||a1[j].x<=a2[hash[a1[i].num]-1].x)&&j<=n;j++)
      {
       if((a1[j].x-a1[i].x)*(a1[j].x-a1[i].x)+(a1[j].y-a1[i].y)*(a1[j].y-a1[i].y)<min)
        min=(a1[j].x-a1[i].x)*(a1[j].x-a1[i].x)+(a1[j].y-a1[i].y)*(a1[j].y-a1[i].y);
      }
   }
 
 fprintf(fo,"%.2lf\n",sqrt(min)/2.0);
 
 fclose(fp);
 fclose(fo);
 return 0;
} 
