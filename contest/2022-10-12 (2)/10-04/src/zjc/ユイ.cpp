#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
#define eps 1e-10
double n,m,ans,c;
int zero(double x)
{
    if(fabs(x)<eps) return 0;
    if(x>eps) return 1; return -1;
}
int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    scanf("%lf%lf",&n,&m);
    if(zero(m-2*pi)==0) { printf("0.000000\n"); return 0; }
    c=m/(2.0*pi)*2.0*pi*n;
    ans=sin(m/2.0)*n*2.0*2.0*n/3.0/c;
    printf("%.6lf\n",ans);
    return 0;
}
