#include<stdio.h>
long f[201][2001],v[201][201];
void count(long x,long lena,long lenb)
{
    long i,j,k,m;
    if(lena>lenb)
        m=lena;
    else
        m=lenb;
    for(i=1;i<=m;i++)
    {
        f[x][i]+=f[x-1][i]+f[x-2][i];
        f[x][i+1]+=f[x][i]/10;
        f[x][i]%=10;
    }
    if(f[x][m+1]>0)
        m++;
    for(i=1;i<=m;i++)
        f[x][i]*=x-1;
    for(i=1;i<=m-1;i++)
    {
        f[x][i+1]+=f[x][i]/10;
        f[x][i]%=10;
    }
    while(f[x][m]>=10)
    {
        f[x][m+1]+=f[x][m]/10;
        f[x][m]%=10;
        m++;
    }
    f[x][0]=m;
    return;
} 
int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    long i,j,k,n;
    scanf("%d",&n);
    f[1][1]=0;f[2][1]=1;
    f[1][0]=1;f[2][0]=1;
    for(i=3;i<=n;i++)
        count(i,f[i-1][0],f[i-2][0]);
    for(i=f[n][0];i>=1;i--)
        printf("%d",f[n][i]);
    printf("\n");
    return 0; 
}
