#include <iostream>
using namespace std;
const int kMaxN=5e5+1;
int n,a[kMaxN],ans;
int main()
{
freopen("snowman.in","r",stdin);
freopen("snowman.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
  cin>>a[i];
}
for(int i=1;i<=n;i++)
{
  for(int j=i+1;j<=n;j++)
  {
    if(j-i<=ans)continue;
    int x=i,y=j,len=0;
    while(a[y]-a[x]==a[j]-a[i])
    {
      len++;
      x++,y++;
      if(x>n||y>n)break;
    }
    //cout<<i<<" "<<j<<" "<<len<<"\n";
    x--,y--;
    ans=max(ans,min(j-i,len));
  }
}
cout<<ans;
return 0;
}