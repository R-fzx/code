// powered by xpd1
// on 2011-10 -
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <iostream>

#include <memory>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <conio.h>
#define oo 2000000000
#define ol 200000000000000000ll
#define ooo 1E14
#define EPS 1E-10
#define md 1000000007
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m,K;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
LL Nmi[1000005],MNmi[1000005];//i^n ; i^((m-2)*n)
LL rev[1000005],CK[1000005],CI[1000005],CCI[1000005];
int ss[1000005],ss2;
int fs[1000005];
LL speedmi(LL x,LL y)
{
  LL t2,ans=1;
  for(t2=1;y>0;t2*=2)
  {
   if (y&t2)
   {
    ans=ans*x%md;
    y-=t2;
   }
   x=x*x%md;
  }
  return ans;
}
LL C(LL x,LL y)
{
  LL i,ans=1;
  x=min(x,y-x);
  for(i=1;i<=x;i++)
   ans=ans*(y-i+1)%md*rev[i]%md;
   return ans;
}
int main()
{
  srand((unsigned)time(NULL));
  LL i,j,k,t1,t2,t3,t4,t5,t,ans=0,ans2=0,tmp;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("painting.in","r",stdin);freopen("painting.out","w",stdout);
  scanf("%d%d%d",&n,&m,&K);
  if (m==1)
  {
   printf("%I64d\n",speedmi(K,n));
   return 0;
  }
  for(i=2;i<=K;i++)
  {
   if (fs[i]==0)
   {
    ss[++ss2]=i;
   }
   for(j=1;j<=ss2 &&ss[j]*i<=K;j++)
   {
    fs[i*ss[j]]=ss[j];
    if (i%ss[j]==0)break;
   }
  }
  for(i=1;i<=n+5;i++)
  {
   if (fs[i])
    Nmi[i]=Nmi[fs[i]]*Nmi[i/fs[i]]%md;
   else Nmi[i]=speedmi(i,n);
  }
  for(i=1;i<=n+5;i++)
  {
   if (fs[i])MNmi[i]=MNmi[fs[i]]*MNmi[i/fs[i]]%md;
   else MNmi[i]=speedmi(Nmi[i],m-2);
  }
  MNmi[0]=1;
  for(i=1;i<=K;i++)
  {
   if (fs[i])rev[i]=rev[fs[i]]*rev[i/fs[i]]%md;
   else rev[i]=speedmi(i,md-2);
  }
  CK[0]=1;
  for(i=1;i<=min(n,K);i++)
  {
   if (i==20) 
    ts=0;
   CK[i]=CK[i-1]*(K-i+1)%md*rev[i]%md;
   tmp=1;
   t1=0;
   for(j=i;j>=1;j--)
   {
    t2=tmp*Nmi[j];
    if ((i-j)%2==0)t1=(t1+t2)%md;
    else t1=(t1-t2+md)%md;
    t3=i-j+1;
    tmp=tmp*(i-t3+1)%md*rev[t3]%md;
   }
   t1=t1*t1%md;
   t1=CK[i]*t1%md;                //求出了第一种颜色的情况以及第二种颜色内部配置 
   if (m==2)j=0;else j=1;
   j=max(j,i*2-K);
   CI[j]=C(j,i);
   CCI[K-2*i+j]=C(K-2*i+j,K-i);
   ans2=0;
   if (i==n)
    ts=0;
   for(;j<=i;j++)
   {
    t3=K-2*i+j;
    t2=CI[j]*CCI[t3]%md*MNmi[j]%md;
    ans2=(ans2+t2)%md;
    CI[j+1]=CI[j]*(i-(j+1)+1)%md*rev[j+1]%md;
    CCI[t3+1]=CCI[t3]*((K-i)-(t3+1)+1)%md*rev[t3+1]%md;
   }
   ans=(ans+ans2*t1)%md;
  }
  printf("%I64d\n",ans);
  return 0;
}
