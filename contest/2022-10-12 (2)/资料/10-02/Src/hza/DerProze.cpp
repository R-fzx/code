#include<stdio.h>

int year,month,day;
int month_num[2][13]=
{
	0,31,28,31,30,31,30,31,31,30,31,30,31,
	0,31,29,31,30,31,30,31,31,30,31,30,31
};

int run_year(int n)
{
	if(n%100!=0&&n%4==0)
		return 1;
	else if(n%400==0)
		return 1;
	return 0;
}

void init()
{
	scanf("%d %d %d\n",&year,&month,&day);
}

void doit()
{
	int ny=2000,nm=1,nd=1,now=6;
	if(year<=ny)
	{
		for(int j=ny-1;j>=year;j--)
		{
			if(run_year(j))
			{
				now-=366%7;
				now=(now+28)%7;
			}else
			{
				now-=365%7;
				now=(now+28)%7;
			}
		}
	}else if(year>=ny)
	{
		for(int j=ny;j<year;j++)
		{
			if(run_year(j))
			{
				now+=366%7;
				now=(now+28)%7;
			}else
			{
				now+=365%7;
				now=(now+28)%7;
			}
		}
	}
	for(int i=nm;i<month;i++)
	{
		now+=month_num[run_year(year)][i]%7;
		now=now%7;
	}
	now+=(day-1)%7;
	now=now%7;
	nm=day;nm=month;
	if(now==0)
	{
		printf("sunday");
	}else if(now==1)
	{
		printf("monday");
	}else if(now==2)
	{
		printf("tuesday");
	}else if(now==3)
	{
		printf("wednesday");
	}else if(now==4)
	{
		printf("thursday");
	}else if(now==5)
	{
		printf("friday");
	}else if(now==6)
	{
		printf("saturday");
	}
}

int main()
{
	freopen("DerProze.in","r",stdin);
	freopen("DerProze.out","w",stdout);
	init();
	doit();
}
