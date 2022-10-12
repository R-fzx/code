#include <stdio.h>
#include <stdlib.h>

int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char w[][20]={{"sunday"},{"monday"},{"tuesday"},{"wednesday"},{"thursday"},{"friday"},{"saturday"},{"sunday"}};

int main()
{
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    int y,m,d;
    int dd=0;
    scanf("%d%d%d",&y,&m,&d);
    if (y==2011 && m==9 && d==18)
    {
       printf("sunday\n");
       return 0;
    }
    if (y<2011 || (y==2011 && m<9) || (y==2011 && m==9 && d<18))
    {
       if (y==2011 && m==9 && d<18)
       {
          printf("%s\n",w[7-(18-d)%7]);
          return 0;
       }
       if (y==2011 && m<9)
       {
          dd=17;
          for (int i=8; i>=m+1; i--)
          {
              dd += mon[i];
          }
          dd += (mon[m]-d+1);
          printf("%s\n",w[7-dd%7]);
          return 0;
       }
       if (y<2011)
       {
          dd = 260;
          int sx=2010,sy=12,sz;
          if (((y % 100 == 0 && y % 400 == 0) || ( y % 100!=0 && y % 4 == 0) ) && m == 2)
             sz = 29;
          else
             sz = mon[m];
          while (sx>y)
          {
                if ((sx % 100 == 0 && sx % 400 == 0) || sx % 4 == 0)
                   dd += 366;
                else
                   dd += 365;
                sx--;
          }
          while (sy>m)
          {
                if (((y % 100 == 0 && y % 400 == 0) || ( y % 100!=0 && y % 4 == 0) ) && sy == 2)
                {
                   dd+=29;
                   sy--;
                   continue;
                }
                dd += mon[sy];
                sy--;
          }
          while (sz>=d)
          {
                dd++;
                sz--;
          }
          printf("%s\n",w[7-dd%7]);
          return 0;
       }
    }
    else
    {
       if (y==2011 && m==9 && d>18)
       {
          printf("%s\n",w[(d-18)%7]);
          return 0;
       }
       if (y==2011 && m>9)
       {
          dd=12;
          for (int i=10; i<m; i++)
          {
              dd += mon[i];
          }
          dd += d;
          printf("%s\n",w[dd%7]);
          return 0;
       }
       if (y>2011)
       {
          dd = 104;
          int sx=2012,sy=1,sz=1;
          while (sx<y)
          {
                if ((sx % 100 == 0 && sx % 400 == 0) || sx % 4 == 0)
                   dd += 366;
                else
                   dd += 365;
                sx++;
          }
          while (sy<m)
          {
                if (((y % 100 == 0 && y % 400 == 0) || ( y % 100!=0 && y % 4 == 0) ) && sy == 2)
                {
                   dd+=29;
                   sy++;
                   continue;
                }
                dd += mon[sy];
                sy++;
          }
          while (sz<=d)
          {
                dd++;
                sz++;
          }
          printf("%s\n",w[dd%7]);
          return 0;
       }
    }
}
