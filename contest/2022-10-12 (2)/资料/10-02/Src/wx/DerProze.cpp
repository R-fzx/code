#include<stdio.h>
#include<stdlib.h>
int N,Y,R,d=-1;
char week[7][50]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
void sou(int a,int b,int c,int n,int y,int r)
{
     int i,j,k;
     for(i=a;i<=n;i++)
     {
      if(i==a)j=b;
      else j=1;
      for(;j<=12;j++)
      {
       int limit=day[j-1];
       if(j==2&& (i%100==0&&i%400==0||i%100!=0&&i%4==0))
       limit=29;
       if(i==a&&j==b)k=c;
       else k=1;
       for(;k<=limit;k++)
       {
        d++;//printf("%d %d %d %d\n",i,j,k,d);
        if(i==n&&j==y&&k==r)return;
       }
      }
     }
}
int main()
{
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    int i,j,k;
    scanf("%d%d%d",&N,&Y,&R);
    if(N>2011||N==2011&&Y>9||N==2011&&Y==9&&R>18)
     {
      sou(2011,9,18,N,Y,R);
      printf("%s",week[(6+d%7)%7]);
     }
    else 
    {
     sou(N,Y,R,2011,9,18);
     printf("%s",week[(6-d%7)%7]);
     }
     return 0;
}
