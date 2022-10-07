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
int k,n,ans[2505],bj[2505];
bool dfs(int S,int x)
{	if(bj[S])return 0;
	bj[S]=1;
	ans[x]=S&1;
	if(x==n)return 1;
	if(dfs(S<<1&(n-1),x+1))return 1;
	if(dfs((S<<1|1)&(n-1),x+1))return 1;
	bj[S]=0;
	return 0;
}
int main()
{	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	k=read();
	n=1<<k;
	dfs(n-2,1);
	cout<<n<<endl;
	for(register int i=1;i<=n;++i)cout<<ans[i];
	return 0;
}

