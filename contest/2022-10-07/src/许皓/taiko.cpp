#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool fg,d[1<<15],vis[1<<15];
int tot,k;
void read()
{
	scanf("%d",&k);
	tot=1<<k;
}
bool check()
{
	int i=1,j=tot+1;
	for(;i<=k-1;i++,j++)
	{
		if(d[i]!=d[j]) return false;
	}
	fg=true;
	for(i=1;i<=tot;i++) printf("%d",d[i]);
}
void dfs(int step,int num)
{
	if(fg) return;
	if(step==tot)
	{
		check();
		return;
	}
	for(int i=0;i<tot;i++)
	{
		if(!vis[i])
		{
			int sk;
			if((num>>(k-1))==1) sk=num-(1<<(k-1));
			else sk=num;
			if(sk==(i>>1))
			{
				d[step+k]=i&1;
				vis[i]=true;
				dfs(step+1,i);
				vis[i]=false;
			}
		}
	}
}
void go()
{
	printf("%d ",tot);
	for(int i=1;i<=k;i++) d[i]=0;
	vis[0]=true;
	dfs(1,0);
}
int main()
{
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	read();
	go();
	//system("pause");
	return 0;
}
