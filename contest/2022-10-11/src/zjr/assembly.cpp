#include<stdio.h>
#include<string.h>
int n,k,a,pre[9],b[9],l[9];
double Ans;
void calc()
{
     int i,j,sv[9],js;
     double tmp1,tmp2,ans=0;
     memcpy(sv,l,sizeof(l));
     for(i=1;i<=n;i++)
     {
       l[i]+=pre[i]*10;
       if(l[i]>100)l[i]=100;
     }
     for(i=0;i<1<<n;i++)
     {
       tmp1=1;
       js=0;
       for(j=1;j<=n;j++)
       {
         if(i&1<<j-1)
         {
           js++;
           tmp1*=(double)l[j]/100.0;
         }
         else tmp1*=(double)(100-l[j])/100.0;
       }
       if(js*2>n)
       {
         ans+=tmp1;
         continue;
       }
       tmp2=0;
       for(j=1;j<=n;j++)
       {
         if(i&1<<j-1)continue;
         tmp2+=b[j];
       }
       tmp2=(double)a/((double)a+tmp2);
       tmp1*=tmp2;
       ans+=tmp1;
     }
     memcpy(l,sv,sizeof(sv));
     if(ans>Ans)Ans=ans;
}
void search(int now,int last)
{
     if(now==n)
     {
       pre[now]=last;
       calc();
       return;
     }
     int i;
     for(i=0;i<=last;i++)
     {
       pre[now]=i;
       search(now+1,last-i);
     }
}
int main()
{
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    int i;
    scanf("%d%d%d",&n,&k,&a);
    for(i=1;i<=n;i++)scanf("%d%d",&b[i],&l[i]);
    search(1,k);
    printf("%.6lf\n",Ans);
}
