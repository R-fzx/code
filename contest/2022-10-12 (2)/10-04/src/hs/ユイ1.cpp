#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Read();
void Count();
void Write();
int main()
{
	freopen("ユイ.in","r",stdin);
	freopen("ユイ.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

double len,rou;
const double pi=3.14159265358979323846;
void Read()
{
	scanf("%lf%lf",&len,&rou);
	return;
}

double sum,mid,ans;
void Pre_sum()
{
	sum=rou*len*len*0.5;
	return;
}


bool Half_cut()
{
	mid=len*cos(rou*0.5);
	double val=mid*len*cos(rou*0.5);
	if( val*2+1e-8>=sum )	return true;
	else					return false;
}

bool Check(double val)
{
	double x=val-sum;
	if(x<0)	x=-x;
	return x<1e-9;
}

void Cnt1(double star,double end)
{
	double ta=tan(rou*0.5);
	ans=(star+end)*0.5;
	for(double l=star,r=end;;ans=(l+r)*0.5)
		if( Check(ans*ta*ans*2) )		return;
		else if( ans*ta*ans*2 > sum )	r=ans;
		else							l=ans;
}

void Cnt2(double star,double end)
{
	//printf(" Cnt2(%lf,%lf)\n",star,end);
	ans=(star+end)*0.5;
	for(double l=star,r=end;;ans=(l+r)*0.5)
	{
		double theat=acos(ans/len);
		double val=theat*len*len - ans*ans*tan(theat);
		//printf("%lf,%lf,  %lf\n",ans,val,sum);
		//system("pause");
		if( Check(val*2) )	return;
		if( val*2>sum )		l=ans;
		else				r=ans;
	}
}

void Count()
{
	Pre_sum();
	if( rou-1e-6>=pi )		Cnt2(0,len);
	else if( Half_cut() )	Cnt1(0,mid);
	else					Cnt2(mid,len);
	return;
}

void Write()
{
	printf("%lf\n",ans);
	return;
}

