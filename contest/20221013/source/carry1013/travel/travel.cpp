#include<bits/stdc++.h>

using namespace std;
const int N=1005,M=3005;
int n,m,mini=1e9,g[N],ans[N],a,b;
struct node{
	int to,l,r;
}d;
vector<node>nbr[M];
void add(int x,int y,int l,int r){
	nbr[x].push_back({y,l,r});
	nbr[y].push_back({x,l,r});
}
bool vis[N];
struct Node{
	int a,b,l,r;
}s[N];
bool cmp(Node x,Node y){
	if(x.r-x.l+1==y.r-y.l+1){
		return x.l<y.l;
	}
	return x.r-x.l+1>y.r-y.l+1;
}
void dfs(int x,int fa){//ans[x]表示以x为终点最多能携带的泡泡怪数量
	if(x==n)
		return ;
	ans[x]=0;
	for(int i=0;i<nbr[x].size();i++){
		int y=nbr[x][i].to,l=nbr[x][i].l,r=nbr[x][i].r;
		if(y==fa)
			continue;
		if(ans[x]<r-l+1){
			ans[x]=r-l+1;
			a=l,b=r;
		}
		else if(ans[x]==r-l+1){
			if(a>l)
				a=l,b=r;
		}
		dfs(y,x);
//		ans[x]=min(ans[x],ans[y])
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i].a>>s[i].b>>s[i].l>>s[i].r;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=m;i++){
		add(s[i].a,s[i].b,s[i].l,s[i].r);
	}
	dfs(1,-1);
	cout<<b-a+1<<'\n';
	for(int i=a;i<=b;i++)
		cout<<i<<" ";
	return 0;
}

