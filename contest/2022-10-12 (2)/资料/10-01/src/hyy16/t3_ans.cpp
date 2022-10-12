#include <stdio.h>
#include <stdlib.h>

unsigned long long n,i,j,ans;
unsigned long long map[205][205],ok[205],f[205];

void dfs(unsigned long long i);

int main()
{
    freopen("t3.in","r",stdin); freopen("t3_ans.out","w",stdout);
    scanf("%I64u",&n);
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       scanf("%I64u",&map[i][j]);
    //dfs(1);
    f[1]=0;
    f[2]=1;
    for(i=3;i<=n;i++)
    f[i]=(i-1)*(f[i-1]+f[i-2]);
    printf("%I64u\n",f[n]);
    return 0;
}

void dfs(unsigned long long i)
{
     unsigned long long x;
     if (i>n)
     {
        ans++;
        return;
     }
     for(x=1;x<=n;x++)
     if (map[i][x]==0 && ok[x]==0)
     {
        ok[x]=1;
        dfs(i+1);
        ok[x]=0;
     }
     return;
}
