#include<stdio.h>
char data[7][20]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
long mon1[13]={0,0,3,1,3,2,3,2,3,3,2,3,2},mon2[13]={0,0,3,0,3,2,3,2,3,3,2,3,2};
int main()
{
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    long year,month,day,i,j,k,change;
    scanf("%d%d%d",&year,&month,&day);
    change=(year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400;
    change%=7;
    if(year%4!=0 || (year%100==0 && year%400!=0))
        for(i=month;i>=2;i--)
        {
            change+=mon2[i];
            change%=7;
        }
    else
        for(i=month;i>=2;i--)
        {
            change+=mon1[i];
            change%=7;
        }
    change+=day;
    change%=7;
    printf("%s\n",data[change]);
    return 0;
}
