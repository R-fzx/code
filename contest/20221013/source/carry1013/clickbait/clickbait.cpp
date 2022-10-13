#include<bits/stdc++.h>

using namespace std;
const int N=1005;
int n,m,t,sx,sy,f=-1,k[N*N];
bool vis[N][N];
char a[N][N];
struct node{
	int x,y;
}s[N*N],d[N*N],g[N*N];
struct Node{
	int x,y,step;
};
int dxy[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int bfs(int x,int y,node ed){
	memset(vis,0,sizeof(vis));
	vis[x][y]=1;
	queue<Node>q;
	q.push({x,y});
	while(!q.empty()){
		Node cur=q.front();
		q.pop();
		if(cur.x==ed.x&&cur.y==ed.y)
			return cur.step;
		for(int i=0;i<4;i++){
			int nx=cur.x+dxy[i][0],ny=cur.y+dxy[i][1];
			if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]||a[nx][ny]=='.'){
				continue;
			} 
			vis[nx][ny]=1;
			q.push({nx,ny});
		}
	} 
}
void dfs(int x,int y){
	if(x<1||x>n||y<1||y>m)
		return ;
	if((a[x][y]=='|'&&(a[x][y-1]=='-'||a[x][y+1]=='-'))||(a[x][y]=='-'&&(a[x-1][y]=='|'||a[x+1][y]=='|'))){
		g[++f].x=x,g[++f].y=y;
		return ;
	}
	for(int i=0;i<4;i++){
		int nx=dxy[i][0]+x,ny=dxy[i][1]+y;
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vis[nx][ny]){
			vis[nx][ny]=1;
			dfs(nx,ny);
		}
	}
}
int main()
{
	freopen("clickbait.in","r",stdin);
	freopen("clickbait.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='1'&&(a[i][j+1]=='|'||a[i][j+1]=='.')){
				sx=i,sy=j;
//				k[0]=1;
			}
			else if(a[i][j]>='1'&&a[i][j]<='9'){
				s[++t]={i,j};
				k[t]=(a[i][j]-'0');
				int s=j+1; 
				while(a[i][s]>='0'&&a[i][s]<='9'){
					k[t]=k[t]*10+(a[i][s]-'0');
					s++;
				}
			}
		}
	}
	s[0]={sx,sy};
	dfs(sx,sy);
	for(int i=1;i<=t;i++){
		dfs(s[i].x,s[i].y);
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=t;i++){
		d[i]={bfs(g[i-1].x,g[i-1].y,g[i]),k[i]};
	}
	sort(d+1,d+1+t,[](node a,node b){
		return a.x<b.x;
	});
	for(int i=2;i<=t;i++)
		cout<<d[i].y<<"\n";
	cout<<1;
	return 0;
}

