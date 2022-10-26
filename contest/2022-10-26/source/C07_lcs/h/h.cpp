#include<bits/stdc++.h>
using namespace std;
int n,m,h[200005],k,ans;
int tree[800005];
void build(int x,int l,int r){
	if(l==r){
		tree[x]=h[l];
		return;
	}
	int mid=l+r>>1;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	tree[x]=min(tree[x*2],tree[x*2+1]);
}
int query(int x,int l,int r,int tl,int tr){
	if(l>tr||r<tl)return 1919810;
	if(l>=tl&&r<=tr)return tree[x];
	int mid=l+r>>1;
	return min(query(x*2,l,mid,tl,tr),query(x*2+1,mid+1,r,tl,tr));
}
struct node{
	int x,y;
}a[200005];
signed main(){
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	scanf("%d%d",&n,&m);for(int i=1;i<=n;++i)scanf("%d",&h[i]);
	build(1,1,n);
	scanf("%d",&k);for(int i=1;i<=k;++i)scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=k;++i){
		for(int j=i+1;j<=k;++j){
			int sum=query(1,1,n,min(a[i].x,a[j].x),max(a[i].x,a[j].x)),a1=0,a2=0;
			a1=abs(a[i].x-a[j].x);
			a2=max(a[i].y-sum,0)+max(a[j].y-sum,0);
			if(a1+a2<=m)++ans;
		}
	}
	printf("%d",ans);
	return 0;
}
