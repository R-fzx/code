#include <iostream>
#include <algorithm>
using namespace std;
const int kMaxN=4e4+1;
int n,m,a[kMaxN],b[kMaxN],c[kMaxN],x;
int cnt[kMaxN];
int read()
{
  int num(0);char in=getchar();
  while(in<'0'||in>'9')in=getchar();
  while(in>='0'&&in<='9'){num=(num<<1)+(num<<3)+(in^48);in=getchar();}
  return num;
}
void write(int x)
{
  if(x>9)write(x/10);
  putchar(x%10+'0');
}
int main()
{
freopen("dandelion.in","r",stdin);
freopen("dandelion.out","w",stdout);
n=read();
m=read();
for(int i(1);i<=n;++i)
{
  a[i]=read();
  b[i]=a[i];
}
sort(b+1,b+n+1);
for(int i(1);i<=n;i++)
{
  int x(lower_bound(b+1,b+n+1,a[i])-b);
  c[x]=a[i];
  a[i]=x;
}
while(m--)
{
  int l((read()+x-1)%n+1),r((read()+x-1)%n+1);
  if(l>r)swap(l,r);
  int nowans=0,max=0;
  for(int i(l);i<=r;++i)
  {
    ++cnt[a[i]];
    if(cnt[a[i]]>max)
    {
      max=cnt[a[i]];
      nowans=a[i];
    }
    else if(cnt[a[i]]==max&&a[i]<nowans)
    {
      nowans=a[i];
    }
  }
  for(int i(l);i<=r;++i)
  {
    --cnt[a[i]];
  }
  write(c[nowans]);putchar('\n');
}
return 0;
}