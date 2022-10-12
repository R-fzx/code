#include<stdio.h>
#include<math.h>

double solve(double r,double theta)
{
	if(theta<1e-8)
		return r*2/3.0;
	double ans=solve(r,theta/2)*cos(theta/4);
	return ans;
}
int main()
{
	double r,p,min,max;
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    scanf("%lf%lf",&r,&p);
    printf("%.6lf\n",solve(r,p));
    return 0;
}
