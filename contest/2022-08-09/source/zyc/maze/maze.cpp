#include <iostream>
#include <unordered_map>
using namespace std;
const int kMaxN=21;
int mp[kMaxN][kMaxN];
unordered_map<int,long long>dp[kMaxN][kMaxN];
int n,m,goal;
long long ans;
int main()
{
freopen("maze.in","r",stdin);
freopen("maze.out","w",stdout);
cin>>n>>m>>goal;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    cin>>mp[i][j];
  }
}
dp[1][1][mp[1][1]]=1;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    for(unordered_map<int,long long>::iterator it=dp[i][j].begin();it!=dp[i][j].end();it++)
    {
      if(i+1<=n)
      {
        dp[i+1][j][(it->first)^mp[i+1][j]]+=it->second;
      }
      if(j+1<=m)
      {
        dp[i][j+1][(it->first)^mp[i][j+1]]+=it->second;
      }
    }
  }
}
cout<<dp[n][m][goal];
return 0;
}