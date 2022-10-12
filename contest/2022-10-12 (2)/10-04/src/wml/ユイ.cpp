#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define min_line 1e-8
//M_PI
using namespace std;

double r,af,ans;

int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);

    scanf("%lf %lf",&r,&af);

    if(fabs(2*M_PI-af)<min_line)
      cout<<0.000000<<endl;

    ans=4*r*sin(af/2)/(af*3);

    printf("%.6lf\n",ans);

    return 0;
}
