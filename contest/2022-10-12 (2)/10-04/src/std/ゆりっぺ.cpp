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
#define ol 20000000000000000ll
#define ooo 1E14
#define EPS 1E-10
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
const int SIZ=2000001;
typedef long long LL;
int ts,ts2;
int n,m;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
LL f[101][101][101],f2[101][101][101],A,B,C,a[SIZ],b[SIZ],c[SIZ],sm[SIZ];
int ord[SIZ],xx[301],ABC;
char xuan[2000001];
inline bool cmp(int A,int B,int flag)
{
  if (flag==1)
  {
   if (a[ord[A]]>=a[ord[B]])return 1;
   return 0;
  }
  if (flag==2)
  {
   if (b[ord[A]]>=b[ord[B]])return 1;
   return 0;
  }
  if (flag==3)
  {
   if (c[ord[A]]>=c[ord[B]])return 1;
   return 0;
  }
}
void qs(int le,int ri,int flag)
{
  if (le>=ri)return;
  int i,j,k;
  i=le,j=ri,k=i+(int)((j-i)*0.618);
  for(;i<=j;)
  {
   for(;i<k &&cmp(i,k,flag);i++);
   swap(ord[k],ord[i]);
   k=i,i++;
   if (i>j)break;
   for(;j>k &&cmp(k,j,flag);j--);
   swap(ord[k],ord[j]);
   k=j,j--;
  }
  qs(le,k-1,flag);
  if (k<ABC)
   qs(k+1,ri,flag);
}
inline void MAX(LL &a,LL b)
{
  a=max(a,b);
}
inline void MIN(LL &a,LL b)
{
  a=min(a,b);
}
char ss[100];
int main()
{
  srand((unsigned)time(NULL));
  LL i,j,k,l,t1,t2,t3,t4,t5,t,nw,tmp,len;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  freopen("ゆりっぺ.in","r",stdin);freopen("ゆりっぺ.out","w",stdout);
  scanf("%d%I64d%I64d%I64d%*c",&n,&A,&B,&C);
  ABC=A+B+C;
  for(i=1;i<=n;i++)
  {
   //scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
   gets(ss);
   //sscanf(ss,"%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
   len=strlen(ss);
   ss[len]=' ';
   ss[len+1]='\0';
   tmp=1,t1=1;t2=0;
   for(j=0;ss[j]!='\0'&&ss[j]!='\n';j++)
   {
    if (ss[j]=='-')
    {
     t1=-1;
     continue;
    }
    if (ss[j]>=48 && ss[j]<=57)
     t2=t2*10+(ss[j]-48);
    else
    {
     t2*=t1;
     if (tmp==1)
      a[i]=t2;
     else if (tmp==2)
      b[i]=t2;
     else 
      c[i]=t2;
     tmp++;
     t1=1,t2=0;
     continue;
    }
   }
   sm[i]=a[i]+b[i]+c[i];
  }
  if (n<ABC)
  {
   printf("I am a godlike cowcowcow\n");
   return 0;
  }
  for(i=1;i<=n;i++)
   ord[i]=i;
  qs(1,n,1);
  for(i=1;i<=ABC;i++)
   xuan[ord[i]]=1;
  for(i=1;i<=n;i++)
   ord[i]=i;
  qs(1,n,2);
  for(i=1;i<=ABC;i++)
   xuan[ord[i]]=1;
  for(i=1;i<=n;i++)
   ord[i]=i;
  qs(1,n,3);
  for(i=1;i<=ABC;i++)
   xuan[ord[i]]=1;
  m=0;
  for(i=1;i<=n;i++)
   if (xuan[i])xx[++m]=i;
  for(i=0;i<=A;i++)
   for(j=0;j<=B;j++)
    for(k=0;k<=C;k++)
     f[i][j][k]=f2[i][j][k]=-ol;
  f[0][0][0]=0,f2[0][0][0]=0;
  for(i=1;i<=m;i++)
  {
   nw=xx[i];
   for(j=A;j>=0;j--)
    for(k=B;k>=0;k--)
     for(l=C;l>=0;l--)
     {
      if (j<A)
      {
       t1=f[j][k][l]+a[nw];
       if (f[j+1][k][l]<t1)
        f[j+1][k][l]=t1,f2[j+1][k][l]=f2[j][k][l]+sm[nw];
       else if (f[j+1][k][l]==t1)
        MAX(f2[j+1][k][l],f2[j][k][l]+sm[nw]);
      }
      if (k<B)
      {
       t1=f[j][k][l]+b[nw];
       if (f[j][k+1][l]<t1)
        f[j][k+1][l]=t1,f2[j][k+1][l]=f2[j][k][l]+sm[nw];
       else if (f[j][k+1][l]==t1)
        MAX(f2[j][k+1][l],f2[j][k][l]+sm[nw]);
      }
      if (l<C)
      {
       t1=f[j][k][l]+c[nw];
       if (f[j][k][l+1]<t1)
        f[j][k][l+1]=t1,f2[j][k][l+1]=f2[j][k][l]+sm[nw];
       else if (f[j][k][l+1]==t1)
        MAX(f2[j][k][l+1],f2[j][k][l]+sm[nw]);
      }
     }
  }
  printf("%I64d\n%I64d\n",f[A][B][C],f2[A][B][C]);
  return 0;
}
