#include <iostream>
using namespace std;
const int kMaxN=2e5+1;
const int kMaxM=2e5+1;
struct EDGE
{
  int to,nt;
}e[kMaxM*2];
int hd[kMaxN],cnt;
int dp[kMaxN],in[kMaxN];
int n,m,ans;
void Add(int a,int b)
{
  e[++cnt].to=b;
  e[cnt].nt=hd[a];
  hd[a]=cnt;
}
int Dfs(int now)
{
  if(dp[now])return dp[now];
  bool flag=false;
  for(int i=hd[now];i;i=e[i].nt)
  {
    if(i)flag=true;
    dp[now]+=Dfs(e[i].to);
  }
  if(!flag)dp[now]=1;
  return dp[now];
}
int main()
{
freopen("lyx.in","r",stdin);
freopen("lyx.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=m;i++)
{
  int a,b;
  cin>>a>>b;
  Add(a,b);
  in[b]++;
}
for(int i=1;i<=n;i++)
{
  if(!in[i])
  {
    Dfs(i);
    ans+=dp[i];
  }
}
cout<<ans;
return 0;
}