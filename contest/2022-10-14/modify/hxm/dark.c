#include <stdio.h>
#include <math.h>
struct point 
{
       long long x,y;
}a[200000]={0};
void sort(int l,int r)
{
     if(l<r)
     {
            int i,j,t;
            struct point q;
            t=(r-l)*0.618+l;
            q=a[t];
            a[t]=a[l];
            i=l,j=r;
            while(i<j)
            {
                 while(i<j && q.x<a[j].x) j--;
                 if(i<j)  a[i++]=a[j];
                 while(i<j && q.x>a[i].x) i++;
                 if(i<j)  a[j--]=a[i];
            }
            a[i]=q;
            sort(l,i-1);
            sort(i+1,r);
     }
}
int main()
{
    FILE *fr,*fw;
    int i,n,j;
    long long min;
    min=4000000000000;
    fr=fopen("dark.in","r");
    fw=fopen("dark.out","w");
    fscanf(fr,"%d",&n);
    for(i=0;i<n;i++)
       fscanf(fr,"%I64d%I64d",&a[i].x,&a[i].y);
    sort(0,n-1);
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
         if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y) < min)
            min = (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
         else if((a[i].x-a[j].x)*(a[i].x-a[j].x)>min)
            break;
    fprintf(fw,"%.2lf",sqrt((double)min)/2.0);
    fclose(fr);
    fclose(fw);
    return 0;
}
