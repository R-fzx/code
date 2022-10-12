#include <stdio.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Debug 0

int Mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char weekday[8][20]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

void Leap(int year)
{
	if(year%400==0)
	{
		Mon[2]=29;
		return;
	}
	if(year%4==0&&year%100!=0)
	{
		Mon[2]=29;
		return;
	}
	Mon[2]=28;
	return;
}

#define OpenFile 1
int main()
{
	#if OpenFile
	freopen("DerProze.in","r",stdin);
	freopen("DerProze.out","w",stdout);
	#endif
	int i,j;
	int year,month,day;
	scanf("%d%d%d",&year,&month,&day);
	int t=0;
	for(i=1;i<=year;i++)
	{
		Leap(i);
		for(j=1;j<=12;j++)
		{
			if(i==year&&month==j)
			{
				t+=day;
				break;
			}
			t+=Mon[j];
		}
		t=(t-1)%7+1;
	}
	printf("%s\n",weekday[t]);
	return 0;
}
