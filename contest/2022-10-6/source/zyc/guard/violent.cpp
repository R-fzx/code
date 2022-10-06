#include <iostream>
#include <iomanip>
#define double long double
using namespace std;
const int kMaxN=201;
double p[kMaxN],ans;
int n,a[kMaxN],l,k;
void Dfs(int now,int win,int v,double pro)
{
  if(now==n)
  {
    if(win>=l&&v>=0)
    {
      ans+=pro;
    }
    return;
  }
  Dfs(now+1,win+1,v+a[now+1],pro*p[now+1]);
  Dfs(now+1,win,v,pro*(1-p[now+1]));
}
int main()
{
freopen("guard.in","r",stdin);
freopen("violent.out","w",stdout);
while(cin>>n>>l>>k)
{
ans=0.0;
for(int i=1;i<=n;i++)
{
  int x;
  cin>>x;
  p[i]=x/100.0;
}
for(int i=1;i<=n;i++)cin>>a[i];
Dfs(0,0,k,1.0);
cout<<fixed<<setprecision(6)<<ans<<"\n";
}
return 0;
}