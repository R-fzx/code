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

double len,rou,ans;
const double pi=3.14159265358979323846;
void Read()
{
	scanf("%lf%lf",&len,&rou);
	return;
}


void Count()
{
	double l1=len*rou;
	double theat=rou;
	if( theat>pi )	theat=2*pi-theat;
	double l2=len*sin(theat*0.5)*2;
	ans=2*len*l2/(3*l1);
	return;
}

void Write()
{
	printf("%lf\n",ans);
	return;
}

