#include<stdio.h>
#include<math.h>
long n;
double x[200050],y[200050];
double dis,min;
int main()
{
    FILE *in,*out;
    in=fopen ("dark.in","r");
    out=fopen ("dark.out","w");
    fscanf (in,"%ld",&n);
    long i,j;
    int pan=0;
    for (i=1;i<=n;i++)
    fscanf (in,"%lf %lf\n",&x[i],&y[i]);
    min=2140000000;
    for (i=1;i<=n&&!pan;i++)
     for (j=i+1;j<=n&&!pan;j++)
     {
        dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        if (min>dis)
        min=dis;
        if (min-0.0000001<=0)
        {pan=1;break;}
     }
    min=min/2.0;
    fprintf (out,"%.2lf\n",min); 
    fclose(in);
    fclose(out);
    return 0;    
}
