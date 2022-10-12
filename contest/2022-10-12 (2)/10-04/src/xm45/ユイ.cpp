#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#define eps 1e-15
//M_PI
using namespace std;
double R,P,mj,lj;
double a;
double sjx,ljj;
int main()
{
    int i,j,k,l;
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    scanf("%lf%lf",&R,&P);
    double ans=4*R*sin(P/2)/(3*P);
    printf("%0.6lf\n",ans);
    return(0);
}
