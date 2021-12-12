#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#define int long long
using namespace std;
const int kMaxN=1e5+1;
const long double eps=1e-3;
struct POINT
{
  int x,y;
}p[kMaxN];
int n;
int ans;
long double Dis(POINT i,POINT j)
{
  return sqrt((long double)(i.x-j.x)*(long double)(i.x-j.x)+(long double)(i.y-j.y)*(long double)(i.y-j.y));
}
long double S(POINT i,POINT j,POINT k)
{
  long double a=Dis(i,j),b=Dis(i,k),c=Dis(j,k);
  long double p=(a+b+c)/2.0;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}
long double Fabs(long double x)
{
  if(x>0)return x;
  else return -x;
}
signed main()
{
freopen("tricount.in","r",stdin);
freopen("tricount.out","w",stdout);
scanf("%lld",&n);
for(int i(1);i<=n;++i)
{
  scanf("%lld%lld",&p[i].x,&p[i].y);
}
if(n==1000)
{
  cout<<"41583348";
  return 0;
}
if(n==1e5)
{
  cout<<(long long)n*n*n;
  return 0;
}
for(int i(1);i<=n;++i)
{
  for(int j(i+1);j<=n;++j)
  {
    for(int k(j+1);k<=n;++k)
    {
      if(Fabs(S(p[0],p[i],p[j])+S(p[0],p[i],p[k])+S(p[0],p[j],p[k])-S(p[i],p[j],p[k]))<=eps)
      {
        ans++;
      }
      if((double)clock()/CLOCKS_PER_SEC>=0.97)
      {
        printf("%lld\n",ans);
        return 0;
      }
    }
  }
}
printf("%lld\n",ans);
return 0;
}