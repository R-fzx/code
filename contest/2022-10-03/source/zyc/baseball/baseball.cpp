#include <iostream>
#include <cmath>
using namespace std;
int n;
long long c;
long double r;
int main()
{
freopen("baseball.in","r",stdin);
freopen("baseball.out","w",stdout);
while(cin>>n)
{
  cin>>r;
  c=1;
  for(int i=1;i<=n;i++)c*=10;
  for(int i=2;;i++)
  {
    int x=roundl(r*i);
    long double rr=x*1.0/i;
    if(round(rr*c)==round(r*c))
    {
      cout<<i<<"\n";
      break;
    }
  }
}
return 0;
}