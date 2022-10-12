#include<stdio.h>
#include<stdlib.h>
main()
{
      freopen("DerProze.in","r",stdin);
      freopen("DerProze.out","w",stdout);
      int y,m,d;
      long int i,sum=0,t=0;
      scanf("%d%d%d",&y,&m,&d);
      for (i=1;i<y;i++)
        if (((i%4==0)&&(i%100!=0))||(i%400==0))
           sum=sum+366;
        else
           sum=sum+365;
      if (((i%4==0)&&(i%100!=0))||(i%400==0))
      {
         if (m==1)
        sum+=0;  
      else if (m==2)
        sum+=31;
      else if (m==3)
        sum+=29+31; 
        else if (m==4)
          sum+=31+29+31;
        else if (m==5)
          sum+=30+31+29+31;
        else if (m==6)
          sum+=31+30+31+29+31;
        else if (m==7)
          sum+=30+31+30+31+29+31;
        else if (m==8)
          sum+=31+30+31+30+31+29+31;
        else if (m==9)
          sum+=31+31+30+31+30+31+29+31;
        else if (m==10)
          sum+=30+31+31+30+31+30+31+29+31;
        else if (m==11)
          sum+=31+30+31+31+30+31+30+31+29+31;
        else if (m==12)
          sum+=30+31+30+31+31+30+31+30+31+29+31;
      }
      else
      {
           if (m==1)
        sum+=0;  
      else if (m==2)
        sum+=31;
      else if (m==3)
        sum+=28+31; 
        else if (m==4)
          sum+=31+28+31;
        else if (m==5)
          sum+=30+31+28+31;
        else if (m==6)
          sum+=31+30+31+28+31;
        else if (m==7)
          sum+=30+31+30+31+28+31;
        else if (m==8)
          sum+=31+30+31+30+31+28+31;
        else if (m==9)
          sum+=31+31+30+31+30+31+28+31;
        else if (m==10)
          sum+=30+31+31+30+31+30+31+28+31;
        else if (m==11)
          sum+=31+30+31+31+30+31+30+31+28+31;
        else if (m==12)
          sum+=30+31+30+31+31+30+31+30+31+28+31;
        }
        /*switch (m)
        {
            case 2:sum+=31;
            case 3:if (((i%4==0)&&(i%100!=0))||(i%400==0)) sum+=29; else sum+=28;
            case 4:sum+=31;
            case 5:sum+=30;
            case 6:sum+=31;
            case 7:sum+=30;
            case 8:sum+=31;
            case 9:sum+=31;
            case 10:sum+=30;
            case 11:sum+=31;
            case 12:sum+=30;
            default: sum+=0;
        }*/
        sum+=d-1;
        //printf("%d",sum);
        t=sum%7;
        if (t==0) printf("monday");
        else if (t==1) printf("tuesday");
        else if (t==2) printf("wednesday");
        else if (t==3) printf("thursday");
        else if (t==4) printf("friday");
        else if (t==5) printf("saturday");
        else if (t==6) printf("sunday");
        
}
