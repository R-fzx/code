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
struct bb
{	int nextt,to;
}op[200005];
int n,m,dis[100005],rd[100005],head[100005],cnt,answer;
queue<int> q;
inline void add(int x,int y)
{	op[++cnt].nextt=head[x];
	op[cnt].to=y;
	head[x]=cnt;
	rd[y]++;
}
int main()
{	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=m;++i)
	{	int x=read(),y=read();
		add(x,y); 
	}
	for(register int i=1;i<=n;++i)
		if(rd[i]==0)
		{	dis[i]=1;
			q.push(i);
		}
	while(!q.empty())
	{	int x=q.front();
		q.pop();
		bool flag=0;
		for(register int i=head[x];i;i=op[i].nextt)
		{	int y=op[i].to;
			flag=1;
			dis[y]+=dis[x];
			rd[y]--;
			if(rd[y]==0)q.push(y);
		}
		if(flag==0)answer+=dis[x];
	}
	cout<<answer;
	return 0;
}
