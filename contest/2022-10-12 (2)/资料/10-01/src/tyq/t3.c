#include<stdio.h>
#include<stdlib.h>
int n,f[300][1001],g[300][1001];
void cheng(int a,int e)
{
     int i;
     for(i=0;i<1001;i++)
      f[a][i]=f[a][i]*e;
}
void chu(int a,int e)
{
     int i;
     for(i=0;i<1001;i++)
      f[a][i]=f[a][i]/e;
}
void cheng1(int a,int e)
{
     int i;
     for(i=0;i<1001;i++)
      g[a][i]=g[a][i]*e;
}
void chu1(int a,int e)
{
     int i;
     for(i=0;i<1001;i++)
      g[a][i]=g[a][i]/e;
}
void add(int a)
{
     int i;
     for(i=0;i<1000;i++)
      f[a][i]=f[a-2][i]+g[a-2][i];
}
void add1(int a)
{
     int i;
     for(i=0;i<1000;i++)
      g[a][i]=f[a-1][i]+g[a-1][i];
}
void sao(int a)
{
     int i;
     for(i=0;i<1000;i++)
     {
      f[a][i+1]+=f[a][i]/10;
      f[a][i]=f[a][i]%10;
     }
}
void sao1(int a)
{
     int i;
     for(i=0;i<1000;i++)
     {
      g[a][i+1]+=g[a][i]/10;
      g[a][i]=g[a][i]%10;
     }
}
int main()
{
    int i,j,u,ber;
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);
    scanf("%d",&n);
    f[2][0]=1;
    f[3][0]=2;
    g[2][0]=1;
    g[3][0]=3;
    for(i=4;i<=n;i++)
    {
     cheng(i-2,i-1);
     cheng1(i-2,(i-1)*(i-2));
     add(i);
     sao(i);
     chu1(i-2,(i-1)*(i-2));
     chu(i-2,i-1);

     cheng1(i-1,i-1);
     add1(i);
     sao1(i);
     chu1(i-1,i-1);
    }
    for(i=1000;i>=0;i--)
    if(u==1||i==0)
    {
     printf("%d",f[n][i]);
    }
    else
    if(f[n][i]!=0)
    {
     printf("%d",f[n][i]);
     u=1;
    }
    printf("\n");
    return 0;
}
