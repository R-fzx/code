#include<stdio.h>
#include<stdlib.h>
FILE *in,*out;
int n,a[100100];
int main()
{
     in=fopen("bus.in","r");
     out=fopen("bus.out","w");
     int i,j,k;
     double count=0,temp;
     fscanf(in,"%d",&n);
     for(i=1;i<=n;i++)
         fscanf(in,"%d",&a[i]);
     for(i=1;i<=n;)
     {
         for(j=i+1;j<=n;j++)
             if(a[j]<a[i])
                 break;
         temp=a[i];
         temp*=(j-i);
         count+=temp;
         i=j;
     }
     fprintf(out,"%.0lf\n",count);
     return 0;
}
