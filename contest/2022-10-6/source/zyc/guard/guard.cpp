#include <iostream>
#include <iomanip>
#include <cstring>
#define double long double
using namespace std;
const int kMaxN=201;
int n,l,k,a[kMaxN];
double p[kMaxN],dp[kMaxN][kMaxN][kMaxN*2],ans;
int main()
{
freopen("guard.in","r",stdin);
freopen("guard.out","w",stdout);
cin>>n>>l>>k;
for(int i=1;i<=n;i++)
{
  int x;
  cin>>x;
  p[i]=x/100.0;
}
for(int i=1;i<=n;i++)cin>>a[i];
dp[0][0][min(k,200)+200]=1.0;
for(int i=0;i<n;i++)
{
  for(int j=0;j<=i;j++)
  {
    for(int k=0;k<=400;k++)
    {
      dp[i+1][j][k]+=dp[i][j][k]*(1-p[i+1]);
      dp[i+1][j+1][min(k+a[i+1],400)]+=dp[i][j][k]*p[i+1];
    }
  }
}
for(int i=l;i<=n;i++)
{
  for(int j=200;j<=400;j++)
  {
    ans+=dp[n][i][j];
  }
}
cout<<fixed<<setprecision(6)<<ans<<"\n";
return 0;
}