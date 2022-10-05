#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
const int kMaxN=801;
const double mintem=1e-10,delta=0.998;
int n;
long long x[kMaxN],y[kMaxN],ans,lastans;
void SA()
{
  double tem=10000;
  while(tem>=mintem)
  {
    int a=(int)(rand()*tem)%n+1,b=(int)(rand()*tem)%n+1;
    long long nowans=lastans-x[a]*y[a]-x[b]*y[b]+x[a]*y[b]+x[b]*y[a],dta=nowans-ans;
    if(nowans<ans)
    {
      ans=nowans;
      lastans=nowans;
      swap(x[a],x[b]);
    }
    else if(exp(-dta*1.0/tem)>rand()*RAND_MAX)
    {
      swap(x[a],x[b]);
      lastans=nowans;
    }
    tem*=delta;
  }
}
int read()
{
  int num(0);char in=getchar();
  while(in<'0'||in>'9')in=getchar();
  while(in>='0'&&in<='9'){num=(num<<1)+(num<<3)+(in^48);in=getchar();}
  return num;
}
long long lread()
{
  long long num(0),f(1);char in=getchar();
  while(in<'0'||in>'9'){if(in=='-')f=-1;in=getchar();}
  while(in>='0'&&in<='9'){num=(num<<1)+(num<<3)+(in^48);in=getchar();}
  return num*f;
}
int main()
{
freopen("scalar.in","r",stdin);
freopen("scalar.out","w",stdout);
n=read();
for(int i=1;i<=n;i++)x[i]=lread();
for(int i=1;i<=n;i++)
{
  y[i]=lread();
  ans+=x[i]*y[i];
}
lastans=ans;
while(clock()*1.0/CLOCKS_PER_SEC<=0.96)
{
  SA();
}
cout<<ans;
return 0;
}