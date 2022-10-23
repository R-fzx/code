#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long LL;
typedef pair<LL,int> pii; 
const int maxn=1010,max_edge=2000010+maxn;
int n,cnt,a[maxn],fa[maxn],vis[maxn];
//int to[max_edge],nxt[max_edge],W[max_edge],head[maxn];
int find_set(int x){return fa[x]==x?x:fa[x]=find_set(fa[x]);}
//void add(int x,int y,int z){
//	++cnt;
//	to[cnt]=y;
//	W[cnt]=z;
//	nxt[cnt]=head[x];
//	head[x]=cnt;
//}
//LL prim(int s){
//	priority_queue<pii> q;
//	q.push(mp(0,s));
//	LL sum=0;
//	while(!q.empty()){
//		pii p=q.top();
//		q.pop();
//		int x=p.second;
//		if(vis[x]) continue;
//		vis[x]=1;
//		sum+=p.first;
//		cout<<x<<' '<<p.first<<endl;
//		for(int i=head[x];i;i=nxt[i]){
//			int y=to[i];
//			if(vis[y]) continue;
//			q.push(mp(-W[i],y));
//		}
//	}
//	return sum;
//}
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],fa[i]=i;
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<i;j++){
//			if(a[i]&a[j]) continue;
//			add(i,j,-a[i]);
//			add(j,i,-a[j]);
//		}
//	}
//	for(int i=1;i<=n;i++) add(0,i,0);
//	cout<<prim(n);
	LL sum=0;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(a[i]&a[j]) continue;
			if(vis[j]) continue;
			if(find_set(i)==find_set(j)) continue;
			vis[j]=1;
			sum+=a[i];
			fa[find_set(i)]=find_set(j);
		}
	}
	cout<<sum<<endl;
	return 0;
}
