//lyx
#include<bits/stdc++.h>
using namespace std;

const int NUM=1e5+5;

struct node
{
	int to,nxt;
}e[4*NUM];

vector<int> start_point;

int n,m,cnt,ans,cnt_start;
int head[NUM];
bool start_bj[NUM],end_bj[NUM],end_mark[NUM];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}

void bfs(int now)
{
	if(end_mark[now]==1)
	{
		++ans;
		return ;
	}
	
	for(int i=head[now];i;i=e[i].nxt)
		bfs(e[i].to);
}

int main()
{
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int a,b;
		a=read(),b=read();
		
		add(a,b);
		
		start_bj[b]=1;
		end_bj[a]=1;
	}
	
	for(int i=1;i<=n;++i)
	{
		if(!start_bj[i])
		{
			start_point.push_back(i);
			++cnt_start;
		}
			
		if(!end_bj[i])
			end_mark[i]=1;
	}
	
	for(int i=1;i<=cnt_start;++i)
		bfs(i);
		
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

