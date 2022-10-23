#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
struct Node{
	int to,next;
}e[2005];
int a[1005],head[1005],tot,n,ans,mi,d[1005];
void add(int x,int y){
	e[++tot].to=y,e[tot].next=head[x],head[x]=tot;
}
bool f[1005];
void dfs(int x){
	f[x]=1;
	if(d[x]<d[mi]) mi=x;
	for(int i=head[x];i;i=e[i].next){
		if(f[e[i].to]==0&&d[e[i].to]==a[x]) dfs(e[i].to);
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])==0){
				//cout<<1;
				add(i,j),add(j,i);
				d[i]=max(a[j],d[i]);
				d[j]=max(d[j],a[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<d[i]<<'\n';
		if(f[i]==0){
			mi=i;
			dfs(i);
			ans-=d[mi];
		}
	}
	for(int i=1;i<=n;i++) ans+=d[i];
	cout<<ans;
	return 0;
}
