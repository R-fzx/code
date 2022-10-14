#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *in,*out;
int n;
int a[200200][2]={0};

int main()
{
     in=fopen("dark.in","r");
     out=fopen("dark.out","w");
     int i,j,k;
     fscanf(in,"%d",&n);
     for(i=1;i<=n;i++)
         fscanf(in,"%d%d",&a[i][0],&a[i][1]);
     double min=214000000,temp,t1,t2;
     for(i=1;i<=n;i++)
         for(j=1;j<i;j++)
         {
             t1=(a[i][0]-a[j][0]);t1*=t1;
             t2=(a[i][1]-a[j][1]);t2*=t2;
             temp=t1+t2;
             if(min>temp)  
                 min=temp;
         }
     fprintf(out,"%.2lf\n",min);
     return 0;
}
