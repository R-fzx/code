#include <iostream>
using namespace std;
const int kMaxN=2e5+1;
const int kM=1e9+9;
int f[kMaxN],num[kMaxN];
int n,m,ans;
int Find(int k)
{
  return f[k]==k?k:f[k]=Find(f[k]);
}
signed main()
{
freopen("magician.in","r",stdin);
freopen("magician.out","w",stdout);
scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++)f[i]=i;
while(m--)
{
  int a,b;
  scanf("%d%d",&a,&b);
  int x=Find(a),y=Find(b);
  if(x!=y)
  {
    f[x]=y;
  }
  else
  {
    ans=ans*2+1;
    ans%=kM;
  }
  printf("%d\n",ans);
}
return 0;
}