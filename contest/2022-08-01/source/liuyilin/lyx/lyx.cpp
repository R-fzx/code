#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int fr[N],nx[M],to[M],t;
int ind[N],outd[N];
int f[N];
void Add(int u,int v){
	nx[++t]=fr[u];
	fr[u]=t;
	to[t]=v;
	ind[v]++;outd[u]++;
}

queue<int>q;
void topo(){
	f[0]=1;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=fr[u];i;i=nx[i]){
			int v=to[i];
			f[v]+=f[u];
			ind[v]--;
			if(ind[v]==0) q.push(v);
		}
	}
	return;
}
int main(){
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		Add(u,v);
	}
	for(int i=1;i<=n;i++){
		if(ind[i]==0) Add(0,i);
		if(outd[i]==0) Add(i,n+1);
	}
	topo();
	printf("%d",f[n+1]);
	return 0;
}
