#include <iostream>
#include <map>
using namespace std;
const int kMaxN=13;
char mp[kMaxN][kMaxN];
int n,m,base[kMaxN],now,last;
map<int,long long>dp[2];
signed main()
{
cin>>n>>m;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    cin>>mp[i][j];
  }
}
base[0]=1;
for(int i=2;i<=12;i++)base[i]=base[i-1]<<2;
dp[now][1]=1;
for(int i=1;i<=n;i++)
{
  for(map<int,long long>::iterator it=dp[now].begin();it!=dp[now].end();it++)
  {
    int x=it->first;
    long long y=it->second;
    dp[now][x<<2]=y;
    dp[now].erase(it);
  }
  for(int j=1;j<=m;j++)
  {
    swap(now,last);
    dp[now].clear();
    for(map<int,long long>::iterator it=dp[last].begin();it!=dp[now].end();it++)
    {
      int zt=it->first,leftzt=(zt>>((j-1)<<1))%4,topzt=(zt>>(j<<1))%4;
      long long lastans=it->second;
      if(mp[i][j]=='*')
      {
        if(!leftzt&&!topzt)dp[now][zt]=lastans;
      }
      else if(!leftzt&!topzt)
      {
        if(mp[i+1][j]=='.'&&mp[i][j+1]=='.')
        {
          dp[now][zt+base[j-1]+2*base[j]]=lastans;
        }
      }
      else if(!leftzt&&topzt)
      {
        if(mp[i+1][j]=='.')
        {
          dp[now][zt-base[j]*topzt+base[j-1]*topzt]=lastans;
        }
      }
    }
  }
}
return 0;
}