// powered by xpd1
// on 2011-09- 
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
#define ooo 1E14
#define EPS 1E-10
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m;
LL A,B,f[70],maxL=(1ll<<63)-1;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
LL speedmi(LL x,LL y)
{
  LL t1,t2,ans=1;
  for(t2=1;y>0;t2*=2)
  {
   if (y&t2)
   {
    if ((double)ans*x > maxL)
    {
     return maxL;
    }
    ans=ans*x;
    y-=t2;
   }
   if (y==0)break;
   if ((double)x*x > maxL)
    {
     return maxL;
    }
   x=x*x;
  }
  
  return ans;
}
int main()
{
  srand((unsigned)time(NULL));
  LL i,j,k,t1,t2,t3,t4,t5,t,le,ri,mid,ans;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("t2.in","r",stdin);freopen("t2.out","w",stdout);
  for(;;)
  {
   A=B=0;
   scanf("%I64d%I64d",&A,&B);
   
   if (A==0)break;
   A=max(A,2);
   memset(f,0,sizeof(f));
   for(i=62;i>=2;i--)
   {
   // if (i==59)
   //  ts=0;
    u1=(double)1/i;
    ri=1000000001;
    for(le=1,mid=(le+ri)/2;le<ri-1;mid=(le+ri)/2)
    {
     t1=speedmi(mid,i);
     if (t1>=A)ri=mid;
     else le=mid;
    }
    t3=ri;
    ri=1000000001;
    for(le=1,mid=(le+ri)/2;le<ri-1;mid=(le+ri)/2)
    {
     t1=speedmi(mid,i);
    // if (i==59 && mid==2)ts=0;
     if (t1>B)ri=mid;
     else le=mid;
    }
    f[i]=le-t3+1;
    for(j=2;i*j<=62;j++)
    {
     f[i]-=f[i*j];
    }
   }
   ans=0;
   for(i=62;i>=2;i--)ans+=f[i]*(i-1);
   ans+=B-A+1;
   printf("%I64d\n",ans);
  }
  return 0;
}
