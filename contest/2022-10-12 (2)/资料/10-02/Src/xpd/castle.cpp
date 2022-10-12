// powered by xpd1
// on 2011-10 -
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <iostream>

#define oo 100000000
#define ol 200000000000000000ll
#define ooo 1E14
#define EPS 1E-10
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
typedef long long LL;
const double PI=acos((double)-1);
const LL md=(1<<31)-1;

int ts,ts2;
int n,m,map[1001][1001];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int d2,d[1000001],next[1000001],head[1001],len[1000001];
LL dis[1001];
int qu[1000001];
short hash[1001];
void addedge(int x,int y,int l)
{
  if (map[x][y]==oo)d2++,d[d2]=y,next[d2]=head[x],head[x]=d2;len[d2]=l;
  map[x][y]=min(map[x][y],l);
}
void SPFA()
{
  LL i,j,k,t1,t2,t3,t4,t5,t,le,ri,nw;
  dis[1]=0;
  for(i=2;i<=n;i++)dis[i]=oo;
  le=ri=1;
  qu[1]=1;
  hash[1]=1;
  for(;le<=ri;)
  {
   nw=qu[le];le++;
   hash[nw]=0;
   for(j=head[nw];j!=0;j=next[j])
   {
    i=d[j];
    if (dis[i]>dis[nw]+map[nw][i])
    {
     dis[i]=dis[nw]+map[nw][i];
     if (!hash[i])
     {
      if (le>1 &&dis[qu[le]]>dis[i])qu[--le]=i;
      else qu[++ri]=i;
      hash[i]=1;
     }
    }
   }
  }
}
int main()
{
  srand((unsigned)time(NULL));
  int i,j,k,t1,t2,t3,t4,t5,t;
  LL ans=1,t7;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("castle.in","r",stdin);freopen("castle.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)map[i][j]=oo;
  for(i=1;i<=m;i++)
  {
   scanf("%d%d%d",&t1,&t2,&t3);
   if (t1!=t2)
   {
    addedge(t1,t2,t3);
    addedge(t2,t1,t3);
   }
  }
  SPFA();
  for(i=2;i<=n;i++)
  {
   t7=0;
   for(j=1;j<=n;j++)
   {
    if (i!=j &&dis[j]+map[j][i]==dis[i])
     t7++;
   }
   ans=ans*t7%md;
  }
  printf("%I64d\n",ans);
  return 0;
}
