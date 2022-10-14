#include <stdio.h>
#define MAX 100050
double a[MAX]={0};
main()
{
     long n,i,k;
     double min,total=0;
     FILE *fp,*fo;
     fp=fopen("bus.in","r");
     fo=fopen("bus.out","w");
     fscanf(fp,"%ld",&n);
     for(i=1;i<=n;i++)
       fscanf(fp,"%lf",&a[i]);
     k=1;
     min=a[1]; 
     for(i=2;i<=n+1;i++)
       if(a[i]<min)
       {
           total+=min*(double)(i-k);
           k=i; 
           min=a[i];           
       }
     fprintf(fo,"%.0lf",total);
     fclose(fp);
     fclose(fo);     
}
