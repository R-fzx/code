#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define min_line 1e-10

using namespace std;

int x1,yy,x2,y2;

inline double dg(int,double,double,double,double,double);

int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);

    scanf("%d%d%d%d",&x1,&yy,&x2,&y2);

    printf("%.1lf\n",dg(500,81.0,(double)x1,(double)yy,(double)x2,(double)y2));
}

inline int pd(double k)
{
	if(fabs(k)<min_line)
		return 0;

	if(k<0)
		return -1;

	return 1;
}

inline double dg(int n,double a,double x1,double yy,double x2,double y2)
{
       double tmp=0;

       if(pd(y2)<=0 || pd(yy-a)>=0 || pd(x2*3+a)<=0 || pd(x1*3-a)>=0 || n<=0)
         return 0;

       if(pd(yy)<=0 && pd(y2-a)>=0)
       {
         if(pd(x1*3+a)<=0 && pd(x2*3-a)>=0)
           return a+(n-1)*a*2.0/3.0;
       
         else if((pd(x1*3+a)<=0 && pd(x2)==0) || (pd(x2*3-a)>=0 && pd(x1)==0))
           return a+(n-1)*a/3.0;
       }

       tmp+=dg(n-1,a/3.0,yy-a*2.0/3.0,-x2,y2-a*2.0/3.0,-x1);
       tmp+=dg(n-1,a/3.0,x1,yy-a*2.0/3.0,x2,y2-a*2.0/3.0);
       tmp+=dg(n-1,a/3.0,a*2.0/3.0-y2,x1,a*2.0/3.0-yy,x2);

       if(pd(x1)<=0&&pd(x2)>=0 && pd(min(a*2.0/3.0,y2)-max(0.0,yy))>=0)
         tmp+=min(a*2.0/3.0,y2)-max(0.0,yy);

       return tmp;
}
