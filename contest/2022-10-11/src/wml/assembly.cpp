#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,k;

double A,B[47],L[47];

double sum=1.0,ans=0.0;

double sum2=1.0;

double s_wl[47]={0.0};
/*
inline void dfs(int i,int tmp,double now_s)
{
       if(tmp>k)
         return;

       if(i>=n)
       {
         if(now_s>ans)
           ans=now_s;
       
         return;
       }

       dfs(i,tmp+1,now_s/L[i]*(L[i]+0.1));

       dfs(i+1,tmp,now_s);
}
*/
int main()
{
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);

    cin>>n>>k>>A;

    for(int i=1;i<=n;i++)
    {
       cin>>B[i]>>L[i];
    
       s_wl[i]=s_wl[i-1]+B[i];
    
       L[i]/=100;
    
       for(int j=1;j<i;j++)
          if(L[j]<L[i])
            swap(L[j],L[i]),
          
            swap(B[j],B[i]);
    }

    for(int i=1;i<=n/2+1;i++)
    {
       sum*=L[i];
    }

    for(int i=n/2+2;i<=n;i++)
    {
       sum2*=1-L[i];
    }

    while(k--)
    {
         double max_now=0.0;
         int max_len=0;
    
         for(int i=1;i<=n/2+1;i++)
         {
            double now=(sum/L[i])*min(L[i]+0.1,1.0);
         
            if(now>max_now)
              max_now=now,
            
              max_len=i;
         }
    
         L[max_len]+=0.1;
    
         sum=max_now;
    }

    //ans=sum;

    //dfs(1,0,sum);

    for(int i=1;i<=n/2+1;i++)
    {
       double now=(1-L[i])*sum2*(A/(A+B[i]+s_wl[n]-s_wl[n/2+1]));
    
       if(ans<now)
         ans=now;
    }

    ans+=sum;

    printf("%.6lf\n",ans);

    return 0;
}
