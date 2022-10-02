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
int n,h[1005],s[1005],jc[15],ans;
signed main()
{	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)
	{	int x=read();
		h[x]++;
	}
//	cerr<<h[1];
	for(register int i=1;i<=1000;++i)s[i]=s[i-1]+h[i];
	jc[0]=1;
	for(register int i=1;i<=13;++i)jc[i]=jc[i-1]*i;
	for(register int i=1;i<=1000;++i)
		if(h[i])
		{	for(register int l=1;l<=min(n,s[i-1]+1);++l)
			{	if(l!=n)ans+=(jc[s[i-1]]/jc[s[i-1]-(l-1)]*(n-1-s[i-1])*jc[n-l-1])*h[i]*(n-l)*l;
				ans+=(jc[s[i-1]]/jc[s[i-1]-(l-1)])*jc[n-l]*h[i]*l;
//			cout<<i<<' '<<l<<' '<<ans<<' '<<endl;
			}
//			cout<<i<<' '<<ans<<endl;
		}
//	cout<<n<<' '<<ans<<endl;
	printf("%.2lf",1.0*ans/jc[n]);
	return 0;
}
