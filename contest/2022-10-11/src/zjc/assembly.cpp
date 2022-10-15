#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct person { double l,b; }p[10];
double f[10][10],ans,t;
int n,m;
double dfs2(int x,int y,double z,double ans)
{
    if(x==n+1)
    {
      if(y*2>n) return ans;
      else return ans*(t/(t+z));
    }
    double a=dfs2(x+1,y+1,z,ans*p[x].l);
    double b=dfs2(x+1,y,z+p[x].b,ans*(1-p[x].l));
    return a+b;
    //return dfs2(x+1,y+1,z,ans*p[x].l)+dfs2(x+1,y,z+p[x].b,ans*(1-p[x].l));
}   
void dfs(int x,int y)
{
    int i,j;
    double s=0,k=p[x].l;
    if(x==n+1) { ans=max(ans,dfs2(1,0,0,1)); return; }
    for(i=0;(i<=y)&&(p[x].l<=1);i++)
    {
      dfs(x+1,y-i);
      p[x].l+=0.1;
    }
    p[x].l=k;
    return;
}
int main()
{
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    int i,j;
    scanf("%d%d%lfd",&n,&m,&t);
    for(i=1;i<=n;i++) scanf("%lf%lf",&p[i].b,&p[i].l),p[i].l/=100.0;
    dfs(1,m);
    printf("%.6lf\n",ans);
    return 0;
}
