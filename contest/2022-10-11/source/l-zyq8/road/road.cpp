#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
int n,m,p,q,a,b,ans(2e18),del[209],tot,_inf,inf;
vector<pair<int,pair<int,int> > >v[209];
inline int read(){
	int r(0);
	char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
	return r;
}
inline void dfs(int x){
	if(del[x]==tot)return;
	del[x]=tot;
	for(int i(0);i<v[x].size();i++){
		if(v[x][i].y.x<=a&&v[x][i].y.y<=b)dfs(v[x][i].x);
	}
}
inline void add(int a,int b,int w,int t){
	_inf=max(_inf,w);inf=max(inf,t);
	v[a].push_back({b,{w,t}}),v[b].push_back({a,{w,t}});
}
inline bool check(int p,int q){
	a=p,b=q,tot++;
	dfs(1);
	for(int i(1);i<=n;i++){
		if(del[i]!=tot)return false;
	}
	return true;
}
inline int f(int p){
	int l(0),r(inf+1);
	while(l<r){
		int mid(l+r+1>>1);
		if(check(p,mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l>inf?-1:l;
}
signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	srand(time(0));
	int start(clock());
	n=read(),m=read(),p=read(),q=read();
	for(int i(0);i<m;i++){
		int a(read()),b(read()),w(read()),t(read());
		add(a,b,w,t);
	}
	int i(_inf);
	for(int j(1);i>=0;i-=j,j<<=1){
		int cur(f(i)),val(i*p+cur*q);
		if(cur>=0&&val<=ans){
			ans=val;
		}else if(j==2){
			break;
		}else{
			i+=(j>>1),j=1;
		}
	}
	int k(1);
	while(clock()-start<=950){
		int cur(f(i=min(max(k+i,(int)0),_inf))),val(i*p+cur*q);
		if(cur>=0&&val<=ans){
			ans=val;
		}else if(!(rand()%(11*abs(k)))){
			if(rand()%37)k*=-1;
			else k*=-2;
		}
		if(i==_inf||i==0){
			if(rand()%7==0)k*=-1;
		}
	}
	cout<<(ans==(int)2e18?-1:ans);
	return 0;
}
