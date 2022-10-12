#include<stdio.h>
#include<stdlib.h>
long y1,m1,d1,y,m,d,week;
int main(){
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    scanf("%ld%ld%ld",&y1,&m1,&d1);
    week=1;y=m=d=1;
    while (1){
          if (y==y1&&m==m1&&d==d1){
              if (week==1)printf("monday\n");
              if (week==2)printf("tuesday\n");
              if (week==3)printf("wednesday\n");
              if (week==4)printf("thursday\n");
              if (week==5)printf("friday\n");
              if (week==6)printf("saturday\n");
              if (week==7)printf("sunday\n");
              return 0;
              }
          d++;week++;
          if (week>=8) week=1;
          if ((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>=32){
              d=1;m++;
              }
          if ((m==4||m==6||m==9||m==11)&&d>=31){
              d=1;m++;
              }
          if (m==2){
              if (y%4==0&&y%100!=0 || y%400==0){
                  if (d>=30){
                      d=1;m++;
                      }
                  }
              else
                  if (d>=29){
                      d=1;m++;
                      }
              }
          if (m>=13){
              m=1;y++;
              }
          }
    return 0;
}
