//sakura
#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int n,ans;
int jc[105];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main()
{
	freopen("sakura.in","r",stdin);
	freopen("sakura.out","w",stdout);
	
	n=read();
	
	jc[1]=1;
	for(int i=2;i<=n;++i)
		jc[i]=jc[i-1]*i;
		
	for(int x=jc[n]+1;x<=10*jc[n];++x)
	{
		for(int y=jc[n]+1;y<=10*jc[n];++y)
		{
			if((x*y)%(x+y)==0 && x*y/(x+y)==jc[n])
				++ans;	
		}
	}
	
	ans%=MOD;
	cout<<ans;
	
	return 0;
}

