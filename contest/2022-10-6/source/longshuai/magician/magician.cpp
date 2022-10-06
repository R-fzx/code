#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const int mod=1e9+9;
int n,m,ans;
int head[maxn],cnt;
struct edge{
	int fro,to,ne;
}e[maxn<<1];
int d[maxn],fa[maxn];
void add(int x,int y){
	cnt++;
	e[cnt].fro=x;
	e[cnt].to=y;
	e[cnt].ne=head[x];
	head[x]=cnt;
} 
int find(int x){
	if(x==fa[x])return fa[x];
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	fa[a]=b;
}
bool vis[maxn];
void getans(){
	memset(d,0,sizeof(d));
	for(int i=1;i<=cnt;i++)
		if(vis[i])
			d[e[i].fro]++,d[e[i].to]++;
	for(int i=1;i<=n;i++)
		if(d[i]%2)return;
	ans=(ans+1)%mod;
}
void violence(int i){
	if(i>cnt){
		getans();
		return;
	}
	if(!vis[i]){
		vis[i]=1;
		violence(i+1);
		vis[i]=0;
	}
	violence(i+1);
}
void work(){
	memset(vis,false,sizeof(vis));
	vis[cnt]=1;
	violence(1);
}
int main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		if(find(u)!=find(v)){
//			cout<<fa[u]<<' '<<fa[v]<<"(((((((((())))))))))\n"; 
			merge(u,v);
			printf("%d\n",ans);
			continue;
		}
		work();
		printf("%d\n",ans%mod);
	}
}
 
