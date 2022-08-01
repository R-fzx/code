#include<cstdio>
#include<vector>
#define N 100001
int n,m,a,b,id[N],od[N],f[N],ans;
using std::vector;
vector<int> g[N];
int dfs(int);
int main(){
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	scanf("%d%d",&n,&m);
	do{
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		++od[a];
		++id[b];
	}while(--m);
	for(int i=1;i<=n;++i){
		if(!id[i]){
			ans+=dfs(i);
		}
	}
	printf("%d",ans);
	return 0;
}
int dfs(int x){
	if(f[x]) return f[x];
	if(!od[x]) return f[x]=1;
	for(int i=0;i<od[x];++i){
		f[x]+=dfs(g[x][i]);
	}
	return f[x];
}
