#include <stdio.h>
#include <math.h>
#define MAX 200005
double x[MAX]={0},y[MAX]={0};
main()
{
     long n,i,j;
     double min=1000000000,t;
     FILE *fp,*fo;
     fp=fopen("dark.in","r");
     fo=fopen("dark.out","w");
     fscanf(fp,"%ld",&n);
     for(i=1;i<=n;i++)
       fscanf(fp,"%lf%lf",&x[i],&y[i]);
     for(i=1;i<=n;i++)
       for(j=i+1;j<=n;j++)
       {
           t=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
           if(t<min)
             min=t;
       }
     fprintf(fo,"%.2lf",min/2.0);
     fclose(fp);
     fclose(fo);
}
