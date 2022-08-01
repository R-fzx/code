#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100,M=2e5+100;
int in[N],out[N];
int n,m;
int h[N],nex[M],to[M],tot;
int root,ans;
void add(int x,int y){
	tot++;
	to[tot]=y;
	nex[tot]=h[x];
	h[x]=tot;
}
void bfs(int s){
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(!out[u]){
			ans++;
			continue;
		}
		for(int i=h[u];i;i=nex[i]){
			q.push(to[i]);
		}
	}
}
int main(){
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		in[y]++;
		out[x]++;
	}
	for(int i=1;i<=n;i++)if(!in[i]){bfs(i);break;}
	printf("%d",ans);
	return 0;
}
