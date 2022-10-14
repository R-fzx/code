#include <stdio.h>

#define oo 2000000000

int main()
{
 FILE *fp,*fo;
 
 long n,i,j;
 double a[100008]={0},min=oo,s=0;
 
 fp=fopen("bus.in","r");
 fo=fopen("bus.out","w");
 
 fscanf(fp,"%ld",&n);
 for(i=1;i<=n;i++)
   fscanf(fp,"%lf",&a[i]);
 
 for(i=1;i<=n;i++)
   {
    if(a[i]<min)
     min=a[i];
    else
     a[i]=min;
   }
 
 for(i=1;i<=n;i++)
   s+=a[i];
   
 fprintf(fo,"%.0lf\n",s);
 
 fclose(fp);
 fclose(fo);
 return 0;
}
