#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double pi=3.1415926535897932384626433832795;
double r,jiao,chang,ans,huchang,zhouchang;
int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    scanf("%lf %lf",&r,&jiao);
    if(jiao-2*pi==0.00000000) 
    {
                              printf("0.000000\n");
                              return 0;
    }
    else
    {
        chang=sin(jiao/2)*r;
        chang=chang*2*1.000000;
    }
    ans=chang*2*1.000000*r/(3*1.000000);
    zhouchang=2*1.000000*pi*r;
    huchang=jiao/(2*1.000000*pi)*zhouchang;
    ans=ans/huchang;
    printf("%.6lf\n",ans);
    return 0;
}
    
    
