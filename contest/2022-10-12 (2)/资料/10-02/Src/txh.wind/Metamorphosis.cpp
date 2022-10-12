#include<stdio.h>
FILE *fin,*fout;
const double e=1e-12;
double min(double a,double b)
{
	return a<b?a:b;
}
double max(double a,double b)
{
	return a>b?a:b;
}
double work(double len,double x1,double y1,double x2,double y2,double time)
{
	if(time+e>500.0)
		return 0;
	double d,l=0;
	if(x1>x2)
	{
		d=x1;
		x1=x2;
		x2=d;
	}
	if(y1>y2)
	{
		d=y1;
		y1=y2;
		y2=d;
	}
	d=len/3.0;
	if(y2+e>len && y1<e && x2+e>d && x1-e<-d)
		return len+len*2.0/3.0*(500.0-time);
	if(y1+e>len || y2<e || x1+e>d || x2-e<-d)
		return 0;
	if(x1-e<0 && x2+e>0)
		l+=max(min(y2,len-d)-max(y1,0.0),0.0);
	++time;
	return
	work(d,x1,y1-len+d,x2,y2-len+d,time)
	+work(d,y1-len+d,-x1,y2-len+d,-x2,time)
	+work(d,-(y1-len+d),x1,-(y2-len+d),x2,time)
	+l;
}
int main()
{
	double x1,y1,x2,y2;
	fin=fopen("Metamorphosis.in","r");
	fout=fopen("Metamorphosis.out","w");
	fscanf(fin,"%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	fprintf(fout,"%.1lf",work(81.0,x1,y1,x2,y2,1.0));
	fclose(fin);
	fclose(fout);
	return 0;
}
