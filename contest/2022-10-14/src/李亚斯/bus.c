#include <stdio.h>
FILE *p,*q;
void opened();
void closed();
int main()
{
    int i,n;
    double min=100000000,s=0,a;
    opened();
    fscanf(p,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(p,"%lf",&a);
        if(a<min)
            min=a;
        s+=min;
    }
    fprintf(q,"%.0lf\n",s);
    closed();
    return(0);
}
void opened()
{
    p=fopen("bus.in","r");
    q=fopen("bus.out","w");
}
void closed()
{
    fclose(p);
    fclose(q);
}
