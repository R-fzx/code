#include <stdio.h>
#include <math.h>
double x[200000]={0},y[200000]={0};
int main()
{
    FILE *fr,*fw;
    int i,n,j;
    double min;
    min=4000000000000;
    fr=fopen("dark.in","r");
    fw=fopen("dark.out","w");
    fscanf(fr,"%d",&n);
    for(i=0;i<n;i++)
       fscanf(fr,"%lf%lf",x+i,y+i);
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
         if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) < min)
            min = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    fprintf(fw,"%.2lf",sqrt(min)/2.0);
    fclose(fr);
    fclose(fw);
    return 0;
}
