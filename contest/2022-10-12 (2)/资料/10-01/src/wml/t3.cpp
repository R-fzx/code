#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 100000000LL
#define oo 10046

using namespace std;

long long n,f[247][10047]={0};

inline void out(long long *u)
{
       cout<<u[u[0]];

       for(int i=u[0]-1;i>0;i--)
          printf("%08d",u[i]);

       cout<<endl;
}

int main()
{
    freopen("t3.in","r",stdin);
    freopen("t3.out","w",stdout);

    cin>>n;

    //ans=dfs(0,0);

    f[2][1]=1;

    for(long long i=3;i<=n;i++)
    {
		for(int j=1;j<=1000;j++)
			f[i][j]=(f[i-1][j]+f[i-2][j])*(i-1);
   
		for(int j=1;j<=1000;j++)
			if(f[i][j]>=10)
			{
				f[i][j+1]+=f[i][j]/mod;
			
				f[i][j]=f[i][j]%mod;
			}
    }

    int i;

	for(i=1000;i>1;i--)
		if(f[n][i])
			break;

	f[n][0]=i;
/*
    for(int i=0;i<=n;i++)
    {
       cout<<i<<' ';
    
       out(f[i]);
    }
*/
    out(f[n]);

    return 0;
}
//10 1334961
