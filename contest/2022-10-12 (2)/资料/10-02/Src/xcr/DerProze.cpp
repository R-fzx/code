#include<stdio.h>
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][11]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
bool run(int yy)
{
	return yy%4==0&&(yy%100!=0||yy%400==0);
}
int main()
{
	int yy,mm,dd,i,ans=5;
	freopen("DerProze.in","r",stdin);
	freopen("DerProze.out","w",stdout);
	scanf("%d%d%d",&yy,&mm,&dd);
	yy-=2011;
	if(yy>0)
		for(i=0;i<yy;++i)
			ans=(ans+365+run(i+2011))%7;
	else
		for(i=-1;i>=yy;--i)
		{
			ans=(ans-365-run(i+2011))%7;
			if(ans<0)
				ans+=7;
		}
	for(i=1;i<mm;++i)
	{
		ans=(ans+month[i])%7;
		if(i==2&&run(yy+2011))
			ans=(ans+1)%7;
	}
	ans=(ans+dd-1)%7;
	printf("%s\n",week[ans]);
	return 0;
}
