#include<stdio.h>
long n,a[100050];
typedef unsigned long long data;
data cost;
int main()
{
   FILE *in,*out;
   in=fopen("bus.in","r");
   out=fopen("bus.out","w");
   fscanf (in,"%ld",&n);
   long i,j,coin;
   for (i=0;i<n;i++)
   fscanf (in,"%ld",&a[i]);
   i=0;
   
   while (i<n)
   {
     for (j=i+1;j<=n;j++)
     if (a[j]<=a[i])
     break;
     coin=j-i;
     cost+=coin*a[i];
     i=j;
   }
   fprintf (out,"%I64d\n",cost);
   fclose(in);
   fclose(out);
   return 0;
}
