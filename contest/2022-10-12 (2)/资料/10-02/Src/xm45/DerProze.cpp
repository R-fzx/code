#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<map>
using namespace std;
int N,M,D;
char mo[7][101]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
struct Q{int y,m,d;}bz={2011,9,18},dq;
inline bool operator >(Q &a,Q &b){return(a.y>b.y||(a.y==b.y&&a.m>b.m)||(a.y==b.y&&a.m==b.m&&a.d>b.d));}
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int da(Q &da)
{
       int i,j,k,l=0;
       for(i=1;i<da.y;i++)
         l+=365+(i%100==0?(i%400==0?1:0):(i%4==0?1:0));
       for(i=1;i<da.m;i++)
       {
         if(i==2)
           l+=(da.y%100==0?(da.y%400==0?1:0):(da.y%4==0?1:0));
         l+=day[i];
         }
       l+=da.d;
       return(l);
       }
inline int operator -(Q &a,Q &b){return(da(a)-da(b));}
int main()
{
    int i,j,k,l;
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    scanf("%d%d%d",&dq.y,&dq.m,&dq.d);
    printf("%s\n",mo[((dq-bz)%7+343)%7]);
    return(0);
}
