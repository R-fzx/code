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
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
string s[7]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline bool run(int x)
{
  if (x%100==0)
  {
   if (x%400==0)return 1;
   else return 0;
  }
  return (x%4==0);
}
int main()
{
  srand((unsigned)time(NULL));
  int i,j,k,t1,t2,t3,t4,t5,t,Y,M,D,now=0;  //2012-01-01ÐÇÆÚÌì 
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("DerProze.in","r",stdin);freopen("DerProze.out","w",stdout);
  scanf("%d%d%d",&Y,&M,&D);
  if (Y<2012)
  {
   for(i=2011;i>=Y;i--)
    now=now-(run(i)+365);
  }
  else
  for(i=2012;i<Y;i++)
    now=now+(run(i)+365);
  for(i=1;i<M;i++)
  {
   if (i==2)now=now+run(Y)+month[i];
   else now=now+month[i];
  }
  now+=(D-1);
  now=(now%7+7)%7;
  //cout<<s[now]<<endl<<endl;
  printf("%s\n",s[now].c_str());
  return 0;
}
