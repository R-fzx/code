#include <cstdio>
#include <cstdlib>

using namespace std ;

namespace date_ctl
{
	const char days[7][10]= {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
	int mon[13]= {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	struct date
	{
		int yy, mm, dd, day;
		bool operator < (date b)
		{
			return yy < b.yy || yy == b.yy && mm < b.mm || yy ==  b.yy && mm == b.mm && dd < b.dd;
		}
		bool operator == (date b)
		{
			return yy == b.yy && mm == b.mm && dd == b.dd ;
		}
		void operator ++ ()
		{
			++ dd;
			++ day;
			if(day > 6)
				day= 0;
			if(dd > mon[mm])
			{
				mm ++ ; 
				dd = 1;
			}
			if(mm > 12)
			{
				yy ++ ; 
				mm = 1;
				if(!(yy % 400) || ((yy % 100) && !(yy % 4)))
					mon[2]= 29;
				else
					mon[2]= 28;
			}
		}
		void operator -- ()
		{
			-- dd;
			-- day;
			if(day < 0)
				day= 6;
			if(dd <= 0)
			{
				mm --; 
				dd = mon[mm];
			}
			if(mm <= 0)
			{
				yy -- ; 
				mm = 12;
				if(!(yy % 400) || ((yy % 100) && !(yy % 4)))
					mon[2]= 29;
				else
					mon[2]= 28;
			}
		}
	};
}

void init()
{
	freopen("DerProze.in", "r", stdin);
	freopen("DerProze.out", "w", stdout);
	date_ctl :: date now, target;
	
	now.yy = 2011 ;
	now.mm = 10;
	now.dd = 2;
	now.day = 6;
	
	scanf("%d%d%d", &target.yy, &target.mm, &target.dd);
	if(now < target)
		for(; !(now == target); ++ now);
	else
		for(; !(now == target); -- now);
		
	printf("%s\n", date_ctl :: days[now.day]);
}

int main()
{
	init();
	return 0 ;
}
