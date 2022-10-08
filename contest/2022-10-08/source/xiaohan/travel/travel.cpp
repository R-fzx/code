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
{	int x,y;
}op[40005];
int n,m,fa[205],rd[205],cd[205],gsr[205],gsc[205],ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=m;++i)op[i].x=read(),op[i].y=read(),cd[op[i].x]++,rd[op[i].y]++;
	for(register int i=1;i<=n;++i)fa[i]=i,gsr[i]=(rd[i]==0),gsc[i]=(cd[i]==0);
	for(register int i=1;i<=m;++i)
	{	int fx=find(op[i].x),fy=find(op[i].y);
		if(fx!=fy)
		{	fa[fy]=fx;
			gsr[fx]+=gsr[fy];
			gsc[fx]+=gsc[fy];
			gsr[fy]=gsc[fy]=0;
		}
	}
	for(register int i=1;i<=n;++i)ans+=max(gsr[i],gsc[i]);
	printf("%d\n",ans);
	for(register int i=1;i<=n;++i)
	{	if(gsr[i]+gsc[i]==0)continue;
		if(gsr[i]>=gsc[i])
		{	for(register int j=1;j<=n;++j)
				if(find(j)==find(i)&&rd[j]==0)printf("%d ",j);
		}
		else
		{	for(register int j=1;j<=n;++j)
				if(find(j)==find(i)&&cd[j]==0)printf("%d ",j);
		}
	}
	return 0;
}

