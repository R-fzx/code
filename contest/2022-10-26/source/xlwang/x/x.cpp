#include<bits/stdc++.h>
#define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define randfind(l,r) (l+(rand()%(r-l+1)))
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void writepl(int x){write(x);putchar(' ');}
inline void writeln(int x){write(x);puts("");}
const int Maxn=1e6+10;
int sum[Maxn<<4];
int tag[Maxn<<4];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline void pushup(int x){sum[x]=max(sum[ls(x)],sum[rs(x)]);}
inline void updatej(int x,int l,int r,int k){
	sum[x]+=k;
	tag[x]+=k;
}
inline void pushdown(int x,int l,int r){
	if(tag[x]){
		int mid;
		mid=(l+r)>>1;
		updatej(ls(x),l,mid,tag[x]);
		updatej(rs(x),mid+1,r,tag[x]);
		tag[x]=0;
	}
}
inline void update(int ql,int qr,int l,int r,int x,int k){
	if(ql<=l && r<=qr){
		updatej(x,l,r,k);
		return;
	}
	pushdown(x,l,r);
	int mid;
	mid=(l+r)>>1;
	if(ql<=mid) update(ql,qr,l,mid,ls(x),k);
	if(mid<qr) update(ql,qr,mid+1,r,rs(x),k);
	pushup(x);
}
inline int query(int ql,int qr,int l,int r,int x){
	if(ql<=l && r<=qr) return sum[x];
	pushdown(x,l,r);
	int mid,ans;
	mid=(l+r)>>1,ans=0;
	if(ql<=mid) ans=max(ans,query(ql,qr,l,mid,ls(x)));
	if(mid<qr) ans=max(ans,query(ql,qr,mid+1,r,rs(x)));
	return ans;
}
struct node{
	int x,y;
}e[Maxn];
int a[Maxn];
int n;
inline int check(int x){
	int l=0,r=n;
	int ans=0;
	while(l<=r){
//		cerr<<l<<' '<<r<<endl;
		int mid;
		mid=(l+r)>>1;
		if(a[mid]<x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return a[ans];
}
inline bool cmp(node a,node b){return a.x<b.x;}
map<int,int> mp;
inline void init(){
	n=read();
	fr(i,1,n) e[i].x=read(),e[i].y=read();
	int maxn=0,minn=e[1].x;
	fr(i,1,n) maxn=max(maxn,e[i].y),minn=min(minn,e[i].x);
	if(minn<=maxn){
		maxn=maxn+1-minn;
		fr(i,1,n) e[i].x+=maxn;
	}
	fr(i,1,n) a[i]=e[i].x+e[i].y;
	sort(a+1,a+n+1);
	int num=0;
	fr(i,1,n) if(!mp[a[i]]) mp[a[i]]=++num;
//	fr(i,1,n) cout<<a[i]<<' '<<mp[a[i]]<<endl;
//	puts("");
}
inline void work(){
	sort(e+1,e+n+1,cmp);
//	fr(i,1,n) writepl(e[i].x),writeln(e[i].y);
	fr(i,1,n){
		if(e[i].x<=e[i].y) continue;
		int sum;
		sum=check(e[i].x-e[i].y);
		int tot=mp[sum];
//		cout<<'*'<<i<<' '<<sum<<' '<<tot<<' '<<(tot==0?0:query(1,tot,1,n,1))<<endl;
		if(tot==0){
			int now;
			now=mp[e[i].x+e[i].y];
			int ans=query(1,now,1,n,1);
			if(!ans) update(now,now,1,n,1,1);
		}
		else if(sum>=e[i].x+e[i].y) update(1,tot,1,n,1,1);
		else {
//			cout<<"**"<<i<<' '<<query(1,tot,1,n,1)<<endl;
			int now;
			now=mp[e[i].x+e[i].y];
			int Tot=max(0ll,query(1,tot,1,n,1)+1-query(now,now,1,n,1));
			update(now,now,1,n,1,Tot);
		}
	}
	writeln(query(1,n,1,n,1));
}
signed main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	init();work();
	return 0;
}

