#include <stdio.h>
#include <math.h>
#define MAX 200010
#define oo 1000000000
struct stu
{
     double x,y;       
}a[MAX],p[MAX],merge[MAX];
void swap(long i,long j)
{
     struct stu temp;
     temp=a[i];a[i]=a[j];a[j]=temp;     
}
void quick_sort(long left,long right)
{
     long i,j,mid;
     if(left<=right)
     {
          i=left;
          j=right;
          mid=(i+j)/2;
          while(i<=j)
          {
               while(a[i].x<a[mid].x&&i<=j) i++;
               if(i<=j) {swap(i,mid);mid=i;i++;}
               while(a[j].x>a[mid].x&&i<=j) j--;
               if(i<=j) {swap(j,mid);mid=j;j--;}          
          }              
          quick_sort(left,mid-1);
          quick_sort(mid+1,right);
     }     
}
double get_min(double num1,double num2)
{
     if(num1<num2) 
          return(num1);
     return(num2);       
}
double solve(long left,long right)
{
     double min=oo,s,standard;
     long i,j,mid,top,front,t;
     if(left==right)
        return(oo);
     else if(left<right)
     {
           mid=(left+right)/2;
           s=(a[mid].x+a[mid+1].x)/2.0;
           min=get_min(solve(left,mid),solve(mid+1,right));
           for(i=left,j=mid+1,top=1,front=0;i<=mid;i++)
              if(s-a[i].x<min)
              {
                   while(j<=right)
                   {
                        if(a[j].x-s<min)
                           p[++front]=a[j];
                        j++;    
                        if(a[j].y-a[i].y>min)
                         break;           
                   }
                   while(a[i].y-p[top].y>=min&&top<=front)  top++;
                   for(t=top;t<=front;t++)
                      min=get_min(min,(p[t].x-a[i].x)*(p[t].x-a[i].x)+(p[t].y-a[i].y)*(p[t].y-a[i].y));                  
              }        
           //merge sort
           for(t=i=left,j=mid+1;i<=mid&&j<=right;t++)
           {
                if(a[i].y<a[j].y)
                   merge[t]=a[i++];
                else
                   merge[t]=a[j++];                                          
           }
           if(i==mid+1)
              for(;j<=right;j++,t++)
                merge[t]=a[j];
           if(j==right+1)
              for(;i<=mid;i++,t++)
                merge[t]=a[i];
           for(i=left;i<=right;i++)
              a[i]=merge[i];
           return(min);
     }       
}
main()
{
      long n,i,j;
      FILE *fp,*fo;
      fp=fopen("dark.in","r");
      fo=fopen("dark.out","w");
      fscanf(fp,"%ld",&n);
      for(i=1;i<=n;i++)
         fscanf(fp,"%lf%lf",&a[i].x,&a[i].y);
      quick_sort(1,n);
      fprintf(fo,"%.2lf",sqrt(solve(1,n))/2.0);
      fclose(fp);
      fclose(fo);
}
