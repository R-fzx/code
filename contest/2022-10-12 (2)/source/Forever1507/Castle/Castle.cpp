#include<bits/stdc++.h>
#define int long long
const int mod=2147483647;
using namespace std;
int n,m,s,dis[1005];
struct node{
	int v,w;
	bool operator<(const node &nxt)const{
		return w>nxt.w;
	}
};
vector<node>nbr[1005];
bool vis[1005];
void Dijkstra(int s){
	node cur={s,0};
	priority_queue<node>pq;
	pq.push(cur);
	dis[s]=0;
	while(!pq.empty()){
		cur=pq.top();
		pq.pop();
		if(vis[cur.v])continue;
		vis[cur.v]=1;
		for(int i=0;i<nbr[cur.v].size();i++){
			int to=nbr[cur.v][i].v;
			if((dis[cur.v]+nbr[cur.v][i].w)<dis[to]){
				dis[to]=(dis[cur.v]+nbr[cur.v][i].w);
				node cur={to,dis[to]};
				pq.push(cur);
			}
		}
	}
}
int cnt[1005],Dis[1005];
void calc(int s){
	memset(vis,0,sizeof(vis)); 
	memset(Dis,0x3f,sizeof(Dis));
	node cur={s,0};
	priority_queue<node>pq;
	pq.push(cur);
	Dis[s]=0;
	while(!pq.empty()){
		cur=pq.top();
		pq.pop();
		if(vis[cur.v])continue;
		vis[cur.v]=1;
		for(int i=0;i<nbr[cur.v].size();i++){
			int to=nbr[cur.v][i].v;
			if((Dis[cur.v]+nbr[cur.v][i].w)==dis[to]){
				cnt[to]=(cnt[to]+1)%mod;
//				cout<<"Test: "<<cur.v<<' '<<to<<'\n';
			}
			if((Dis[cur.v]+nbr[cur.v][i].w)<Dis[to]){
				Dis[to]=(Dis[cur.v]+nbr[cur.v][i].w);
				node cur={to,Dis[to]};
				pq.push(cur);
			}
		}
	}
}
signed main(){
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		nbr[u].push_back((node){v,w});
		nbr[v].push_back((node){u,w});
	}
	memset(dis,0x3f,sizeof(dis));
	Dijkstra(1);
//	for(int i=1;i<=n;++i)cnt[i]=1;
	calc(1);
	int ans=1;
	for(int i=2;i<=n;i++)ans=(ans*cnt[i])%mod;
	cout<<ans;
	return 0;
}
