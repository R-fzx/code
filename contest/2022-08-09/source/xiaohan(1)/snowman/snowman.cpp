#include<bits/stdc++.h>
#define int long long
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,cf[500005],base1=163,mod1=1000000007,base2=13131,mod2=33554431,cnt,ans;
pair<int,int> hash1[500005],dl[500005];
map<pair<int,int>,int> minn,maxn;
int ksm(int x,int y,int mod)
{	int res=1;
	while(y)
	{	if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
bool check(int len)
{	minn.clear(),maxn.clear();
	cnt=0;
	int jl1=ksm(base1,len,mod1),jl2=ksm(base2,len,mod2);
	for(register int i=1;i<n-len;++i)
	{	pair<int,int> tmp=make_pair((hash1[i+len-1].first-hash1[i-1].first*jl1%mod1+mod1)%mod1,(hash1[i+len-1].second-hash1[i-1].second*jl2%mod2+mod2)%mod2);
		if(!minn.count(tmp))
		{	dl[++cnt]=tmp;
			minn[tmp]=i;
			maxn[tmp]=i;
		}
		else
		{	minn[tmp]=min(i,minn[tmp]);
			maxn[tmp]=max(i,maxn[tmp]);
		}
	}
	int max_len=0;
	for(register int i=1;i<=cnt;++i)max_len=max(max_len,maxn[dl[i]]-minn[dl[i]]);
	return max_len>=len;
}
signed main()
{	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)cf[i]=read();
	for(register int i=1;i<n;++i)cf[i]=cf[i+1]-cf[i];
	for(register int i=1;i<n;++i)hash1[i].first=(hash1[i-1].first*base1+cf[i])%mod1;
	for(register int i=1;i<n;++i)hash1[i].second=(hash1[i-1].second*base2+cf[i])%mod2;
	int l=1,r=n;
	while(l<r)
	{	int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
//	cerr<<check(2);
	if(check(ans+1))cout<<ans+2;
	else if(check(ans))cout<<ans+1;
	else if(check(ans-1))cout<<ans;
	return 0;
}

