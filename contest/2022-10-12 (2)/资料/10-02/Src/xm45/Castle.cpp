#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<map>
using namespace std;
int N,M,K;
int lt[1001][1001];
int dd[1001];
int zx[1001];
int la[1001];
long long ans=1;
inline void SPFA()
{
       int i,j,k,l;
       int h[1001]={0};
       int dl[1011]={0},now=0,top=0;
       zx[1]=0;
       for(i=2;i<=N;i++)
         zx[i]=0xfffffff;
       dl[1]=1;
       h[1]=1;
       now=top=1;
       for(now=1;dl[now]!=0;now=now%N+1)
       {
         int dq=dl[now];
         for(i=1;i<=N;i++)
           if(lt[dq][i]!=0 && lt[dq][i]+zx[dq]<zx[i])
           {
             zx[i]=lt[dq][i]+zx[dq];
             if(h[i]==0)
             {
               h[i]=1;
               top=top%N+1;
               dl[top]=i;
               }
             }
         h[dq]=0;
         dl[now]=0;
         }
       }
int main()
{
    int i,j,k,l;
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    scanf("%d%d",&N,&M);
    int a,b,c;
    for(i=1;i<=M;i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      if(lt[a][b]>c || lt[a][b]==0 && a!=b)
      {
        lt[a][b]=lt[b][a]=c;
        }
      }
    SPFA();
    for(i=1;i<=N;i++)
      for(j=1;j<=N;j++)
        if(i!=j && lt[i][j]!=0 && zx[i]+lt[i][j]==zx[j])
        {
          dd[j]++;
          }
    /*for(i=2;i<=N;i++)
      printf("%d %d\n",i,dd[i]);/**/
    ans=1;
    for(i=2;i<=N;i++)
      ans=ans*dd[i]%(2147483647);
    printf("%I64d\n",ans);
    return(0);
}
