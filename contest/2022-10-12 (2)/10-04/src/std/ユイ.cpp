// powered by xpd1
// on 2011-10
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
double R,P;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int main()
{
  srand((unsigned)time(NULL));
  int i,j,k,t1,t2,t3,t4,t5,t;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("ユイ.in","r",stdin);freopen("ユイ.out","w",stdout);
  scanf("%lf%lf",&R,&P);
  u1=sin(P/2)*R*4/3/P;
  printf("%.6lf\n",u1);
  return 0;
}
