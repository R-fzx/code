#include<bits/stdc++.h>
using namespace std;
struct edges{int v,nxt;}edge[200005];
int head[100005];void add(int u,int v){static int cnt=0;edge[++cnt]=(edges){v,head[u]};head[u]=cnt;}
int n,m,ind[100005],oud[100005],ans[100005];
void topo(){
	queue<int>q;
	for(int i=1;i<=n;i++)if(!ind[i])ans[i]=1,q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			ans[edge[i].v]+=ans[u];
			if(--ind[edge[i].v]==0)q.push(edge[i].v);
		}
	}
}
int main(){
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){cin>>u>>v;add(u,v);ind[v]++,oud[u]++;}
	topo();int sum=0;
	for(int i=1;i<=n;i++)if(!oud[i])sum+=ans[i];
	cout<<sum;
	return 0;
}
