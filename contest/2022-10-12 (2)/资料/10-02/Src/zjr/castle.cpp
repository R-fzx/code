#include<stdio.h>
int n,m,lj[1001][1001],stack[1000001],min[1001];
long long ssum[1001],ans;
bool hash[1001];
int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    int i,j,x,y,z,now,step,sum;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
      scanf("%d%d%d",&x,&y,&z);
      if(lj[x][y]==0||z<lj[x][y])
      {
        lj[x][y]=z;
        lj[y][x]=z;
      }
    }
    for(i=2;i<=n;i++)min[i]=2000000000;
    sum=1;
    step=0;
    stack[1]=1;
    while(step<sum)
    {
      now=stack[++step];
      hash[now]=0;
      for(i=1;i<=n;i++)
      {
        if(lj[now][i]==0)continue;
        if(min[now]+lj[now][i]<min[i])
        {
          min[i]=min[now]+lj[now][i];
          if(hash[i]==0)
          {
            stack[++sum]=i;
            hash[i]=1;
          }
        }
      }
    }
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      {
        if(lj[i][j]==0)continue;
        if(min[i]+lj[i][j]==min[j])ssum[j]++;
      }
    ans=1;
    for(i=2;i<=n;i++)
    {
      ans*=ssum[i];
      if(ans>2147483647)ans%=2147483647;
    }
    printf("%I64d\n",ans);
}
