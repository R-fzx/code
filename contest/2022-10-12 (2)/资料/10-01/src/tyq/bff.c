#include<stdio.h>
#include<stdlib.h>
int n,b[10001],g[101][101],sum;
int dfs(int m)
{
    int i;
    if(m>=n)
    {
     sum++;
    }
    else
    for(i=0;i<n;i++)
    if(!b[i]&&!g[m][i])
    {
     b[i]=1;
     dfs(m+1);
     b[i]=0;
    }
}
int main()
{
    int i,j;
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
      scanf("%d",&g[i][j]);
    dfs(0);
    printf("%d\n",sum);
    return 0;
} 
