#include<stdio.h>
double min(double a,double b)
{
	return a>b?b:a;
}
double max(double a,double b)
{
	return a>b?a:b;
}
double e=0.0000000001;
double dfs(double x,double len,double x1,double y1,double x2,double y2)
{
	if(x>500)return 0;
	if(x1>x2)
	{
		double k;
		k=x1;x1=x2;x2=k;
	}
	if(y1>y2)
	{
		double k;
		k=y1;y1=y2;y2=k;
	}
	double d=len/3.0,r=0;
	if(y2+e>len&&y1<e&&x1-e<-d&&x2+e>d)
		return len+(len*2.0/3.0)*(500.0-x);
	if(y1+e>len||y2<e||x2<-d+e||d-e<x1)
		return 0;
	if(x1-e<0&&x2+e>0)
		r+=max(min(y2,len-d)-max(y1,0.0),0.0);
	x++;
	return dfs(x,d,x1,y1-len+d,x2,y2-len+d)+
	dfs(x,d,-(y1-len+d),x1,-(y2-len+d),x2)+
	dfs(x,d,(y1-len+d),-x1,(y2-len+d),-x2)+r;
}
int main()
{
	double x1,y1,x2,y2;
	freopen("Metamorphosis.in","r",stdin);freopen("Metamorphosis.out","w",stdout);
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	printf("%0.1lf\n",dfs(1,81,x1,y1,x2,y2));
	return 0;
}
