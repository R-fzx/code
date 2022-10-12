#include<stdio.h>
#include<stdlib.h>
int s;
int year,month,day;
int y,m,d;
int main()
{
    int i,j;
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    
    s=6;
    for(year=2000;year>0;)
    {
     year--;
     if(year%400==0||year%100!=0&&year%4==0)
      s=(s+7-2)%7;
     else
      s=(s+7-1)%7;
    }
    scanf("%d%d%d",&year,&month,&day);
    
    for(y=0;y<year;y++)
    {
     if(y%400==0||y%100!=0&&y%4==0)
     {
      s=(s+7+2)%7;
     }
     else
      s=(s+7+1)%7;
    }
    
    for(m=1;m<=month-1;m++)
    {
     if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
     {
      s=(s+31)%7;
     }
     else
     if(m==4||m==6||m==9||m==11)
     {
      s=(s+30)%7;
     }
     else
     {
      if(y%400==0||y%100!=0&&y%4==0)
       s=(s+29)%7;
      else
       s=(s+28)%7;
     }
    }
    s=(s+day-1)%7;
    if(s==0)
     printf("sunday\n");
    if(s==1)
     printf("monday\n");
    if(s==2)
     printf("tuesday\n");
    if(s==3)
     printf("wednesday\n");
    if(s==4)
     printf("thursday\n");
    if(s==5)
     printf("friday\n");
    if(s==6)
     printf("saturday\n");
    return 0;
}
