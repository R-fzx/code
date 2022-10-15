#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int N,K,A,num[10];
double ans=0,ans2=0;
bool ok[100];
struct pp
{
       double pk,dog;
}z[100];
int cmp(pp a,pp b)
{
    if(a.pk!=b.pk)
    ;//return a.dog<b.dog;
    return a.pk>b.pk;
}
void sou(int now,double f)
{
     int i,j;
     double k;
     if(now>N)
     {
      k=0;
      j=0;
      for(i=1;i<=N;i++)
      if(!ok[i]){
                 k+=z[i].pk;
                 j++;
                 }
      double AB=k+(double)A;
      if(j*2>=N)f*=(double)A/(double)(AB);
      ans+=f;
      
      return;
     }
     ok[now]=1;
     sou(now+1,f*z[now].dog/100.0);
     ok[now]=0;
     sou(now+1,f*(1.0-z[now].dog/100.0));
}
void dfs(int x,int d)
{
     int i,j,k;
     if(x>N)
     {
            for(i=1;i<=N;i++)
            {
             z[i+N]=z[i];
             z[i].dog+=10.0*num[i];
            }
            ans=0;
            sou(1,1.0);
            if(ans>ans2)ans2=ans;
            for(i=1;i<=N;i++)
             z[i]=z[i+N];
            return ;
     }
     
     for(i=0;i<=d&&(100-(int)z[x].dog)>=10*i;i++)
     {
      num[x]=i;
      dfs(x+1,d-i);
     }
}
int main()
{
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    int i,j,k;
    scanf("%d%d%d",&N,&K,&A);
    for(i=1;i<=N;i++)
    {
     scanf("%lf%lf",&z[i].pk,&z[i].dog);
    }
    dfs(1,K);
    printf("%.6lf",ans2);
    return 0;
}
