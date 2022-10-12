#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define oo 1e+18LL

using namespace std;

long long x,y;

long long f[147]={0};

long long ans=0;

inline long long find(long long mi,long long p)
{
	long long mid,l=1,r=p,o,i;

	while(l<r)
	{
		mid=(l+r+1)/2;
	
		for(o=p,i=1;i<=mi;i++)
			o=o/mid;
	
		if(o>=1)
			l=mid;
	
		else
			r=mid-1;
	}

	return l;
}

inline long long pd(long long k)
{
	long long i,max,ans=0,o,j;

	memset(f,0,sizeof(f));

	for(i=61;i>=1;i--)
	{
		f[i]=find(i,k);
	
		for(j=2;j*i<=61;j++)
			f[i]-=f[i*j];
	
		ans+=i*f[i];
	}

	return ans;
}

int main()
{
    freopen("t2.in","r",stdin);
    freopen("t2.out","w",stdout);

    cin>>x>>y;

    while(x!=0 || y!=0)
    {
         if(x>y)
           swap(x,y);
    
         ans=pd(y)-pd(x-1);
    
         cout<<ans<<endl;
    
         cin>>x>>y;
    }

    return 0;
}
