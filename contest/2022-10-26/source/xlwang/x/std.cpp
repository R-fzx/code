#include<bits/stdc++.h>
#define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
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
const int Maxn=30;
int vis[Maxn];
struct node{
	int x,y;
}e[Maxn];
int n;
int ans;
inline bool check(node a,node b){return abs(a.x-b.x)>abs(a.y+b.y);}
inline void check1(){
	fr(i,1,n) fr(j,i+1,n) if(vis[i] && vis[j] && !check(e[i],e[j])) return;
	int now=0;
	fr(i,1,n) now+=vis[i];
	ans=max(ans,now);
}
inline void dfs(int x){
	if(x==(n+1)){
		check1();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
inline void init(){
	n=read();
	fr(i,1,n) e[i].x=read(),e[i].y=read();
}
inline void work(){
//	fr(i,1,n) fr(j,i+1,n) if(check(e[i],e[j])) printf("add:%lld %lld\n",i,j);
	dfs(1);
	writeln(ans);
}
signed main(){
	freopen("x.in","r",stdin);
	freopen("x1.out","w",stdout);
	init();work();
	return 0;
}

