#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<map>
#define JW 10000
using namespace std;
int N,M,K;
struct INT
{
       int len;
       int num[10001];
       inline int & operator  [](int a){return(num[a]);}
       };
inline void add(INT &a,INT &b,INT &c)
{
       int i,j,k,l=max(b.len,c.len);
       for(i=1;i<=l;i++)
         a[i]=b[i]+c[i];
       for(i=1;i<=l;i++)
         if(a[i]>=JW)
         {
           a[i+1]+=a[i]/JW;
           a[i]%=JW;
           if(i==l) l++;
           }
       a.len=l;
       }
inline void cf(INT &a,int b)
{
       int i,j,k,l=a.len;
       for(i=1;i<=l;i++)
         a[i]*=b;
       for(i=1;i<=l;i++)
         if(a[i]>=JW)
         {
           a[i+1]+=a[i]/JW;
           a[i]%=JW;
           if(i==l) l++;
           }
       a.len=l;
       }
inline void pr(INT &a)
{
       int i,j,k,l=a.len;
       for(i=l;i>=1;i--)
         if(i==l)
           printf("%d",a[i]);
         else
           printf("%04d",a[i]);
       printf("\n");
       }
INT D[201];
int main()
{
    int i,j,k,l;
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    scanf("%d",&N);
    D[1].len=1;
    D[1][1]=0;
    D[2].len=1;
    D[2][1]=1;
    for(i=3;i<=N;i++)
    {
      if(i==8)
        i=8;
      add(D[i],D[i-1],D[i-2]);
      cf(D[i],i-1);
      }
    pr(D[N]);
    return(0);
}
