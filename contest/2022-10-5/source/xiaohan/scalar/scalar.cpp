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
int n,x[805],y[805],ans;
inline bool cmp(int a,int b)
{	return a>b;
}
signed main()
{	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)x[i]=read();
	for(register int i=1;i<=n;++i)y[i]=read(); 
	sort(x+1,x+n+1);
	sort(y+1,y+n+1,cmp);
	for(register int i=1;i<=n;++i)ans+=x[i]*y[i];
	cout<<ans;
	return 0;
}
