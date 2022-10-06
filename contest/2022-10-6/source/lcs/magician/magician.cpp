#include<bits/stdc++.h> 
#define int long long
#define mod 1000000009
using namespace std;
int n,m,fa[200005],ans=1;
int head[200005],tot;
struct Edge{
	int nxt,to;
}edge[600006];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void add(int x,int y){
	edge[++tot].nxt=head[x];
	edge[tot].to=y;
	head[x]=tot;
}
bool vis[200005];
bool dfs(int x,int y){
	memset(vis,0,sizeof(vis));
	queue<int>q;q.push(x);
	while(!q.empty()){
		int a=q.front();q.pop();
		if(vis[a])continue;
		vis[a]=1;
		if(a==y)return 1;
		for(int i=head[a];i;i=edge[i].nxt){
			if(!vis[edge[i].to])q.push(edge[i].to);
		}
	}
	return 0;
}
signed main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	while(m--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(find(x)==find(y))ans=ans*2%mod;
		else{
			if(dfs(x,y)){
				fa[y]=fa[x];
				ans=ans*2%mod;
			}
			else{
				add(x,y),add(y,x);
			}
		}
		printf("%lld\n",(ans-1+mod)%mod);
	}
	return 0;
}
