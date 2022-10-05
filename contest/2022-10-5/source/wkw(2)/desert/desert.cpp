#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printlf(x) print(x),putchar('\n')
using namespace std;
inline int read(){
	int x=0;bool w=0;char c=getchar();
	while(!isdigit(c))	w|=c=='-',c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return w?-x:x;
}
inline void print(int x){
	if(x>9)	print(x/10);
	if(x<0)	putchar('-'),x=-x;
	putchar('0'+x%10);
}
#define Num(x,y) x*n+y
const int N=55,INF=2147483647;
int dis[N*N],head[N*N];
char a[N][N];
bool vis[N*N];
int n,ans,sx,sy,tot;
const int dx[8]={0,0,1,-1,1,-1,1,-1};
const int dy[8]={1,-1,1,-1,0,0,-1,1};
struct Node{
	int x,y;
	Node(int xx,int yy){
		x=xx,y=yy;
	}
};
vector<Node> e;
struct edge{
	int to,nxt;
}Edge[N*N*4];
struct node{
	int dis,now;
	bool operator <(const node &x) const{
		return x.dis<dis;
	}
};
inline void dij(int s,int wdx,int wdy){
	priority_queue<node> q;
	for(register int i=1;i<=n*n;++i)	
		dis[i]=INF;dis[s]=0;
	memset(vis,0,sizeof(vis));
	q.push((node){0,s});
	while(!q.empty()){
		int x=q.top().now;q.pop();
		if(vis[x])	continue;
		vis[x]=1;
		for(register int i=head[x];i;i=Edge[i].nxt){
			int v=Edge[i].to,w=1;
			if(x+wdx*n+wdy==v)	w=3;
			if(dis[x]+w<dis[v]){
				dis[v]=dis[x]+w;
				q.push((node){dis[v],v});
			}
		}
	}
}
inline void add(int u,int v){
	Edge[++tot].nxt=head[u];
	Edge[tot].to=v;
	head[u]=tot;
}
int main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=n;++j){
			cin>>a[i][j];
			if(a[i][j]=='@')	sx=i,sy=j;
			if(a[i][j]=='*')	e.push_back(Node(i,j));
		}
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=n;++j){
			for(register int k=0;k<8;++k){
				int xx=dx[k]+i,yy=dy[k]+j;
				if(a[xx][yy]!='X' && xx>0 && xx<=n && yy>0 && yy<=n){
					add(Num(i,j),Num(xx,yy));
				}
			}
		}		
	}
	for(register int k=0;k<8;++k){
		int s=Num(sx,sy);
		dij(s,dx[k],dy[k]);
		int res=INF;
		for(register int i=0;i<e.size();++i){
			int x=e[i].x,y=e[i].y;
			res=min(res,dis[Num(x,y)]);
		}
		if(res!=INF)	ans=max(res,ans);
	}
	if(ans==0)	puts("-1");
	else	print(ans);
	return 0;
}

