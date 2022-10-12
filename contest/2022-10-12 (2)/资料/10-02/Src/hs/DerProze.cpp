#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Read();
void Count();
void Write();
int main()
{
	freopen("DerProze.in","r",stdin);
	freopen("DerProze.out","w",stdout);
	Read();
	Count();
	Write();
	//system("pause");
	return 0;
}

int year,month,day;
void Read()
{
	scanf("%d%d%d",&year,&month,&day);
	return;
}


char ans[110]={0};
//			 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void Count()
{
	int star=2000,d=6;
	for(;star<year;star++)
		d=( d + (star%4==0) )%7+1;
	while( star>year )
	{
		star--;
		d=( d + 5 - (star%400==0||star%100&&star%4==0 ) )%7+1;
	}
	if( star%400==0||star%100&&star%4==0)	mon[2]++;
	for(int m=1;m<month;m++)
		for(int da=1;da<=mon[m];da++,d++);
	for(int da=1;da<day;da++,d++);
	d=(d+6)%7+1;
	switch(d)
	{
		case 1: strcpy(ans,"monday"		);	break;
		case 2:	strcpy(ans,"tuesday"	);	break;
		case 3:	strcpy(ans,"wednesday"	);	break;
		case 4:	strcpy(ans,"thursday"	);	break;
		case 5:	strcpy(ans,"friday"		);	break;
		case 6:	strcpy(ans,"saturday"	);	break;
		case 7:	strcpy(ans,"sunday"		);	break;
		default: break;
	}
	return;
}

void Write()
{
	printf("%s\n",ans);
	return;
}

