#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<map>
#define mod 10007
using namespace std;
int T;
int N,M,K;
struct tree{int fa,lc,rc,dp,s;}t[1001];
int C[1001][2001],ny[1001];
int ans;
void ss(int sl)
{
     int i,j,k,l;
     if(sl==0) return;
     ss(t[sl].lc);
     ss(t[sl].rc);
     t[sl].s=t[t[sl].lc].s+t[t[sl].rc].s+1;
     if(t[sl].lc==0 && t[sl].rc==0)
       t[sl].dp=1;
     if(t[sl].lc!=0 && t[sl].rc==0)
       t[sl].dp=t[t[sl].lc].dp%mod;
     if(t[sl].lc==0 && t[sl].rc!=0)
       t[sl].dp=t[t[sl].rc].dp%mod;
     if(t[sl].lc!=0 && t[sl].rc!=0)
       t[sl].dp=t[t[sl].lc].dp*t[t[sl].rc].dp%mod*C[t[t[sl].lc].s][t[t[sl].lc].s+t[t[sl].rc].s]%mod;
     }
void work()
{
     int i,j,k,l;
     scanf("%d",&N);
     memset(t,0,sizeof(t));
     ans=0;
     for(i=1;i<=N;i++)
     {
       scanf("%d",&j);
       k=i;
       while(j--)
       {
         scanf("%d",&l);
         if(k==i)
           t[k].lc=l;
         else
           t[k].rc=l;
         k=l;
         }
       }
     ss(1);
     printf("%d\n",t[1].dp);
     }
int ksm(int a,int b)
{
    int i,j,k,l=1;
    if(b==0) return(1);
    if(b==1) return(a);
    i=ksm(a,b/2);
    if(b%2==0)
      return(i*i%mod);
    else
      return(i*i%mod*a%mod);
}
void csh()
{
     /*for(i=1;i<=N;i++)
       ny[i]=ksm(i,mod-2);/**/
     int i,j,k,l;
     for(i=0;i<=1000;i++)
       C[0][2*i]=C[0][2*i+1]=C[i][i]=1;
     for(i=1;i<=2*1000;i++)
       for(j=1;j<=1000 && j<i;j++)
         C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
     }
int main()
{
    int i,j,k,l;
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    csh();
    scanf("%d",&T);
    while(T--)
      work();
    return(0);
}
