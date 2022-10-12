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
int n,K;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}


const int BNLIM=250,JW=10000;        //高精度模板 
bool isnum(char c)
{if (c>=48 &&c<=57)return 1;else return 0;}
class bignum
{
  public:
   int a[BNLIM+1];
   void mset()
   {memset(a,0,sizeof(a));}
   bignum(LL x=0)
   {
    this->mset();
    //memset(a,0,sizeof(a));
    int i;
    for(i=1;x>0;i++)
     a[i]=x%JW,x/=JW;
    a[0]=i-1;
   }
   int getws(int sj=BNLIM)
   {
    int i;
    for(i=sj;i>=1;i--)if (a[i]>0)break;
    return i;
   }
   friend bignum operator + (bignum a,bignum b)
   {
    bignum c;
    int i,j,k,t1,t2,t3;
    t1=max(a.a[0],b.a[0]);
    for(i=1;i<=t1;i++)
    {
     c.a[i]+=a.a[i]+b.a[i];
     if (c.a[i]>=JW)
      c.a[i+1]++,c.a[i]-=JW;
    }
    c.a[0]=t1;
    if (c.a[t1+1]>0)c.a[0]++;
    return c;
   }
   friend bignum operator - (bignum a,bignum b)
   {
    bignum c;
    int i,j,k,t1,t2,t3;
    for(i=1;i<=a.a[0];i++)
    {
     c.a[i]+=a.a[i]-b.a[i];
     if (c.a[i]<0)
      c.a[i+1]--,c.a[i]+=JW;
    }
    c.a[0]=c.getws(a.a[0]);
    return c;
   }
   friend bignum operator * (bignum a,bignum b)
   {
    bignum c;
    int i,j,k,t1,t2,t3;
    for(i=1;i<=a.a[0];i++)
     for(j=1;j<=b.a[0];j++)
     {
      c.a[i+j-1]+=a.a[i]*b.a[j];
      if (c.a[i+j-1]>=JW)
       c.a[i+j-1+1]+=c.a[i+j-1]/JW,c.a[i+j-1]%=JW;
     }
    c.a[0]=c.getws();
    return c;
   }
   friend bignum operator * (bignum a,int b)//高精度乘单精度 
   {
    bignum c;
    int i,j,k,t1,t2,t3;
    for(i=1;i<=a.a[0];i++)
     {
      c.a[i]+=a.a[i]*b;
      if (c.a[i]>=JW)
       c.a[i+1]+=c.a[i]/JW,c.a[i]%=JW;
     }
    c.a[0]=c.getws();
    return c;
   }
   friend bignum operator / (bignum a,int b)
   {
    bignum c;
    int i,j,k,t1,t2,t3;
    t1=0;
    for(i=a.a[0];i>=1;i--)
    {
     t1=t1*JW+a.a[i];
     c.a[i]=t1/b;
     t1%=b;
    }
    c.a[0]=c.getws(a.a[0]);
    return c;
   }
   void input()  //假设压4位的情况 
   {
    int i=1,j,t1=0,b[BNLIM*4+1];
    char c1;
    for(;;)
    {
     scanf("%c",&c1);
     if (!isnum(c1))break;
     b[++t1]=c1;
    }
    for(i=1;i<=t1;i+=4)
    {
     for(j=i+4-1;j>=i;j--)
      a[i/4+1]=a[i/4+1]*10+b[j];
    }
    a[0]=getws();
   }
   void print()
   {
    int i;
    a[0]=max(getws(),1);
    for(i=a[0];i>=1;i--)
    {
     if (i!=a[0])
     {
      if (a[i]<1000)printf("0");
      if (a[i]<100)printf("0");
      if (a[i]<10)printf("0");
     }
     printf("%d",a[i]);
    }
   }
};
bignum begjd(LL x)  //变成高精度数 
{
    bignum c;
    int i;
    for(i=1;x>0;i++)
     c.a[i]=x%JW,x/=JW;
    c.a[0]=i-1;
    return c;
}

bignum f[201][201];
int main()
{
  srand((unsigned)time(NULL));
  int i,j,k,t1,t2,t3,t4,t5,t;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  bignum pp=0,qq;
  freopen("t3.in","r",stdin);freopen("t3.out","w",stdout);
  scanf("%d",&n);
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
    scanf("%d",&t1);
    if (t1==1)K++;
   }
  f[0][0]=begjd(1);
  for(i=0;i<K;i++)
   for(j=0;j<=K-i&&j<=i;j++)
   {
    if (j!=0)
    {
     f[i+1][j]=  f[i+1][j]+f[i][j]*(K-i-j);
     f[i+1][j-1]=f[i+1][j-1]+f[i][j]*(n-K+j);
    }
    else
    {
     f[i+1][1]=f[i+1][1]+f[i][j]*(K-i-1);
     f[i+1][0]=f[i+1][0]+f[i][j]*(n-K+j);
    }
   }
  for(i=0;i<=K;i++)
   pp=pp+f[K][i];
  for(i=K+1;i<=n;i++)
   pp=pp*(n-i+1);
  pp.print();
  printf("\n");
  return 0;
}
