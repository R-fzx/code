#include <stdio.h>
#include <math.h>
FILE *p,*q;
void opened();
void closed();
double x[200052]={0},y[200052]={0},min=2000000000,s;
int main()
{
    int n;
    int i,j;
    opened();
    fscanf(p,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(p,"%d%d",&x[i],&y[i]);
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            s=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            s=sqrt(s);
            if(min>s)
                min=s;
            if(min==0)
                goto lop;
        }
    lop:
    fprintf(q,"%.2lf\n",min);
    closed();
    return(0);
}
void opened()
{
    p=fopen("dark.in","r");
    q=fopen("dark.out","w");
}
void closed()
{
    fclose(p);
    fclose(q);
}
