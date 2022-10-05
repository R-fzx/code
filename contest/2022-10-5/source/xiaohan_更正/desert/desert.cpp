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
struct node
{	int id,w;
};
struct bb
{	int nextt,to,w;
}op[20005];
int n,m,cnt,tot,head[2505],ans=1147483647,dis[2505],s,fx[10][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool bj[2505];
char c[2505],mapp[55][55];
queue<node> Q; 
priority_queue<node> q; 
bool operator <(node a,node b){return a.w>b.w;}
inline int getid(int x,int y){return (x-1)*m+y;}
inline void add(int x,int y,int z)
{	op[++tot].nextt=head[x];
	op[tot].to=y;
	op[tot].w=z;
	head[x]=tot;
}
inline void dij()
{	memset(dis,0x3f,sizeof(dis));
	dis[cnt+1]=0;
	node tmp;
	tmp.id=cnt+1,tmp.w=0;
	q.push(tmp);
	while(!q.empty())
	{	int x=q.top().id;
//		cerr<<x<<' '<<dis[x]<<endl;
		q.pop();
		if(bj[x])continue; 
		bj[x]=1;
		for(register int i=head[x];i;i=op[i].nextt)
		{	int y=op[i].to;
			if(dis[y]>dis[x]+op[i].w)
			{	dis[y]=dis[x]+op[i].w;
				if(!bj[y])
				{	tmp.id=y,tmp.w=dis[y];
					q.push(tmp);
				}
			}
		}
	} 
	return ;
}
int main()
{	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	n=read();
	while(cin>>c[++cnt]);
	cnt--;
	m=cnt/n;
	for(register int i=0;i<=n+1;++i)
		for(register int j=0;j<=m+1;++j)
		{	if(i==0||j==0||i==n+1||j==m+1)mapp[i][j]='X';
			else mapp[i][j]=c[(i-1)*m+j];
		} 
//	for(register int i=0;i<=n+1;++i)
//	{	for(register int j=0;j<=m+1;++j)
//			cout<<mapp[i][j]<<' ';
//		cout<<endl;
//	}
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j)
		{	if(mapp[i][j]=='X')continue;
			if(mapp[i][j]=='@')s=getid(i,j);
			if(mapp[i][j]=='*')add(cnt+1,getid(i,j),0);//,cerr<<getid(i,j)<<endl;
			for(register int k=0;k<8;++k)
			{	int I=i+fx[k][0],J=j+fx[k][1];
				if(mapp[I][J]!='X')add(getid(i,j),getid(I,J),1);
			}
		}
	dij();
//	for(register int i=1;i<=n;++i)
//	{	for(register int j=1;j<=m;++j)
//			cout<<dis[getid(i,j)]<<' ';
//		cout<<endl; 
//		}
	node tmp;
	tmp.id=s,tmp.w=0;
	Q.push(tmp);
	while(!Q.empty())
	{	int x=Q.front().id,z=Q.front().w;
		Q.pop();
		if(dis[x]==0)ans=min(ans,z);
		int X=x/m+1,Y=x+m-X*m,ls=0,minn=114748364;
		for(register int i=0;i<8;++i)
		{	int X0=X+fx[i][0],Y0=Y+fx[i][1];
			if(dis[getid(X0,Y0)]+1==dis[x])ls++;
			else minn=min(minn,dis[getid(X0,Y0)]+1);
		}
//		cerr<<x<<' '<<X<<" "<<Y<<' '<<dis[x]<<' '<<ls<<endl;
		if(ls>=2)
		{	for(register int i=0;i<8;++i)
			{	int X0=X+fx[i][0],Y0=Y+fx[i][1];
				if(X0>=1&&X0<=n&&Y0>=1&&Y0<=m&&dis[getid(X0,Y0)]+1==dis[x])
				{	z++;
					tmp.id=getid(X0,Y0),tmp.w=z; 
					Q.push(tmp);
//					cerr<<tmp.id<<endl;
				}
			}
		}
		else
		{	if(minn>dis[x]+2)
			{	for(register int i=0;i<8;++i)
				{	int X0=X+fx[i][0],Y0=Y+fx[i][1];
					if(X0>=1&&X0<=n&&Y0>=1&&Y0<=m&&dis[getid(X0,Y0)]+1==dis[x])
					{	z+=3;
						tmp.id=getid(X0,Y0),tmp.w=z; 
						Q.push(tmp);
					}
				}
			}
			else if(minn==dis[x]+2)
			{	for(register int i=0;i<8;++i)
				{	int X0=X+fx[i][0],Y0=Y+fx[i][1];
					if(X0>=1&&X0<=n&&Y0>=1&&Y0<=m&&dis[getid(X0,Y0)]+1==dis[x])
					{	z+=3;
						tmp.id=getid(X0,Y0),tmp.w=z; 
						Q.push(tmp);
					}
					else if(X0>=1&&X0<=n&&Y0>=1&&Y0<=m&&dis[getid(X0,Y0)]+1==minn)
					{	z+=1;
						tmp.id=getid(X0,Y0),tmp.w=z; 
						Q.push(tmp);
					}
				}
			}
			else
			{	for(register int i=0;i<8;++i)
				{	int X0=X+fx[i][0],Y0=Y+fx[i][1];
					if(X0>=1&&X0<=n&&Y0>=1&&Y0<=m&&dis[getid(X0,Y0)]+1==minn)
					{	z+=1;
						tmp.id=getid(X0,Y0),tmp.w=z; 
						Q.push(tmp);
					}
				}
			} 
		}
	}
	cout<<ans;
	return 0;
}
