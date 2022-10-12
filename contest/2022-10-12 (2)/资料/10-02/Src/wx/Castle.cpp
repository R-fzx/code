#include<stdio.h>
#include<stdlib.h>
int max(int x,int y)
{
    if(x>y)return x;
    return y;
}
int b[1002],v[1002],f[1002][1002],ge[1002],G[1002][1002];
int n,m;
long long dis[1002],oo=1,ans=1;
void spfa(int s)
{
     int i=0,j=1,k;
     for(k=2;k<=n;k++)
     dis[k]=oo;
     b[1]=1;
     while(i!=j)
     {
      i=(i+1)%(n+1);
      v[b[i]]=0;
      for(k=1;k<=ge[b[i]];k++)
      if(dis[b[i]]+G[b[i]][f[b[i]][k]]<dis[ f[b[i]][k] ])
      {
       dis[ f[b[i]][k] ]=dis[b[i]]+G[b[i]][f[b[i]][k]];
       if(!v[ f[b[i]][k] ])
       {
        v[ f[b[i]][k] ]=1;
        j=(j+1)%(n+1);
        b[j]=f[b[i]][k];
       }
      }
     }
}
int main()
{
    int i,j,k,w;
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
     scanf("%d%d%d",&j,&k,&w);
     if(j==k)continue;
                    if(G[j][k]==0)
                    {
                     f[j][++ge[j]]=k;
                     f[k][++ge[k]]=j;
                    }
                    if(G[j][k]==0||G[j][k]>w)
                    G[j][k]=G[k][j]=w;
    }
    for(i=1;i<=55;i++)
    oo*=2;
    long long mod=1;
    for(i=1;i<=31;i++)
    mod*=2;
    mod--;
    spfa(1);
    for(i=2;i<=n;i++)
    {
     int tmp=0;
     for(j=1;j<=ge[i];j++)
     if(dis[i]==G[i][f[i][j]]+dis[ f[i][j] ])
     tmp++;
     ans=ans*tmp%mod;
    }
    printf("%I64d",ans);
    return 0;
}
