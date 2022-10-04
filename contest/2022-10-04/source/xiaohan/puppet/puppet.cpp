#include<bits/stdc++.h>
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
int n,a[55],f[55];
inline int pd(int x,int y)
{	for(register int maxn=1;maxn<=y-x+1;++maxn)
	{	if(abs(a[x+maxn-1]-a[y-maxn+1])<=1)return maxn-1;
		for(register int i=maxn+x;i<=y;++i)
			if(abs(a[i]-a[i-maxn])>1)return maxn-1;
	}
	return y-x+1;
}
int main()
{	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{	for(register int i=1;i<=n;++i)a[i]=read(),f[i]=0;
		sort(a+1,a+n+1);
		for(register int i=1;i<=n;++i) 
			for(register int j=0;j<i;++j)
				f[i]=max(f[i],f[j]+pd(j+1,i));
		cout<<f[n]<<endl;
	}
	return 0;
}

