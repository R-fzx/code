#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=2e5+5;
int n,m;
int in[maxn],out[maxn],ans[maxn],sum;
int head[maxn],cnt;
struct node{
	int to,ne;
}e[maxm];
queue<int> tmp;
void add(int x,int y){
	cnt++;
	e[cnt].to=y;
	e[cnt].ne=head[x];
	head[x]=cnt;
}
int main(){
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		out[u]++;in[v]++;
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(out[i]==0){
			tmp.push(i);
			ans[i]=1;
		}
	while(!tmp.empty()){
		int t=tmp.front();
		tmp.pop();
		for(int i=head[t];i;i=e[i].ne){
			int v=e[i].to;
			out[v]--;ans[v]+=ans[t];
			if(out[v]==0)tmp.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(in[i]==0)sum+=ans[i];
	printf("%d\n",sum);
	return 0;
}
