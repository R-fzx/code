#include<bits/stdc++.h>
#define re register
using namespace std;
const int N=100010;
vector<int> head[N];
int fa[N];
int n,m,ans,ro;
bool vis[N];
stack<int> st;
inline int read()
{
	re int x=0;
	re char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+ch-48,ch=getchar(); 
	return x;
}
void write(re int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
	return;
}
inline void dfs()
{
	st.push(ro);
	re int u,v;
	while(!st.empty())
	{
		u=st.top();
		re int i=0;
		for(i; i<head[u].size(); i++)
		{
			v=head[u][i];
			if(!vis[v])
			{
				if(head[v].size()==0)
					ans++;
				vis[v]=true;
				st.push(v);
				break;
			}
		}
		if(i==head[u].size())
		{
			st.pop();
			for(i=0; i<head[u].size(); i++)
			{
				v=head[u][i];
				vis[v]=false;
			}
		}
	}
	return;
}
int main()
{
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	n=read(),m=read();
	re int u,v;
	for(re int i=1; i<=m; i++)
	{
		u=read(),v=read();
		head[u].push_back(v);
		fa[v]=u;
	}
	for(re int i=1; i<=n; i++)
		if(fa[i]==0)
		{
			ro=i;
			break;
		}
	dfs();
	write(ans);
	return 0;
}
