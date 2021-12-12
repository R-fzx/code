#include <iostream>
#define int long long
using namespace std;
const int kMaxN=1e5+1;
struct EDGE
{
  int _x1,_y1,_x2,_y2;
}e[kMaxN];
int n;
int du[kMaxN],maxa;
bool Check(EDGE i,EDGE j)
{
  if(i._x1>j._x1)swap(i,j);
  if(i._x2>=j._x1)
  {
    if(i._y1>i._y2)
    {
      swap(i._y1,i._y2);
      swap(i._x1,i._x2);
    }
    if(i._y1<=j._y1&&i._y2>=j._y1)return true;
    if(i._y1<=j._y2&&i._y2>=j._y2)return true;
    return false;
  }
  return false;
}
signed main()
{
freopen("cowjump.in","r",stdin);
freopen("cowjump.out","w",stdout);
scanf("%lld",&n);
for(int i(1);i<=n;++i)
{
  scanf("%lld%lld%lld%lld",&e[i]._x1,&e[i]._y1,&e[i]._x2,&e[i]._y2);
  if(e[i]._x1>e[i]._x2)
  {
    swap(e[i]._x1,e[i]._x2);
    swap(e[i]._y1,e[i]._y2);
  }
}
for(int i(1);i<=n;++i)
{
  for(int j(i+1);j<=n;++j)
  {
    if(Check(e[i],e[j]))
    {
      //cout<<i<<" "<<j<<"\n";
      du[i]++;
      du[j]++;
    }
  }
}
for(int i(1);i<=n;i++)
{
  maxa=max(maxa,du[i]);
}
for(int i(1);i<=n;i++)
{
  if(du[i]==maxa)
  {
    printf("%lld",i);
    return 0;
  }
}
return 0;
}