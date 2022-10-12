#include<stdio.h>
#include<stdlib.h>
long long  n,f[1001],g[1001];

int main()
{
    int i,j,ber;
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    scanf("%I64d",&n);
    f[2]=1;
    g[2]=1;
    f[3]=2;
    g[3]=3;
    for(i=4;i<=n;i++)
    {
     f[i]=(i-1)*f[i-2]+(i-1)*(i-2)*g[i-2];
     g[i]=f[i-1]+g[i-1]*(i-1);
    }
    printf("%I64d\n",f[n]);
    return 0;
}
