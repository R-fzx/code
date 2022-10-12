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
#define EPS 1E-5
/*#define dis(x1,y1,x2,y2) (double)(sqrt( ((x1)-(x2))*((x1)-(x2)) + ((y1)-(y2))*((y1)-(y2)) ) )
#define disx(x,y) (double)(sqrt((x)*(x)+(y)*(y)))
#define dianji(x1,y1,x2,y2) (double)((x1)*(x2)+(y1)*(y2))
#define chaji(x1,y1,x2,y2) (double)((x1)*(y2)-(y1)*(x2))*/
using namespace std;
const double PI=acos((double)-1);
typedef long long LL;
int ts,ts2;
int n,m;
double ans,LJJ;
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
//   计算几何模块 
class point{     //点或向量                  
  public:
   double x,y;
  point(){x=y=0;}
  point(double a,double b){x=a,y=b;}
  inline friend point operator + (point A,point B)
  {return point(A.x+B.x,A.y+B.y);}
  inline  friend point operator - (point A,point B)
  {return point(A.x-B.x,A.y-B.y);}
  inline  friend point operator * (point A,double p)
  {return point(A.x*p,A.y*p);}
  inline  friend point operator / (point A,double p)
  {return point(A.x/p,A.y/p);}
}ZX,YS;
class XL{      //向量 或者一条线段 
  public:
   point a,b;
  XL(){}
  XL(point x,point y){a=x;b=y;}
  XL(double t1,double t2,double t3,double t4)
  {a.x=t1;a.y=t2; b.x=t3;b.y=t4;}
};
inline double sqr(double x)
{return x*x;}
inline double chaji(point A,point B)
{return A.x*B.y - B.x*A.y;}
inline double dianji(point A,point B)
{return A.x*B.x + A.y*B.y;}
inline double dis(point A,point B)
{return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));}
inline double dis(XL A)
{return dis(A.a,A.b);}
inline double disx(point A)
{return sqrt(sqr(A.x)+sqr(A.y));}
inline double Atan2(point A)
{return atan2(A.y,A.x); }
inline point shengcheng(double JD,double CD =1.0)  //极角 +长度 
{return point(cos(JD)*CD,sin(JD)*CD); }
inline short comp(double x,double y)
{if (fabs(x-y)<EPS)return 0;
  else if (x<y)return -1;
  else return 1;}
inline short equ(double x,double y) //x与y是否相等
{if (fabs(x-y)<EPS)return 1;
  else return 0;}
short DIR(XL now)  // 0左 1上  2右  3下   向量的方向 
{short t1=comp(now.b.x,now.a.x),t2=comp(now.b.y,now.a.y);
  if (t2==0)
  {
   if (t1<0)return 0;
   else return 2;
  }
  if (t1==0)
  {
   if (t2>0)return 1;
   else return 3;
  }
}
bool IN(point a)//点是否在输入矩形里面 
{if ((comp(a.x,ZX.x)==-1)||
  (comp(a.x,YS.x)==1)||
  (comp(a.y,ZX.y)==-1)||
  (comp(a.y,YS.y)==1))return 0;
  else return 1;
}
int tag=0;
bool bet(double x,double y,double z)//判是否x>=y且x<=z betweem
{if (y>z)swap(y,z);
  if (y-EPS<=x &&x<=z+EPS)return 1;
  else return 0;
}
bool JXJ(XL A,XL B) //两矩形是否交
{if (min(A.a.x,A.b.x)>max(B.a.x,B.b.x) ||max(A.a.x,A.b.x)<min(B.a.x,B.b.x))return 0;
  if (min(A.a.y,A.b.y)>max(B.a.y,B.b.y) ||max(A.a.y,A.b.y)<min(B.a.y,B.b.y))return 0;
  return 1;
} 
void XD_(XL now)  //判线段有多少在输入矩形里面 
{double u1,u2,u3;
  XL qq,QQ;
  now.b=(now.b*2+now.a)/3;
  int t2=IN(now.a);
  int t3=IN(now.b);
  int t1=DIR(now);
  tag=0;
  if (t2==0&&t3==0)
  {if (t1==0)
   {
    if (now.b.x<ZX.x&&now.a.x>YS.x && bet(now.a.y,ZX.y,YS.y))
     ans+=YS.x-ZX.x;
    else tag=1;
   }
   if (t1==2)
   {
    if (now.a.x<ZX.x&&now.b.x>YS.x && bet(now.a.y,ZX.y,YS.y))
     ans+=YS.x-ZX.x;
    else tag=1;
   }
   if (t1==1)
   {
    if (now.a.y<ZX.y&&now.b.y>YS.y && bet(now.a.x,ZX.x,YS.x))
     ans+=YS.y-ZX.y;
    else
     tag=1;
   }
   if (t1==3)
   {
    if (now.b.y<ZX.y&&now.a.y>YS.y && bet(now.a.x,ZX.x,YS.x))
     ans+=YS.y-ZX.y;
    else
     tag=1;
   }
   if (tag==1)
   {u1=dis(now);
    u2=u1;
    if (t1%2==1)
    {
     qq=XL(now.a.x-u2,now.a.y,now.a.x+u2,now.b.y+(now.b.y-now.a.y)/2);
    }
    else
     qq=XL(now.a.x,now.a.y-u2,now.b.x+(now.b.x-now.a.x)/2,now.a.y+u2);
    if (JXJ(qq,XL(ZX,YS)))
     tag=0;
   }
   return;
  }
  if (t2==1&&t3==1)
  {
   tag=-1;  //完全包含 
   ans+=dis(now);
   return;
  }
  if (t2==0)
   swap(now.a,now.b);  //a在里面 
  t1=DIR(now);
  if (t1==0)
   ans+=dis(now.a,point(ZX.x,now.a.y));
  if (t1==3)
   ans+=dis(now.a,point(now.a.x,ZX.y));
  if (t1==1)
   ans+=dis(now.a,point(now.a.x,YS.y));
  if (t1==2)
   ans+=dis(now.a,point(YS.x,now.a.y));
}
XL xuanz(XL now,double jd)  //逆时针旋转角度 
{
  double u1,u2,u3;
  XL qq;
  u1=Atan2(now.b-now.a);
  point pp=shengcheng(u1+jd,dis(now));
  return XL(now.a.x,now.a.y,pp.x+now.a.x,pp.y+now.a.y);
}
bool ongrid(point p)
{
  int t1=(int)floor(p.x+EPS),t2=(int)floor(p.y+EPS);
  if (comp(t1,p.x)==0 && comp(t2,p.y)==0 )return 1;
  else return 0;
}
void DFS(int sec,XL now)
{ 
  double DIS=dis(now.a,now.b);
  short dir=DIR(now);
  if (DIS<1)
  {
   double u1,u2,u3;
   int t1,t2;
   t1=(int)floor(now.b.x+EPS),t2=(int)floor(now.b.y+EPS);
   //if (t1<ZX.x-EPS ||t1>YS.x-1+EPS ||t2<ZX.y-EPS ||t2>YS.y-1+EPS)return;  //没有包含 
   u1=now.b.x,u2=now.b.y;
   if (u1<ZX.x-EPS ||u1>YS.x+EPS ||u2<ZX.y-EPS ||u2>YS.y+EPS)return;
   u1=now.a.x,u2=now.a.y;
   if (u1<ZX.x-EPS ||u1>YS.x+EPS ||u2<ZX.y-EPS ||u2>YS.y+EPS)return;
   
   if (ongrid(now.b)&&( (dir%2==1 &&(equ(t1,ZX.x)||equ(t1,YS.x)) ) || ((dir+1)%2==1 &&(equ(t2,ZX.y)||equ(t2,YS.y))) ))
    ans+=DIS*(500-sec)/3 +DIS;
   else
    ans+=DIS*(500-sec)*2/3 +DIS;
   return;
  }
  //if (sec>15)return;
  XD_(now);
  if (tag==1)return;  //完全没被包含 
/*  if (tag==-1)
  {
   ans+=DIS*(500-sec)*2/3 +DIS;
   return;
  }*/
  
  XL qq;
  point pp=(now.a+now.b*2)/3; 
  qq=XL(pp.x,pp.y,now.b.x,now.b.y);
  DFS(sec+1,qq);
  DFS(sec+1,xuanz(qq,PI/2));
  DFS(sec+1,xuanz(qq,2*PI-PI/2));
}
int main()
{
  srand((unsigned)time(NULL));
  int i,j,k,t1,t2,t3,t4,t5,t;
  double X1,Y1,X2,Y2;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  point pp,PP;
  XL qq,QQ;
  freopen("Metamorphosis.in","r",stdin);freopen("Metamorphosis.out","w",stdout);
  scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
  if (X1>X2)swap(X1,X2);
  if (Y1>Y2)swap(Y1,Y2);
  ZX=point(X1,Y1);
  YS=point(X2,Y2);
  qq=XL(0,0,0,81);
  DFS(1,qq);
  printf("%.1lf\n",ans);
  return 0;
}
