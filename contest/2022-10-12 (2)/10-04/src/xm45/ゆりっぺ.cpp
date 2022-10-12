#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define ll long long 
using namespace std;
int N,A,B,C,M,sum1,sum2;
long long f[102][102][102]={0};
long long dp[102][102][102]={0};
bool h[102][102][102];
struct V
{
       int a,b,c,sum,bj;
       }v1[100001],v[1001],dl[1000011];
int top;
int pr()
{
     for(int j=0;j<=A;j++)
      for(int k=0;k<=B;k++)
        for(int l=0;l<=C;l++)
          printf("%d %d %d %I64d\n",j,k,l,f[j][k][l]);
     printf("\n");
     }
inline bool cmpa(V a,V b){return(a.a>b.a||(a.a==b.a&&a.sum>b.sum));}
inline bool cmpb(V a,V b){return(a.b>b.b||(a.b==b.b&&a.sum>b.sum));}
inline bool cmpc(V a,V b){return(a.c>b.c||(a.c==b.c&&a.sum>b.sum));}
void csh()
{
     int i,j,k,l=0;
     //sort(v1+1,v1+N+1,cmpa);
     partial_sort(v1+1,v1+1+M,v1+N+1,cmpa);
	 for(i=1;i<=M;i++)
       v1[i].bj=1;
     //sort(v1+1,v1+N+1,cmpb);
     partial_sort(v1+1,v1+1+M,v1+N+1,cmpb);
     for(i=1;i<=M;i++)
       v1[i].bj=1;
     //sort(v1+1,v1+N+1,cmpc);
     partial_sort(v1+1,v1+1+M,v1+N+1,cmpc);
     for(i=1;i<=M;i++)
       v1[i].bj=1;
     for(i=1;i<=N;i++)
       if(v1[i].bj==1)
       {
	     v[++l]=v1[i];
	     }
	 N=l;
	 }
int main()
{
    int i,j;
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);
    scanf("%d%d%d%d",&N,&A,&B,&C);
    M=A+B+C;
    if(M>N)
    {
      printf("I am a godlike cowcowcow\n");
      return(0);
      }
    for(i=1;i<=N;i++)
    {
      scanf("%d%d%d",&v1[i].a,&v1[i].b,&v1[i].c);
      v1[i].sum=v1[i].a+v1[i].b+v1[i].c;
      }
    csh();
    if(N>800) N=800;
    for(j=0;j<=A;j++)
      for(int k=0;k<=B;k++)
        for(int l=0;l<=C;l++)
          f[j][k][l]=dp[j][k][l]=-0x7fffffff;
    top=1;
    dl[top].a=0;
    dl[top].b=0;
    dl[top].c=0;
    h[0][0][0]=1;
    f[0][0][0]=0;
    dp[0][0][0]=0;
    for(i=1;i<=N;i++)
      for(j=top;j>=1;j--)
      {
        int a=dl[j].a,b=dl[j].b,c=dl[j].c;
        if(f[a+1][b][c]<=f[a][b][c]+v[i].a && a!=A)
        {
          if((dp[a+1][b][c]<dp[a][b][c]+v[i].sum && f[a+1][b][c]==f[a][b][c]+v[i].a)||f[a+1][b][c]<f[a][b][c]+v[i].a)
            dp[a+1][b][c]=dp[a][b][c]+v[i].sum;
          f[a+1][b][c]=f[a][b][c]+v[i].a;
          if(h[a+1][b][c]==0)
          {
            h[a+1][b][c]=1;
            top++;
            dl[top].a=a+1;
            dl[top].b=b;
            dl[top].c=c;
            }
          }
        
        
        if(f[a][b+1][c]<=f[a][b][c]+v[i].b && b!=B)
        {
          if((dp[a][b+1][c]<dp[a][b][c]+v[i].sum && f[a][b+1][c]==f[a][b][c]+v[i].b)||(f[a][b+1][c]<f[a][b][c]+v[i].b))
            dp[a][b+1][c]=dp[a][b][c]+v[i].sum;
          f[a][b+1][c]=f[a][b][c]+v[i].b;
          if(h[a][b+1][c]==0)
          {
            h[a][b+1][c]=1;
            top++;
            dl[top].a=a;
            dl[top].b=b+1;
            dl[top].c=c;
            }
          }
        
        if(f[a][b][c+1]<=f[a][b][c]+v[i].c && c!=C)
        {
          if((f[a][b][c+1]==f[a][b][c]+v[i].c&&dp[a][b][c+1]<dp[a][b][c]+v[i].sum )||(f[a][b][c+1]<f[a][b][c]+v[i].c))
            dp[a][b][c+1]=dp[a][b][c]+v[i].sum;
           f[a][b][c+1]=f[a][b][c]+v[i].c;
		  if(h[a][b][c+1]==0)
          {
            h[a][b][c+1]=1;
            top++;
            dl[top].a=a;
            dl[top].b=b;
            dl[top].c=c+1;
            }
          }
        
        }
    printf("%I64d\n%I64d\n",f[A][B][C],dp[A][B][C]);
    //pr();
    return(0);
}
