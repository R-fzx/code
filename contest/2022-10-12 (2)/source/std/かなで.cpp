// powered by xpd1
// on 2011-10
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <iostream>

#define oo 2000000000
#define ooo 1E14
#define EPS 1E-10
#define md 1000007
#define md2 100000000000000007ll
#define qc(i,j) ((Q.p[(i)]>>(j))&1)
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m,K;
short map[11][11];
int qx[4]={0,-1,0,1},qy[4]={-1,0,1,0};
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int head[1000007];
int next[1000001],d2=0,ans;
LL zhi[1000001];
char NN[1000001],MM[1000001];

int head_[3000007];
int next_[3000001],d2_=0;
LL zhi_[3000001],q2[100];

class zt
{
  public:
  unsigned char p[6];  //第0行第0列开始算起 
  char lax,lay,siz;
  void mset()
  {
   for(int i=0;i<n;i++)p[i]=0;
   lax=lay=0;
  }
}qu[3000001];
inline LL XM(LL x,LL y)
{
  //LL t=;
  /*LL t2=x*y-t*md2;
  if (t2<0)
   ts=0;
  return t2;*/
  return x*y-(LL)((long double)x*y/md2)*md2;
}
LL calcp(unsigned char p[])
{
  LL t1=0,i,j;
  //recalcp=0;
  for(i=0;i<n;i++)
  {
   t1=(t1+XM(q2[i*m],p[i]))%md2;
   //for(j=0;j<)
  }
  return t1;
}
inline int MAX(int &x,int y)
{
  x=max(x,y);
}
inline int MIN(int &x,int y)
{
  x=min(x,y);
}

bool addp(LL t1)
{
  LL t2,i,t3,t4;
  t2=t1%md;
  if (head_[t2]==0)
  {
   d2_++,head_[t2]=d2_;
   zhi_[d2_]=t1;return 1;
  }
   for(i=head_[t2];next_[i]!=0;i=next_[i])
   {
    if (zhi_[i]==t1)return 0;
   }
   if (zhi_[i]==t1)return 0;
   d2_++,next_[i]=d2_;
   zhi_[d2_]=t1;return 1;
}
char tmp[10][10],tmp2[10][10],tmp3[10][10];
LL calchs2(int N,int M)
{
  LL t1=0;
  int i,j;
  for(i=1;i<=N;i++)
   for(j=1;j<=M;j++)
    t1=(t1+XM(tmp[i][j],q2[(i-1)*M+(j-1)]))%md2;
  return t1;
}
int reN,reM;
LL calchs(unsigned char p[])
{
  LL t1=0,MXans=0;
  int i,j,k,l,x,y,maxx=-1,maxy=-1,minx=n,miny=m,N,M,t2,t3;
  for(i=0;i<n;i++)
   for(j=0;j<m;j++)
   {
    t2=(p[i]>>j)&1;
    if (t2)
     MAX(maxx,i),MAX(maxy,j),MIN(minx,i),MIN(miny,j);
   }
  N=maxx-minx+1,M=maxy-miny+1;
  for(i=minx;i<=maxx;i++)
   for(j=miny;j<=maxy;j++)
    tmp[i-minx+1][j-miny+1]=(p[i]>>j)&1;
  for(x=0;x<=1;x++)
  {
   if (x==1)
   {
    for(i=1;i<=N/2;i++)  //翻转 
     for(j=1;j<=M;j++)
      swap(tmp[i][j],tmp[N-i+1][j]);
   }
   for(y=0;y<4;y++)
   {
    t1=calchs2(N,M);
    if (t1>MXans||(t1==MXans &&reN<N))   //选择最大的hash值并记录矩形大小 
     MXans=t1,reN=N,reM=M;
    for(i=1;i<=N;i++)   //旋转 
     for(j=1;j<=M;j++)
      tmp2[M-j+1][i]=tmp[i][j];
    swap(N,M);
    for(i=1;i<=N;i++)
     for(j=1;j<=M;j++)
      tmp[i][j]=tmp2[i][j];
   }
  }
  //reN=N,reM=M;
  return MXans;
}
bool addhs(LL t1)
{
  LL t2,i,t3,t4;
  t2=t1%md;
  if (reN==2&&reM==2)
   ts=0;
  if (head[t2]==0)
  {
   d2++,head[t2]=d2;ans++;
   zhi[d2]=t1;NN[d2]=reN,MM[d2]=reM;return 1;
  }
   for(i=head[t2];next[i]!=0;i=next[i])
   {
    if (zhi[i]==t1&&NN[i]==reN&&MM[i]==reM)
     return 0;
   }
   if (zhi[i]==t1&&NN[i]==reN&&MM[i]==reM)
     return 0;
   d2++,next[i]=d2;ans++;
   zhi[d2]=t1;NN[d2]=reN,MM[d2]=reM;return 1;
}
int main()
{
  srand((unsigned)time(NULL));
  LL i,j,k,t1,t2,t3,t4,t5,t,le,ri,cnt=0;
  int tx,ty;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  //zt &q;
  for(q2[0]=1,i=1;i<=90;q2[i]=q2[i-1]*2%md2,i++);
  freopen("かなで.in","r",stdin);freopen("かなで.out","w",stdout);
  scanf("%d%d%d",&n,&m,&K);
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {
    scanf("%c",&c1);
    if (c1=='0')map[i][j]=0;
    else if (c1=='1')map[i][j]=1,cnt++;
    else
    {
     j--;continue;
    }
   }
  if (cnt<K)
  {
   printf("0\n");return 0;
  }
  if (cnt==K)
  {
   printf("1\n");return 0;
  }
  for(i=0;i<=n+1;i++)map[i][0]=map[i][m+1]=0;
  for(i=0;i<=m+1;i++)map[0][i]=map[n+1][i]=0;
  le=1,ri=0;
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
    if (map[i+1][j+1])
    {
     ri++;
     zt &q=qu[ri];
     q.mset();
     q.lax=i,q.lay=j,q.p[i]+=1<<j;
     q.siz=1;
     t1=calcp(q.p);
     if (!addp(t1)){ri--;continue;}
     if (q.siz==K)
     {
      t2=calchs(q.p);
      addhs(t2);
      ri--;
     }
    }
  }
  for(;le<=ri;le++)
  {
   if (le==777)
    ts=0;
   zt &Q=qu[le];
   for(i=0;i<n;i++)
    for(j=0;j<m;j++)tmp3[i][j]=0;
   for(i=0;i<n;i++)
    for(j=0;j<m;j++)
     if ((Q.p[i]>>j)&1)
     {
      for(k=0;k<4;k++)
      {
       tx=i+qx[k];ty=j+qy[k];
       if (map[tx+1][ty+1] && !qc(tx,ty))
       {
        if (Q.lax==i &&Q.lay==j)
         tmp3[tx][ty]=max(tmp3[tx][ty],(char)1);
        else
         tmp3[tx][ty]=max(tmp3[tx][ty],(char)2);  //与原来的有关 
       }
      }
     }
   for(i=0;i<n;i++)
    for(j=0;j<m;j++)
     if (tmp3[i][j])
     {
      if (tmp3[i][j]==2 && (i<Q.lax || (i==Q.lax &&j<=Q.lay)))
       continue; //优化
      ri++;
      zt &q=qu[ri];
     //q.mset();
      q.lax=i,q.lay=j;
      for(k=0;k<n;k++)
       q.p[k]=Q.p[k];
      q.p[i]+= 1<<j;
      q.siz=Q.siz+1;
      t1=calcp(q.p);
      if (!addp(t1))
      {
       ri--;continue;
       }
      if (q.siz==K-5)
       ts=0;
      if (q.siz==K)
      {
       t2=calchs(q.p);
       addhs(t2);
       ri--;
      }
     }
  }
  printf("%d\n",ans);
  //printf("%.%dlf\n",4,4.0);
  return 0;
}
