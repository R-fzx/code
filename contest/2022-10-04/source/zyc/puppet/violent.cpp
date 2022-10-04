#include <iostream>
using namespace std;
const int kMaxN=51;
int n,p[kMaxN],ans,r[kMaxN],match[kMaxN],cop[kMaxN];
bool vis[kMaxN];
void Dfs(int x,int no)
{
  if(x==n+1)
  {
    //cout<<no<<"\n";
    ans=max(ans,no);
    if(no==2)
    {
      for(int i=1;i<=n;i++)
      {
        cop[i]=match[i];
      }
    }
    return;
  }
  bool flag=false;
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    if(abs(r[i]-p[x])<=1)
    {
      //cout<<x<<" "<<i<<"\n";
      flag=true;
      vis[i]=true;
      match[x]=r[i];
      Dfs(x+1,no);
      vis[i]=false;
      match[x]=0;
    }
  }
  if(!flag)
  {
    Dfs(x+1,no+1);
  }
}
int main()
{
freopen("puppet.in","r",stdin);
freopen("violent.out","w",stdout);
while(cin>>n)
{
  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
    r[i]=p[i];
  }
  ans=0;
  Dfs(1,0);
  cout<<ans<<"\n";
  for(int i=1;i<=n;i++)
  {
    cout<<i<<" "<<p[i]<<" "<<cop[i]<<"\n";
  }
}
return 0;
}