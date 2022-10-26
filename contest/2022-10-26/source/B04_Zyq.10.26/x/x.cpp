#include<bits/stdc++.h>
#define left(p) {p.l,p.l+p.r>>1}
#define right(p) {(p.l+p.r>>1)+1,p.r}
#define pii pair<int,int>
#define l first
#define r second
#define all {1,tot}
#define root 1
using namespace std;
const int N(1e5+7);
struct Node{
	int w1,w2,t;
}p[N];//a.w2 > b.w1|| b.w2 > a.w1
struct E{
	int w1,num;
	inline const bool operator<(const E a)const{
		return w1==a.w1?num<a.num:w1<a.w1;
	}
};
inline bool cmp(Node x,Node y){
	return x.t<y.t;
}
int n,tot,ans(1),d[N<<4];
inline int change(pii p,int x,int y,int k){
	if(p.l>y||p.r<y)return d[x];
	if(p.l==p.r&&p.l==y)return d[x]=k;
	return d[x]=max(change(left(p),x<<1,y,k),change(right(p),x<<1|1,y,k));
}
inline int ask(pii p,int x,pii _p){
	if(p.r<_p.l||p.l>_p.r)return 0;
	if(p.l>=_p.l&&p.r<=_p.r){
		return d[x];
	}
	return max(ask(left(p),x<<1,_p),ask(right(p),x<<1|1,_p));
}
map<int,int>f;
inline int read(){
	int r(0);
	char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
	return r;
}
int main(){
	freopen("x.in","r",stdin),freopen("x.out","w",stdout);
	n=read();
	for(int i(0);i<n;i++){
		int x(read()),y(read());
		p[i]={x+y,x-y,x},f[x+y]=0,f[x-y]=0;
	}
	for(auto i(f.begin());i!=f.end();i++){//ÀëÉ¢»¯ 
		f[i->first]=++tot;
	}
	for(int i(0);i<n;i++){
		//cout<<p[i].w1<<' '<<p[i].w2<<',';
		p[i].w1=f[p[i].w1],p[i].w2=f[p[i].w2];
		//cout<<p[i].w1<<' '<<p[i].w2<<'\n';
	}
	sort(p,p+n,cmp);
	for(int i(0);i<n;i++){
		int x(ask(all,root,{1,p[i].w2-1})),y(ask(all,root,{p[i].w1,p[i].w1}));
		if(x+1>y){
			change(all,root,p[i].w1,x+1);
		}
	}
	for(int i(1);i<=tot;i++){
		ans=max(ans,ask(all,root,{i,i}));
	}
	cout<<ans;
	return 0;
}

