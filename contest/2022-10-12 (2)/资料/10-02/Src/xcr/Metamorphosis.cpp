#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int sgn(double a)
{
	if(fabs(a)<1e-12)
		return 0;
	if(a<0)
		return -1;
	return 1;
}
double solve(int n,double a,double x1,double y1,double x2,double y2)
{
	if(sgn(y2)<=0||sgn(y1-a)>=0||sgn(x2*3+a)<=0||sgn(x1*3-a)>=0)
		return 0;
	if(sgn(y1)<=0&&sgn(y2-a)>=0)
		if(sgn(x1*3+a)<=0&&sgn(x2*3-a)>=0)
			return a+(n-1)*a*2.0/3.0;
		else
			if((sgn(x1*3+a)<=0&&sgn(x2)==0)||(sgn(x2*3-a)>=0&&sgn(x1)==0))
				return a+(n-1)*a/3.0;
	double ans=0;
	if(sgn(x1)<=0&&sgn(x2)>=0&&sgn(min(a*2.0/3.0,y2)-max(0.0,y1))>=0)
		ans+=min(a*2.0/3.0,y2)-max(0.0,y1);
	ans+=solve(n-1,a/3,y1-a*2/3,-x2,y2-a*2/3,-x1);
	ans+=solve(n-1,a/3,x1,y1-a*2/3,x2,y2-a*2/3);
	ans+=solve(n-1,a/3,a*2/3-y2,x1,a*2/3-y1,x2);
	return ans;
}
int main()
{
	int x1,y1,x2,y2;
	freopen("Metamorphosis.in","r",stdin);
	freopen("Metamorphosis.out","w",stdout);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%.1lf\n",solve(500,81,x1,y1,x2,y2));
	return 0;
}
