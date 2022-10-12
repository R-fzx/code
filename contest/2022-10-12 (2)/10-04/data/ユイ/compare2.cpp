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
int n,m;
char ss[50];
LL gcd(LL x,LL y){LL t;for(;y!=0;){t=x%y;x=y;y=t;}return x;}
int main(int argc,char *argv[])
{
  srand((unsigned)time(NULL));
  LL i,j,k,t1,t2,t3,t4,t5,t;
  double u1,u2,u3,u4,u5;
  char c1,c2,c3;
  //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

  FILE *fp=fopen("ユイ.out","r"),*fi=fopen(argv[2],"r"),*fo=fopen("score.log","w");  //fp选手 fi标准 
  u1=-1;
  fscanf(fp,"%lf",&u1);
  fscanf(fi,"%lf",&u2);
  if (fabs(u1-(-1))<EPS)
  {fprintf(fo,"0");return 0;}
  if (fabs(u2)<EPS)
  {
   if (fabs(u1)<EPS)fprintf(fo,"10");
   else fprintf(fo,"0");
   return 0;
  }
  u3=fabs((u1-u2)/u2);
  //if (u3<1)u3=1+(u3-1);
  //u3--;
  
  if (u3<=0.05)
   fprintf(fo,"10");
  else if (u3<=0.1)
   fprintf(fo,"8");
  else if (u3<=0.15)
   fprintf(fo,"6");
  else if (u3<=0.2)
   fprintf(fo,"4");
  else if (u3<=0.4)
   fprintf(fo,"2");
  else
   fprintf(fo,"1");
  fprintf(fo,"\n");
  fclose(fp);
  fclose(fi);
  fclose(fo);
  return 0;
}
