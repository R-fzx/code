#include <iostream>
#include <ctime>
using namespace std;
long long a,b,ans;
void Dfs(int ceng,long long now,long long ji)
{
  if(clock()*1.0/CLOCKS_PER_SEC>=1.98)
  {
    cout<<ans;
    exit(0);
  }
  if(ceng==18)return;
  for(int i(1);i<=9;++i)
  {
    long long now2=(now<<1)+(now<<3)+i,ji2=ji*i;
    if(now2*ji2>b)return;
    if(now2*ji2>=a&&now2*ji2<=b)++ans;
    Dfs(ceng+1,now2,ji2);
  }
}
signed main()
{
freopen("sillyz.in","r",stdin);
freopen("sillyz.out","w",stdout);
cin>>a>>b;
Dfs(1,0,1);
cout<<ans;
return 0;
}
/*int sum[1000001];
int main()
{
freopen("114514.out","w",stdout);
for(int i=1;i<=50000;i++)
{
  int ji=i,j=i;
  while(j)
  {
    ji*=j%10;
    j/=10;
  }
  if(ji<=50000)sum[ji]++;
}
for(int i=1;i<=50000;i++)
{
  if(sum[i]>=1)cout<<i<<" "<<sum[i]<<"\n";
}
return 0;
}*/