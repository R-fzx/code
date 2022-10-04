#include<bits/stdc++.h>
#define eps 1e-7
inline int read()
{	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))x=x*10+(c&15),c=getchar();
	return f?-x:x;
}
using namespace std;
struct node
{	int id;
	double w;
};
struct bb
{	int nextt,to;
	double w;
}op[40005];
int T,R,C,cnt,head[10005],s,e;
bool bj[10005];
char c[105][105];
double L,dis[10005];
priority_queue<node> q;
inline int getid(int x,int y){return (x-1)*C+y;}
bool operator <(node a,node b)
{	return a.w>b.w;
}
inline void add(int x,int y,double z)
{	op[++cnt].nextt=head[x];
	op[cnt].to=y;
	op[cnt].w=z;
	head[x]=cnt;
}
inline void jt(double v)
{	cnt=0;
	memset(head,0,sizeof(head));
	for(register int i=1;i<=R;++i)
		for(register int j=1;j<=C;++j)
		{	if(c[i][j]=='#')continue;
			if(c[i][j]=='S')s=getid(i,j);
			if(c[i][j]=='E')e=getid(i,j);
			if(c[i-1][j]!='#')add(getid(i,j),getid(i-1,j),v);
			if(c[i+1][j]!='#')add(getid(i,j),getid(i+1,j),v);
			if(c[i][j-1]!='#')add(getid(i,j),getid(i,j-1),1.0);
			if(c[i][j+1]!='#')add(getid(i,j),getid(i,j+1),1.0);
		}
}
inline double dij()
{	for(register int i=1;i<=R*C;++i)dis[i]=11474836.0;
	memset(bj,0,sizeof(bj));
	dis[s]=0.0;
	node tmp;
	tmp.id=s,tmp.w=0.0;
	q.push(tmp);
	while(!q.empty())
	{	int x=q.top().id;
//	cout<<x<<head[x]<<endl;
		q.pop();
		if(bj[x])continue;
		bj[x]=1;
		for(register int i=head[x];i;i=op[i].nextt)
		{	int y=op[i].to;
//			cout<<y; 
			if(dis[y]>dis[x]+op[i].w)
			{	dis[y]=dis[x]+op[i].w;
				if(!bj[y])
				{	tmp.id=y,tmp.w=dis[y];
					q.push(tmp);
				}
			}
		}
	}
//	for(register int i=1;i<=R;++i)
//	{	for(register int j=1;j<=C;++j)
//			cout<<dis[getid(i,j)]<<' ';
//		cout<<endl;
//	}
//	cerr<<dis[e]<<endl;
	return dis[e];
}
int main()
{	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{	scanf("%lf%d%d\n",&L,&R,&C);
		for(register int i=1;i<=R;++i)
			gets(c[i]+1);
//		for(register int i=1;i<=R;++i)
//		{	for(register int j=1;j<=C;++j)
//				cout<<c[i][j];
//			cout<<endl;
//		}
		double l=0.0,r=10.0;
		while(l+eps<r)
		{	double mid=(l+r)/2;
			jt(mid);
//			cout<<mid<<":\n";
//			cout<<mid<<' '<<dij()<<endl;
			if(dij()<=L)l=mid+eps;
			else r=mid-eps; 
		}
		printf("%.5lf\n",l);
	}
	return 0;
} 
