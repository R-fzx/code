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
int n,last=1,now=1147483647,ans;
signed main()
{	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)
	{	int x=read();
		if(x<now)
		{	ans+=(i-last)*now;
			now=x;
			last=i;
		}
//		cerr<<ans<<endl;
	}
	ans+=(n+1-last)*now;
	cout<<ans;
	return 0;
} 
