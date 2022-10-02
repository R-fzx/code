#include <iostream>
#include <algorithm>
using namespace std;
const int kMaxN=501;
int l[kMaxN][kMaxN],r[kMaxN][kMaxN],n,cnt;
long long sum,ans;
struct POINT
{
  int x,y,many;
}p[kMaxN*kMaxN];
bool cmp(POINT i,POINT j)
{
  return i.many>j.many;
}
int main()
{
freopen("garland.in","r",stdin);
freopen("garland.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
    int num;
    cin>>num;
    p[++cnt].many=num;
    p[cnt].x=i,p[cnt].y=j;
  }
}
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
    cin>>l[i][j];
    sum+=l[i][j]*1ll;
  }
}
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=n;j++)
  {
    cin>>r[i][j];
  }
}
sum=-sum;
sort(p+1,p+cnt+1,cmp);
for(int i=1;i<=cnt;i++)
{
  int xx=p[i].x,yy=p[i].y;
  int cha=r[xx][yy]-l[xx][yy];
  long long jia=min(cha*1ll,sum);
  l[xx][yy]+=jia;
  sum-=jia;
  ans+=p[i].many*1ll*l[xx][yy];
}
cout<<ans;
return 0;
}