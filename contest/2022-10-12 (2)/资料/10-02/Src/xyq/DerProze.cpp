#include<stdio.h>
int y,m,d,Y,M,D,xq;
inline bool run(int a)
{
       if(a%4==0&&a%100!=0||a%400==0)return 1;
       return 0;
}
int main()
{
    freopen("derproze.in","r",stdin);
    freopen("derproze.out","w",stdout);
    scanf("%d%d%d",&Y,&M,&D);
    y=2011;
    m=10;
    d=2;
    xq=7;
    if(Y==y&&M==m&&D==d)
    {
      printf("sunday\n");
      return 0;
    }
    if(Y>y||Y==y&&M>m||Y==y&&M==m&&D>d)
    {
      while(1)
      {
        d++;
        xq++;
        if(xq>7)xq=1;
        if(d==29&&m==2&&run(y)==0)
        {
          d=1;
          m=3;
        }
        else if(d==30&&m==2&&run(y))
        {
          d=1;
          m=3;
        }
        else if(d==31&&(m==4||m==6||m==9||m==11))
        {
          d=1;
          m++;
        }
        else if(d==32)
        {
          d=1;
          m++;
        }
        if(m>12)
        {
          m=1;
          y++;
        }
        if(y==Y&&m==M&&d==D)break;
      }
      if(xq==1)printf("monday\n");
      else if(xq==2)printf("tuesday\n");
      else if(xq==3)printf("wednesday\n");
      else if(xq==4)printf("thursday\n");
      else if(xq==5)printf("friday\n");
      else if(xq==6)printf("saturday\n");
      else printf("sunday\n");
    }
    else
    {
      while(1)
      {
        d--;
        xq--;
        if(xq<1)xq=7;
        if(d==0)
        {
          m--;
          if(m==2&&run(y))d=29;
          else if(m==2&&run(y)==0)d=28;
          else if(m==4||m==6||m==9||m==11)d=30;
          else d=31;
        }
        if(m==0)
        {
          y--;
          m=12;
        }
        if(y==Y&&m==M&&d==D)break;
      }
      if(xq==1)printf("monday\n");
      else if(xq==2)printf("tuesday\n");
      else if(xq==3)printf("wednesday\n");
      else if(xq==4)printf("thursday\n");
      else if(xq==5)printf("friday\n");
      else if(xq==6)printf("saturday\n");
      else printf("sunday\n");
    }
    return 0;
}
