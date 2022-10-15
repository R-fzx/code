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
#define EPS 1E-15
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,K,A,B[10],L[10],houm[10];
double ans=0;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
double prb;
void kel(int k,double NOWp,int wl,int zc)
{
  if (NOWp<EPS)return;
  if (k>n)
  {
   if (zc>n/2)prb+=NOWp;
   else prb+=NOWp*A/(A+wl);
   return;
  }
  kel(k+1,NOWp*L[k]/100,wl,zc+1);  //ÖÒ³¼
  kel(k+1,NOWp*(100-L[k])/100,wl+B[k],zc);
}
void DFS(int k,int gif)
{
  if (k>n)
  {
   prb=0;
   kel(1,1,0,0);
   ans=max(ans,prb);
   return;
  }
  int i,L2;
  L2=L[k];
  if (houm[k]<=gif)i=(100-L[k])/10;else
   i=0;
  for(;i<=gif;i++)
  {
   L[k]=L2+10*i;
   if (L[k]>100)break;
   DFS(k+1,gif-i);
  }
  L[k]=L2;
}
int main()
{
  srand((unsigned)time(NULL));
  int i,j,k,t1,t2,t3,t4,t5,t;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("assembly.in","r",stdin);freopen("assembly.out","w",stdout);
  scanf("%d%d%d",&n,&K,&A);
  for(i=1;i<=n;i++)
  {
   scanf("%d%d",&B[i],&L[i]);
  }
  for(i=n;i>=1;i--)
  {
   houm[i]=houm[i+1]+(100-L[i])/10;
  }
  DFS(1,K);
  printf("%.6lf\n",ans);
  return 0;
}
