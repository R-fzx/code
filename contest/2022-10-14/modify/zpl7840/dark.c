#include <stdio.h>
#include <math.h>

#define oo 2000000000
#define MIN(a,b) ((a)<(b)?(a):(b)) 

long long min=oo;
long hash[200005]={0};

struct case1
{
 long x,y;
 long num;
}a1[200005]={{0,0,0}},b[200005]={{0,0,0}},dui[200205]={{0,0,0}};

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

long long deal(struct case1 dui[],long x)
{
 long i,j;
 long long min2=oo;
 
 for(i=1;i<x;i++)
   for(j=i+1;j<=x;j++)
     if((long long)(dui[i].x-dui[j].x)*(long long)(dui[i].x-dui[j].x)+(long long)(dui[i].y-dui[j].y)*(long long)(dui[i].y-dui[j].y)<min2)
      min2=(long long)(dui[i].x-dui[j].x)*(long long)(dui[i].x-dui[j].x)+(long long)(dui[i].y-dui[j].y)*(long long)(dui[i].y-dui[j].y);
 
 return min2;
}

long long dg(long x,long y)
{
 struct case1 tmp;
 long i,o=0,closed=0,open=0,j,pp;
 long long min3=oo,min4=oo,min2=oo,u;
 double t;

 if(y-x<20)
  {
   for(i=x;i<=y;i++)
     dui[++o]=a1[i];
   for(i=x;i<y;i++)
     for(j=i+1;j<=y;j++)
       {
        if(a1[i].y>a1[j].y)
         {
          tmp=a1[i];
          a1[i]=a1[j];
          a1[j]=tmp;
         }
       }
   
   return deal(dui,y-x+1);
  }
 else
  {
   t=(double)(a1[(x+y)/2].x+a1[(x+y)/2+1].x)/2.0;
   min3=dg(x,(x+y)/2);
   min4=dg((x+y)/2+1,y);
   min2=MIN(min3,min4);
   u=sqrt((double)min2);
   
   for(i=x,pp=(x+y)/2+1;i<=(x+y)/2;i++)
     {
      if(a1[i].x+u<t)
       continue;
      
      for(;a1[i].y-u>=a1[pp].y;pp++);
      j=pp;
      for(;j<=y&&a1[j].y<a1[i].y+u;j++)
        if((long long)(a1[i].x-a1[j].x)*(long long)(a1[i].x-a1[j].x)+(long long)(a1[i].y-a1[j].y)*(long long)(a1[i].y-a1[j].y)<min2)
         min2=(long long)(a1[i].x-a1[j].x)*(long long)(a1[i].x-a1[j].x)+(long long)(a1[i].y-a1[j].y)*(long long)(a1[i].y-a1[j].y);
     }
   
   for(o=x,i=x,j=(x+y)/2+1;i<=(x+y)/2||j<=y;)
     {
      if(i>(x+y)/2)
       b[o++]=a1[j++];
      else if(j>y)
       b[o++]=a1[i++];
      else if(a1[i].y<a1[j].y)
       b[o++]=a1[i++];
      else
       b[o++]=a1[j++];
     }
   for(o=x;o<=y;o++)
     a1[o]=b[o];
   return min2;
  }
}

int main()
{
 FILE *fp,*fo;
 
 long n,i,j;
 long long x,y,min2=oo;
 
 fp=fopen("dark.in","r");
 fo=fopen("dark.out","w");
 
 fscanf(fp,"%ld",&n);
 
 for(i=1;i<=n;i++)
   {
    fscanf(fp,"%ld%ld",&x,&y);
    a1[i].x=x;
    a1[i].y=y;
    a1[i].num=i;
   }
 
 quicksort1(1,n);

 min2=dg(1,n);
 
 fprintf(fo,"%.2lf",sqrt((double)min2)/2.0);
 
 fclose(fp);
 fclose(fo);
 return 0;
} 
