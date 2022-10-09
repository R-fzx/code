//seventeen
#include<bits/stdc++.h>
using namespace std;

const int NUM=205;

int n;
double ans;
int fx[NUM],fy[NUM],dis[NUM],dp[NUM][NUM*NUM*2];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline void walk(int dis[])
{	
	int numtemp=NUM*NUM;

	for(int i=0;i<=n;++i)
        for(int j=-numtemp;j<numtemp;++j)
            dp[i][j+numtemp]=0;
    
	dp[0][numtemp]=1;
	
	for(int i=1;i<=n+1;++i)
	{
		for(int j=-numtemp;j<numtemp;++j)
        {
        	if(dp[i-1][j+numtemp]!=0)
        		dp[i][j+dis[i]+numtemp]=1,dp[i][j-dis[i]+numtemp]=1;
        }
	}
	
	for(int i=1;i<numtemp;++i)
	{
		if(dp[n][numtemp+i-1]!=0 || dp[n][numtemp-i+1]!=0)
		{
			ans+=pow(i-1,2);
			break;
		}
	}
}

signed main()
{
	freopen("seventeen.in","r",stdin);
	freopen("seventeen.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;++i)
    {
        fx[i]=read(),fy[i]=read();
        ans-=pow(fx[i],2)+pow(fy[i],2);
    }
    
    walk(fx);
    walk(fy);
    
    ans/=2;
    printf("%.2lf",ans);
	
	return 0;
}

