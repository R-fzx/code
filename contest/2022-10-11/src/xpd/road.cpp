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
#define ol 200000000000000000ll  //2*10^17
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
int n,m,P,Q;
int A[100005],B[100005],d[100005],next[100005],head[400],d2;
int lsA[50005];
char hash[201];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
void addedge(int x,int y,int a,int b)
{
  d2++,d[d2]=y,next[d2]=head[x],head[x]=d2,A[d2]=a,B[d2]=b;
}
void DFS(int k,int a,int b)
{
  int i,j;
  hash[k]=1;
  for(j=head[k];j!=0;j=next[j])
  {
   if (A[j]>a||B[j]>b)continue;
   i=d[j];
   if (hash[i])continue;
   DFS(i,a,b);
  }
}
bool judge(LL a,LL b)
{
  int i;
  memset(hash,0,sizeof(hash));
  DFS(1,a,b);
  for(i=1;i<=n;i++)if (!hash[i])return 0;
  return 1;
}
int main()
{
  srand((unsigned)time(NULL));
  LL i,j,k,t1,t2,t3,t4,t5,t,ans=ol,le,ri,mid,MAXB=0;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("road.in","r",stdin);freopen("road.out","w",stdout);
  scanf("%d%d",&n,&m);
  scanf("%d%d",&P,&Q);
  for(i=1;i<=m;i++)
  {
   scanf("%I64d%I64d%I64d%I64d",&t1,&t2,&t3,&t4);
   MAXB=max(MAXB,t4);
   if (t1==t2)
   {
    m--,i--;continue;
   }
   addedge(t1,t2,t3,t4);addedge(t2,t1,t3,t4);
   lsA[i]=t3;
  }
  sort(lsA+1,lsA+m+1);
  for(j=1;j<=m;j++)
  {
   if (j!=1 && lsA[j]==lsA[j-1])continue;
   i=lsA[j];
   if (i*P>=ans)break;
   for(le=0,ri=min(MAXB,(ans-i*P)/Q),mid=(le+ri)/2;le<=ri;mid=(le+ri)/2)
   {
    if (judge(i,mid))ri=mid-1;
    else le=mid+1;
   }
   ans=min(ans,i*P+le*Q);
  }
  if (ans==ol)printf("-1\n");
  else 
  printf("%I64d\n",ans);
  return 0;
}
