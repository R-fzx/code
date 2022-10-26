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
int n,a[100005],ans=1e18,maxn,tot;
signed main()
{	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	srand(time(0));
	n=read();
	for(register int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	maxn=a[n];
	while(clock()<=2800)
	{	if(tot>=550&&maxn>=10000000000)maxn+=(rand()%100+rand()%100)%100;
		else maxn++;
		tot++;
		int ls=0;
		for(register int i=1;i<=n;++i)ls+=__builtin_popcount((maxn-a[i])%1000000000)+__builtin_popcount((maxn-a[i])/1000000000);
		ans=min(ans,ls);
//		cout<<a[n]<<' '<<ls<<endl;
//		system("pause");
	}
	cout<<ans;
	return 0;
}

