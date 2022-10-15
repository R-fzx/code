#include<bits/stdc++.h>
using namespace std;
int u[50005],v[50005],a[50005],b[50005];
int n,m,fa[205];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int a,int b){
	int x=find(a),y=find(b);
	if(x!=y)fa[x]=y;
}
bool check(int A,int B){
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		if(A>=a[i]&&B>=b[i])unionn(u[i],v[i]);
	}
	int base=find(1);
	for(int i=2;i<=n;++i)if(find(i)!=base)return 0;
	return 1;
}
int p,q;
int _a[50005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>n>>m>>p>>q;
	int maxa=0,maxb=0;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>a[i]>>b[i];
		maxa=max(maxa,a[i]);
		maxb=max(maxb,b[i]);
		_a[i]=a[i];
	} 
	sort(_a+1,_a+m+1);
	int len=unique(_a+1,_a+m+1)-_a-1,mini=1e9;
	for(int i=1;i<=len;++i){
		int mida=_a[i];
		int l=-1,r=maxb+1;
		while(l+1<r){
			int midb=l+r>>1;
			if(check(mida,midb)){
				r=midb;
				mini=min(mini,mida*p+midb*q);
			}
			else l=midb;
		}
	}
	if(mini==1e9)mini=-1;
	cout<<mini;
	return 0;
}
