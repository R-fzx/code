#include <stdio.h>
#define oo 200000000000.0
double bus[100010]={0},minnow=oo,ans=0;
long n;

int main()
{
    FILE *fi,*fo;
    long i;
    fi=fopen("bus.in","r");
    fo=fopen("bus.out","w");
    
    fscanf(fi,"%ld",&n);
    for (i=1;i<=n;i++)
        {
         fscanf(fi,"%lf",&bus[i]);
        }
    for (i=1;i<=n;i++)
        {
         if (minnow>bus[i]) minnow=bus[i];
         ans+=minnow;
        }
    fprintf(fo,"%.0lf\n",ans);
    fclose(fi);
    fclose(fo);
    return 0;
}
