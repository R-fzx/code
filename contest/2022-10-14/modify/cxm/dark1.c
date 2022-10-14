#include<stdio.h>
#include<math.h>
#define sq(a) (a)*(a)
FILE *fp,*fo;
long n,m,i,j;
double k,x[200000],y[200000];
int main()
{
 fp=fopen("dark.in","r");
 fo=fopen("dark1.out","w");
 fscanf(fp,"%ld",&n);
 k=2147483647;
 for(i=1;i<=n;i++)
   {
    fscanf(fp,"%lf%lf",&x[i],&y[i]);
    for(j=1;j<i;j++)
      if(sq(k)>sq(x[i]-x[j])+sq(y[i]-y[j]))
        k=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));               
   }
 fprintf(fo,"%.2lf",k/2.0);
 fclose(fp);fclose(fo);
 return(0);    
}
