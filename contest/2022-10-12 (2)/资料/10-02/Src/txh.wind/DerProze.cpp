#include<stdio.h>
FILE *fin,*fout;
inline int mday(int year,int month)
{
	if((year%400==0 || (year%4==0 && year%100!=0)) && month==2)
		return 29;
	switch(month)
	{
		case 2:return 28;
		case 4:
		case 6:
		case 9:
		case 11:return 30;
		default:return 31;
	}
}
inline int yday(int year)
{
	if(year%400==0 || (year%4==0 && year%100!=0))
		return 366;
	return 365;
}
int main()
{
	int i,j,y,m,d,ans;
	fin=fopen("DerProze.in","r");
	fout=fopen("DerProze.out","w");
	fscanf(fin,"%d%d%d",&y,&m,&d);
	if(y>=1900)
	{
		ans=1;
		for(i=1900;i<y;++i)
		{
			ans+=yday(i);
			ans%=7;
		}
		for(i=1;i<m;++i)
		{
			ans+=mday(y,i);
			ans%=7;
		}
		ans+=(d-1);
		ans%=7;
	}
	else
	{
		ans=0;
		for(i=y+1;i<1900;++i)
		{
			ans+=yday(i);
			ans%=7;
		}
		for(i=m+1;i<13;++i)
		{
			ans+=mday(y,i);
			ans%=7;
		}
		ans+=(mday(y,m)-d+1);
		ans%=7;
		ans=1-ans;
		if(ans<0)
			ans+=7;
	}
	switch(ans)
	{
		case 0:
			fprintf(fout,"sunday");
			break;
		case 1:
			fprintf(fout,"monday");
			break;
		case 2:
			fprintf(fout,"tuesday");
			break;
		case 3:
			fprintf(fout,"wednesday");
			break;
		case 4:
			fprintf(fout,"thursday");
			break;
		case 5:
			fprintf(fout,"friday");
			break;
		default:
			fprintf(fout,"saturday");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
