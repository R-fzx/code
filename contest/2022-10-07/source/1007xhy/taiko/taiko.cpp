#include<bits/stdc++.h>
#define re register
#define gt getchar
using namespace std;
const int K=19,M=3005;
int k,m;
bool vis[M],s[M],flag;
inline int read()
{
	re int x=0;
	re bool fl=true;
	re char ch=gt();
	while(ch<48||ch>57){if(ch=='-')fl=0;ch=gt();}
	while(ch>=48&&ch<=57)x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return fl?x:-x;
} 
inline void write(re int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
inline void print(re int x)
{
	if(x<0){putchar('-'),x=-x;}
	write(x),putchar(10);
}
inline int check(int x)
{
	int num=0;
	for(re int i=0; i<k; i++)
		num+=(s[x-i]<<i);
	return num;
}
inline int check2(int x)
{
	int num=0;
	for(re int i=m-(k-x)+1; i<=m; i++)
		num+=(s[i]<<i-(m-(k-x)+1));
	for(re int i=1; i<=x; i++)
		num+=(s[i]<<i+(k-x)-1);
	return num;
}
inline bool hack()
{
	for(re int i=1; i<k; i++)
		if(vis[check2(i)])return 1;
	return 0;
}
inline bool dfs(int x)
{
	if(x>m)return hack();
	int tmp=check(x);
	if(!vis[tmp])
	{
		s[x]=0;vis[tmp]=true;
		if(dfs(x+1))
		{
			vis[tmp]=false;
			if(!vis[tmp+1])
			{
				s[x]=1,vis[tmp+1]=true;
				return dfs(x+1);
			}
			else return 1;
		}
		return 0;
	}
	else if(!vis[tmp+1])
	{
		s[x]=1,vis[tmp+1]=true;
		return dfs(x+1);
	}
	return 1;
}
signed main()
{
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	k=read();
	m=1<<k,write(m),putchar(' ');
	vis[0]=true;
	for(re int i=1; i<=k; i++)s[i]=0;
	dfs(k+1);
	for(re int i=1; i<=m; i++)
		putchar(s[i]+48);
	return 0;
}
