#include <stdio.h>
FILE *fp,*fo;
long long a[100010]={0},n,cost=0;
long now=1;
int main()
{
    long i,j;
    fp=fopen("bus.in","r");
    fo=fopen("bus.out","w");
    fscanf(fp,"%I64d",&n);
    for (i=1;i<=n;i++)
      fscanf(fp,"%I64d",&a[i]);
    do
    {
      for (i=now+1;a[i]>a[now];i++);
      cost+=a[now]*(i-now);
      now=i;
    }
    while (now<=n);
    fprintf(fo,"%I64d\n",cost);
    fclose(fp);
    fclose(fo);
    return 0;
}
