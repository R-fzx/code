#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.1415926535897932384626433832795

double R,P,dis;//半径、弧度、重心到圆心的距离。 
struct std
{
	double s,r,h;
	//扇形面积\宽\高 
}fan;
double D(double hudu,double mianji)
{
	return sqrt(mianji/2/tan(hudu/2));
}
void Read()
{
	scanf("%lf%lf",&R,&P);
} 
void Work()
{
	fan.s=R*R*P/2;
	//fan.r=cos(R);
	//fan.h=sin(R);
	if(P<=pi)dis=D(P,fan.s);
	else
	{
		dis=cos(P/4);
		//dis=cos(1.57);
		dis*=D(P/2,fan.s/2);
	}
	//fan.s/=2;
	//P/=2;
	//dis=fan.s/tan(P);
	//dis=sqrt(dis);
}
void Write()
{
	double tmp=dis*1e+7;
	long k=(long)tmp%10;
	if(k!=0)dis+=1e-6;
	printf("%.6lf\n",dis);
}
int main()
{
    freopen("ユイ.in","r",stdin);
    freopen("ユイ.out","w",stdout);
    long i,j,k;
    Read();
    Work();
    Write();
    return 0;
}
