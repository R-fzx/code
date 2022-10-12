#include<stdio.h>
#include<math.h>
#define pi 3.14159265357
double r,sita,hc,xc;
int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    scanf("%lf%lf",&r,&sita);
    hc=2*r*pi*sita/(2*pi);
    if(sita<pi)xc=2*r*sin(sita/2);
    else xc=2*r*sin((2*pi-sita)/2);
    printf("%.6lf\n",2*r*xc/(3*hc));
    return 0;
}
