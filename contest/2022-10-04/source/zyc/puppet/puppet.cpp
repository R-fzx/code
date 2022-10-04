#include <iostream>
#include <algorithm>
using namespace std;
const int kMaxN=51;
const int kMaxP=101;
int p[kMaxN],n,tong[kMaxP];
int main()
{
freopen("puppet.in","r",stdin);
freopen("puppet.out","w",stdout);
while(cin>>n)
{
  for(int i=0;i<=100;i++)tong[i]=0;
  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
    tong[p[i]]++;
  }
  sort(p+1,p+n+1);
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(!tong[p[i]+1]&&!tong[p[i]]&&!tong[p[i]-1])ans++;
    else if(tong[p[i]+1])tong[p[i]+1]--;
    else if(tong[p[i]])tong[p[i]]--;
    else tong[p[i]-1]--;
  }
  cout<<ans<<"\n";
}
return 0;
}