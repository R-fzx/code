#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 2147483647

using namespace std;

long long map[1047][1047],ans=1,jl[1047],sp[1047];

int n,m,cant[1047];

void SPFA();

//inline void dfs(int);

int main()
{
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
       int a,b,c;
    
       scanf("%d%d%d",&a,&b,&c);
    
       if(a==b)
         continue;
    
       if(map[a][b]==0)
         map[a][b]=map[b][a]=c;
    
       else
         map[b][a]=map[a][b]<?=c;
    }

    SPFA();

    //dfs(1);

    for(int i=2;i<=n;i++)
       if(jl[i]!=0)
       {
         ans*=jl[i];
       
         ans%=mod;
       }

    cout<<ans<<endl;

    return 0;
}

void SPFA()
{
     int l=0,r=0,s[100047]={0},hash[1047]={0};

     s[0]=1;

     memset(sp,127,sizeof(sp));

     sp[1]=0;

     hash[1]=1;

     while(l<=r)
     {
          int k=s[l];
     
          for(int i=1;i<=n;i++)
          {
             if(map[k][i])
             {
               if(sp[i]>sp[k]+map[k][i])
               {
                 sp[i]=sp[k]+map[k][i];
               
                 jl[i]=1;
               
                 if(!hash[i])
                 {
                   s[++r]=i;
                 
                   hash[i]=1;
                 }
               }
             
               else
                 if(sp[i]==sp[k]+map[k][i])
                   jl[i]++;
             }
          }
     
          hash[k]=0;
     
          l++;
     }
}
/*
inline void dfs(int i)
{
       //int u=1;

       cant[i]=1;

       for(int j=1;j<=n;j++)
          if(jl[i][j] && !cant[j])
          {
            dfs(j);
          
            ans*=jl[i][j];
          }

       cant[i]=0;

       //return u;
}
*/
