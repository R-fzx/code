#include<stdio.h>
int n,m,t,ans;
inline int year(int x)
{
    if((x%4==0)&&((x%100!=0)||(x%400==0))) return 366;
    return 365;
}
inline int month(int x)
{
    if((x==1)||(x==3)||(x==5)||(x==7)||(x==8)||(x==10)||(x==12)) return 31;
    if((x==4)||(x==6)||(x==9)||(x==11)) return 30;
    if((n%4==0)&&((n%100!=0)||(n%400==0))) return 29;
    return 28;
}
int main()
{
    freopen("DerProze.in","r",stdin);
    freopen("DerProze.out","w",stdout);
    int i,j,k;
    scanf("%d%d%d",&n,&m,&t);
    if(n>=2007) for(i=2007;i<n;i++) ans+=year(i);
    else for(i=2006;i>=n;i--) ans-=year(i);
    for(i=1;i<m;i++) ans+=month(i);
    ans+=t;
    ans=(ans%7+7)%7;
    if(ans==1) printf("monday\n");
    if(ans==2) printf("tuesday\n");
    if(ans==3) printf("wednesday\n");
    if(ans==4) printf("thursday\n");
    if(ans==5) printf("friday\n");
    if(ans==6) printf("saturday\n");
    if(ans==0) printf("sunday\n");
    return 0;
}
    
