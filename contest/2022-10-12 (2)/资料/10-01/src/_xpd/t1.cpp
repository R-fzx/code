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
#define md 10007
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m;
int ch[1001][1001],ch2[1001];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int f[1001],size[1001],tmp[1005];
int C[1001][1001];
void DFS(int k)
{
  int i,j,t1,t2,sum;
  
  for(i=ch2[k];i>=1;i--)
  {
   j=ch[k][i];
   DFS(j);
   size[k]+=size[j];
  }
  size[k]+=1;
  sum=0;
  tmp[ch2[k]+1]=1;
  for(i=ch2[k];i>=1;i--)
  {
   j=ch[k][i];
   tmp[i]=tmp[i+1]*C[sum+size[j]-1][sum]%md;
   sum+=size[j];
  }
  f[k]=tmp[1];
}
int main()
{
  srand((unsigned)time(NULL));
  int i,j,k,t1,t2,t3,t4,t5,t,TEST;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("t1.in","r",stdin);freopen("t1.out","w",stdout);
  scanf("%d",&TEST);
  C[0][0]=1;
  for(i=1;i<=1000;i++)  //先下后上 
  {
   C[i][0]=1;
   for(j=1;j<=i;j++)
    C[i][j]=(C[i-1][j-1]+C[i-1][j])%md;
  }
  for(;;)
  {
   n=0;
   scanf("%d",&n);
   if (n==0)break;
   for(i=1;i<=n;i++)ch2[i]=0;
   memset(tmp,0,sizeof(tmp));
   memset(f,0,sizeof(f));
   memset(size,0,sizeof(size));
   for(i=1;i<=n;i++)
   {
    scanf("%d",&ch2[i]);
    for(j=1;j<=ch2[i];j++)
     scanf("%d",&ch[i][j]);
   }
   DFS(1);
   printf("%d\n",f[1]);
  }
  return 0;
}
