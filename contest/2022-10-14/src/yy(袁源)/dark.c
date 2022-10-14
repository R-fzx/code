#include <stdio.h>
#include <math.h>
#define oo 2000000000000.0
long n;
double ans=oo;
struct yy
{
double x,y;
}d[200000]={0};

double min(double a,double b)
{
 if (a>b) return b;
 else return a;
}

void quicksort(long s,long t)
{
     double xx;
     struct yy c;
     long i,j,k;
     k=(s+t)/2;
     c=d[k];d[k]=d[s];d[s]=c;
     xx=d[s].x;
     i=s;
     j=t;
     do
     {
      while (i<j&&d[j].x>=xx) j--;
      if (i<j) {c=d[i];d[i]=d[j];d[j]=c;}
      while (i<j&&d[i].x<xx) i++;
      if (i<j) {c=d[i];d[i]=d[j];d[j]=c;}
     }while (i<j);
     i++;
     j--;
     if (s<j) quicksort(s,j);
     if (i<t) quicksort(i,t);
}
int main()
{
    FILE *fi,*fo;
    fi=fopen("dark.in","r");
    fo=fopen("dark.out","w");
    long i,j;
    fscanf(fi,"%ld",&n);
    for (i=1;i<=n;i++)
        {
         fscanf(fi,"%lf%lf",&d[i].x,&d[i].y);
        }
    quicksort(1,n);
    for (i=1;i<=n;i++)
        for (j=1;j<i;j++)
        {
         ans=min(ans,sqrt((d[i].x-d[j].x)*(d[i].x-d[j].x)+(d[j].y-d[i].y)*(d[j].y-d[i].y)));
         if (ans==0) goto here;
        }
   here: fprintf(fo,"%.2lf\n",ans/2);
    fclose(fi);
    fclose(fo);
    return 0;
}
