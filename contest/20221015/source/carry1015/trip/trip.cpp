#include<bits/stdc++.h>

using namespace std;
const int N=5005,M=1e5+5,K=50005;
int n,m,a[N],u[M],v[M],lt=1e9,rt=-1e9,t[N];
double w[M],dis[N];
struct node{
	int to;
	double w;
};
bool vis[N][K],g[N];
vector<node>nbr[M];
struct Node{
	int id;
	double dist;
	bool operator<(const Node&b)const{
		return dist>b.dist;
	}	
};

bool dij(int s,int t,int l,int r){
	memset(g,0,sizeof(g));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<Node>q;
	q.push({s,0});
	dis[s]=0;
//	g[s]=1;
	while(!q.empty()){
		Node cur=q.top();
		q.pop();
		int x=cur.id;
		if(g[x])
			continue;
		g[x]=1;
		for(int i=0;i<nbr[x].size();i++){
			int y=nbr[x][i].to;
			double w=nbr[x][i].w;
			if(w>=l&&w<=r)
				w=0;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				if(!g[y]){
					g[y]=1;
					q.push({y,dis[y]});
				}
			}
		}
	}
	return dis[t]==0;
}
int main()
{
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		w[i]=w[i]/100.0;
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
		for(int j=1,x;j<=t[i];j++){
			cin>>x;
			vis[x][t[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool p1=0,p2=0;
		if(vis[u[i]][t[i]]&&vis[v[i]][t[i]]){
			nbr[u[i]].push_back({v[i],w[i]*1.0*a[i]});
			nbr[v[i]].push_back({u[i],w[i]*a[i]*1.0});
			rt=max(rt,(int)ceil(w[i]*a[i]*1.0));
			lt=max(lt,(int)floor(w[i]*a[i]*1.0));
		}
		else if(vis[u[i]][t[i]]){
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				if(vis[v[i]][t[j]]){
					nbr[v[i]].push_back({u[i],w[i]*1.0*(a[i]+a[j])/2.0});
					nbr[u[i]].push_back({v[i],w[i]*1.0*(a[i]+a[j])/2.0});
					rt=max(rt,(int)ceil(w[i]*1.0*(a[i]+a[j])/2.0));
					lt=min(lt,(int)floor(w[i]*1.0*(a[i]+a[j])/2.0));
					break;
				}
			}
		}
		else if(vis[v[i]][t[i]]){
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				if(vis[u[i]][t[j]]){
					nbr[v[i]].push_back({u[i],w[i]*1.0*(a[i]+a[j])/2.0});
					nbr[u[i]].push_back({v[i],w[i]*1.0*(a[i]+a[j])/2.0});
					rt=max(rt,(int)ceil(w[i]*1.0*(a[i]+a[j])/2.0));
					lt=min(lt,(int)floor(w[i]*1.0*(a[i]+a[j])/2.0));
					break;
				}
			}
		}
	}
	int s,t;
	cin>>s>>t;
	while(lt<rt){
		if(dij(s,t,lt,rt))
			lt++,rt--;
		else{
			break;
		}
	}
	cout<<lt<<" "<<rt;
	return 0;
}
/*3 7
1 2 3
5 2 8
1 3 7
5 4 5
2 4 9
3 5 10
3 4 2
2 1 2
1 3
2 4 5
30 50 60
1 5

2 6
*/

