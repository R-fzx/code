#include<stdio.h>
#include<stdlib.h>
long Y,M,D,y,m,d,ans;
bool flag;
long days[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
char str[][20]={{"sunday"},{"monday"},{"tuesday"},{"wednesday"},{"thursday"},{"friday"},{"saturday"}};
int main()
{
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    long i,j,k;
    scanf("%ld%ld%ld",&Y,&M,&D);
    y=2011,m=10,d=1,ans=6;
    if(Y>y||(Y==y&&M>m)||(Y==y&&M==m&&D>d))
    {
		while(1)
		{
			ans=(ans+1)%7;
			d++;
			days[2]=28;
			if(y%100==0)
			{
				if(y%400==0)days[2]=29;
			}
			else if(y%4==0)days[2]=29;
			//if(y==2060)
			//m++,m--;
			if(d>days[m])
			{
				d=1;
				m++;
				if(m>12)
				{
					y++;
					m=1;
				}
			}
			if(d==D&&M==m&&Y==y){printf("%s\n",str[ans]);return 0;}
		}
	}
	else
	{
		if(d==D&&M==m&&Y==y){printf("%s\n",str[ans]);return 0;}
		while(1)
		{
			ans=(ans-1+7)%7;
			d--;
			days[2]=28;
			if(y%100==0)
			{
				if(y%400==0)days[2]=29;
			}
			else if(y%4==0)days[2]=29;
			if(d==0)
			{
				m--;
				if(m<1)
				{
					m=12;
					y--;
				}
				d=days[m];
			}
			if(d==D&&M==m&&Y==y){printf("%s\n",str[ans]);return 0;}
		}
	}
    return 0;
}
