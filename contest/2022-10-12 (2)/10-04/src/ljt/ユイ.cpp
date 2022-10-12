#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double EPS = 1e-10;
const double PI = (double) acos((double)-1);

int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    double r,p,x,h,ans;
    scanf("%lf%lf",&r,&p);
    if (p-PI<EPS)
       x=2*r*sin(p/2.0);
    else
       x=2*r*sin(PI-p/2.0);
    h=r*p;
    ans=2*r*x/(3.0*h);
    printf("%.6lf",ans);
    return 0;
}
