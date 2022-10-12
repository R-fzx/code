#include <stdio.h>
#include <math.h>
#define M 1e-8
#define pi 3.1415926535
double pr(double r,double deg)
{
	if (deg>pi) deg=2*pi-deg;
	if (fabs(deg-pi)<M) return(2*r);
	return(r*sin(deg)/sin((pi-deg)/2));
}
int main()
{
	FILE *f1=fopen("ユイ.in","r");
	FILE *f2=fopen("ユイ.out","w");
	double r,d;
	fscanf(f1,"%lf%lf",&r,&d);
	fprintf(f2,"%lf",2*r*pr(r,d)/3/(r*d));
	return 0;
}
