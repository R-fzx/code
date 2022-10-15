#include <stdio.h>
#include <stdlib.h>
#define eps 0.000000001

int n,k,win,i,b[16],l[16];
double key,a,ans;

int bj(double a,double b);
void dfs(int i,int sur);
void work(int i,int s,int bs,double gl);

int main()
{
    freopen("assembly.in","r",stdin); freopen("assembly.out","w",stdout);
    scanf("%d %d %lf",&n,&k,&a);
    for(i=1;i<=n;i++) scanf("%d %d",&b[i],&l[i]);
    win=(n>>1);
    win++;
    ans=-1;
    dfs(1,k);
    printf("%.6lf\n",ans);
    return 0;
}

int bj(double a,double b)
{
    if (a-b>0-eps && a-b<eps) return 0;
    if (a>b) return 1;
    else return -1;
}

void dfs(int i,int sur)
{
     int x;
     if (sur==0)
     {
        key=0;
        work(1,0,0,1);
        if (bj(key,ans)==1) ans=key;
        return;
     }
     if (i>n) return;
     for(x=0;x<=sur;x++)
     {
        l[i]+=x*10;
        dfs(i+1,sur-x);
        l[i]-=x*10;
     }
     return;
}

void work(int i,int s,int bs,double gl)
{
    int x;
    if (i>n)
    {
       if (s>=win) key+=gl;
       else key+=gl*(a/(a+(double)(bs)));
       return;
    }
    x=l[i];
    if (l[i]>100) x=100;
    work(i+1,s+1,bs,gl*(double)(x)/(double)(100));
    work(i+1,s,bs+b[i],gl*(double)(100-x)/(double)(100));
    return;
}
