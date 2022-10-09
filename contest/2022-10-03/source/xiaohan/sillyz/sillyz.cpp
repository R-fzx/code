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
int tong[1000005];
inline int cf(int x)
{	int res=1;
	while(x)
	{	res*=(x%10);
		x/=10;
	}
	return res;
}
signed main()
{	freopen("sillyz.in","r",stdin);
	freopen("sillyz.out","w",stdout);
	for(register int i=1;i<=1000000;++i)
		if(i*cf(i)<=1000000)tong[i*cf(i)]++;
	int A=read(),B=read(),ans=0;
	for(register int i=A;i<=B;++i)
		ans+=tong[i];
	cout<<ans;
	return 0;
}

