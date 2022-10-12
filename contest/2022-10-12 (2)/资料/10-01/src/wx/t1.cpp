#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int l[1002],r[1002],size[1002],p[1002];
int f[1002][1002],ge[1002];
int dp[1002],n;
void make(int x)
{
     int i,j,k;
     if(ge[x]!=0)
     l[x]=f[x][1];//×ó¶ù×Ó 
     for(i=1;i<=ge[x];i++)
     {
      if(i!=ge[x])
      r[f[x][i]]=f[x][i+1];//ÓÒÐÖµÜ 
      make(f[x][i]);
     }
}
int C(int x,int y)
{
    if(x==0||x==y)return 1;
    int i,j,k=1;
    for(i=y;i>x;i--)
    {
     k=k*i%10007;
     //k/=y-i+1;
     k=k*p[y-i+1]%10007;
    }
    return k;
}
void sou(int x)
{
     int i,j,k;
     if(l[x]==0&&r[x]==0){
                          size[x]=1;
                          dp[x]=1;
                          return;
                          }
     if(l[x]!=0)sou(l[x]);
     if(r[x]!=0)sou(r[x]);
     size[x]=size[l[x]]+size[r[x]]+1;
     dp[x]=(dp[l[x]]*dp[r[x]]%10007)*C(size[l[x]],size[x]-1);
     dp[x]%=10007;
}
int get_ni(int x,int K)
{
    if(K<=1)return x;
    int now=get_ni(x,K/2);
    now=now*now%10007;
    if(K & 1)
    now=now*x%10007;
    return now;
}
void ready()
{    
     int i,j,k;
     p[1]=1;
    for(i=2;i<=1002;i++)
    {
     int x=10005;
     p[i]=get_ni(i,x);
    }
}
int main()
{
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    
    int i,j,k,T;
    scanf("%d",&T);
    ready();
    for(int ii=1;ii<=T;ii++)
{
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    scanf("%d",&n);
    dp[0]=1;//×¢Òâ£¡£¡ 
    for(i=1;i<=n;i++)
    {
     dp[i]=1;
     scanf("%d",&ge[i]);
     for(j=1;j<=ge[i];j++)
     scanf("%d",&f[i][j]);
    }
    make(1);
    sou(1);
    printf("%d\n",dp[1]);
}
return 0;
}
