#include <iostream>
#include <iomanip>
using namespace std;
const int kMaxN=301;
int h[kMaxN],n,ci;
int person[kMaxN];
long long ans;
bool vis[kMaxN];
void Dfs(int num)
{
  if(num==n)
  {
    ci++;
    for(int i=1;i<=n;i++)
    {
      for(int j=i-1;j>=0;j--)
      {
        if(person[j]>person[i])
        {
          ans+=i-j;
          break;
        }
      }
    }
    return;
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i])continue;
    vis[i]=true;
    person[num+1]=h[i];
    Dfs(num+1);
    vis[i]=false;
  }
}
int main()
{
freopen("queue.in","r",stdin);
freopen("queue.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)cin>>h[i];
person[0]=1e9;
Dfs(0);
double out=ans*1.0/ci;
cout<<fixed<<setprecision(2)<<out;
return 0;
}