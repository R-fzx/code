#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926535897932384626433832795
#define eps 0.000000001

double r,a,Xian,ans,Hu,C;

int bj(double a,double b);

int main()
{
    freopen("ユイ.in","r",stdin); freopen("ユイ.out","w",stdout);
    scanf("%lf %lf",&r,&a);
    if (bj(a,2*pi)==0)
    {
       printf("0.000000\n");
       return 0;
    }
    Xian=sin(a/(double)(2))*r;
    Xian=Xian*(double)(2);
    ans=Xian*(double)(2)*r/(double)(3);
    C=(double)(2)*pi*r;
    Hu=a/((double)(2)*pi)*C;
    ans=ans/Hu;
    printf("%.6lf\n",ans);
    return 0;
}

int bj(double a,double b)
{
    if (a-b>0-eps && a-b<eps) return 0;
    if (a>b) return 1;
    else return -1;
}
