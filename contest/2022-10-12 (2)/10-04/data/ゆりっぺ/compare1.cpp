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
  FILE *fp=fopen("¤æ¤ê¤Ã¤Ú.out","r"),*fi=fopen(argv[2],"r"),*fo=fopen("score.log","w");
  fscanf(fp,"%I64d%I64d",&t1,&t2);
  fscanf(fi,"%I64d%I64d",&t3,&t4);
  fscanf(fi,"%c",&c1);
  if (c1=='I')
  {
   fgets(ss,50,fp);
   t1=strlen(ss);
   if (ss[t1-1]=='\n')ss[t1-1]='\0';
   if (strcmp(ss,"I am a godlike cowcowcow")==0)fprintf(fo,"10");
   else fprintf(fo,"0");
   fclose(fp);
  fclose(fi);
  fclose(fo);
   return 0;
  }
  t5=(t1==t3)+(t2==t4);
  if (t5==1)
   fprintf(fo,"4");
  else if (t5==2)
   fprintf(fo,"10");
  else 
   fprintf(fo,"0");
  fprintf(fo,"\n");
  fclose(fp);
  fclose(fi);
  fclose(fo);
  return 0;
}
