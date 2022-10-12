#include <stdio.h>
#include <stdlib.h>

class day_1
{
      public:
         //public_begin
         
         int year,month,data;
         
         void read()
         {
              scanf("%d %d %d",&year,&month,&data);
              return;
         }
         
         //public_end
};

class day:day_1
{
     public:
         //public_begin
         
         int week;
         
         void init()
         {
              year=month=data=1;
              week=1;
         }
         
         void print()
         {
              if (week==1) printf("monday\n");
              if (week==2) printf("tuesday\n");
              if (week==3) printf("wednesday\n");
              if (week==4) printf("thursday\n");
              if (week==5) printf("friday\n");
              if (week==6) printf("saturday\n");
              if (week==7) printf("sunday\n");
              return;
         }
              
         friend bool operator != (day a,day_1 b)
         {
             if (a.year==b.year && a.month==b.month && a.data==b.data)
             return 0;
             else return 1;
         }
         
         friend void operator ++(day &a)
         {
                int x,y,z;
                x=a.year,y=a.month,z=a.data;
                a.week++;
                if (a.week>7) a.week=1;
                
                z++;
                if (y==1 || y==3 || y==5 || y==7 || y==8 || y==10 || y==12)
                {
                   if (z>31) z=1,y++;
                }
                else if (y==4 || y==6 || y==9 || y==11)
                {
                     if (z>30) z=1,y++;
                }
                else
                {
                    if (((x&3)==0 && (x%100!=0)) || (x%400==0))
                    {
                       if (z>29) z=1,y++;
                    }
                    else if (z>28) z=1,y++;
                }
                
                if (y>12) y=1,x++;
                
                a.year=x,a.month=y,a.data=z;
                return;
         }
            
         //public_end
};

day_1 end;
day now;

int main()
{
    freopen("DerProze.in","r",stdin); freopen("DerProze.out","w",stdout);
    end.read();
    now.init();
    while (now!=end) ++now;
    now.print();
    return 0;
}
