#include<stdio.h>
FILE *fin,*fout;
const char ans[7][20]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
const int now=0,cyear=2011,cmonth=10,cday=2;
int tyear,tmonth,tday;
inline int abs(int x){return x>0?x:-x;}
inline bool isrn(int year){return ((year%4==0 && year%100!=0)|| year%400==0);}
inline int getdays(int year,int month)
{
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:return 31;
		case 4:
		case 6:
		case 9:
		case 11:return 30;
		case 2:return (isrn(year)?29:28);
	}
	return -1;
}
int main()
{
	fin=fopen("DerProze.in","r");
	fout=fopen("DerProze.out","w");
	fscanf(fin,"%d%d%d",&tyear,&tmonth,&tday);
	int i,cdays=0,tdays=0,tans;
	for (i=1;i<cyear;++i) cdays+=(isrn(i))?366:365;
	for (i=1;i<cmonth;++i) cdays+=getdays(cyear,i);
	cdays+=cday;
	for (i=1;i<tyear;++i) tdays+=(isrn(i))?366:365;
	for (i=1;i<tmonth;++i) tdays+=getdays(tyear,i);
	tdays+=tday;
	tans=now+((tdays-cdays)%7);
	if (tans<0) tans+=7;
	fprintf(fout,"%s\n",ans[tans]);
	fclose(fin);
	fclose(fout);
	return 0;
}
