#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
#define randfind(l,r) (rand()%((r)-(l)+1)+(l))
#define pb push_back
#define Times printf("Time:%.3lf\n",clock()/CLOCKS_PER_SEC)
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){write(x); puts("");}
inline void writepl(int x){write(x); putchar(' ');}
const int Maxn=20,base1=131,base2=101,mod=998244353;
int n,m,k;
char c[Maxn][Maxn];
int vis1[Maxn][Maxn];
int vis[Maxn][Maxn];
map<int,int> mp;
int ans;
struct node{
	int x,y;
}e[Maxn],e1[Maxn],e2[Maxn];
inline bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
inline int gethash(){
	fr(i,1,k) e1[i]=e[i];
	sort(e1+1,e1+k+1,cmp);
	int minx=100,miny=100,maxx=0,maxy=0;
	fr(i,1,k) minx=min(minx,e1[i].x),maxx=max(maxx,e1[i].x),miny=min(miny,e1[i].y),maxy=max(maxy,e1[i].y);
	fr(i,1,k) e1[i].x+=0-minx,e1[i].y+=0-miny;
//	fr(i,1,k) writepl(e1[i].x),writeln(e1[i].y);
//	puts("");
	int sum=0;
	int tot1=1,tot2=1;
	fr(i,1,k){
		sum+=tot1*e1[i].x+tot2*e1[i].y;
		tot1*=base1,tot2*=base2;
		tot1%=mod,tot2%=mod;
	}
	return sum;
}
inline void init(){
	n=read();
	m=read();
	k=read();
	fr(i,1,n) scanf("%s",c[i]+1);
}
inline bool find(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m;
}
//int ans;
inline void check(){
	fr(i,1,k) e2[i]=e[i];
	int minx=100,miny=100,maxx=0,maxy=0;
	fr(i,1,k) minx=min(minx,e[i].x),maxx=max(maxx,e[i].x),miny=min(miny,e[i].y),maxy=max(maxy,e[i].y);
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny;
	int now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	fr(i,1,k) e[i].x+=minx,e[i].y+=miny;
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny,e[i].x=-e[i].x,e[i].y=-e[i].y;
	now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	fr(i,1,k) e[i].x=-e[i].x,e[i].y=-e[i].y,e[i].x+=minx,e[i].y+=miny;
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny,e[i].x=-e[i].x;
	now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	fr(i,1,k) e[i].x=-e[i].x,e[i].x+=minx,e[i].y+=miny;
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny,e[i].y=-e[i].y;
	now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	fr(i,1,k) e[i]=e2[i];
	fr(i,1,k) swap(e[i].x,e[i].y);
	minx=100,miny=100,maxx=0,maxy=0;
	fr(i,1,k) minx=min(minx,e[i].x),maxx=max(maxx,e[i].x),miny=min(miny,e[i].y),maxy=max(maxy,e[i].y);
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny;
	now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	fr(i,1,k) e[i].x+=minx,e[i].y+=miny;
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny,e[i].x=-e[i].x,e[i].y=-e[i].y;
	now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	fr(i,1,k) e[i].x=-e[i].x,e[i].y=-e[i].y,e[i].x+=minx,e[i].y+=miny;
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny,e[i].x=-e[i].x;
	now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	fr(i,1,k) e[i].x=-e[i].x,e[i].x+=minx,e[i].y+=miny;
	fr(i,1,k) e[i].x-=minx,e[i].y-=miny,e[i].y=-e[i].y;
	now=gethash();
	if(mp[now]) return;
	mp[now]=1;
	++ans;
}
inline void dfs(int now,int x,int y){
	e[now].x=x,e[now].y=y;
	if(now==(k)){
		check();
		return;
	}
	fr(i,0,3){
		int nx,ny;
		nx=x+dx[i];
		ny=y+dy[i];
		if(!find(nx,ny)) continue;
		if(c[nx][ny]=='0') continue;
		if(vis[nx][ny]) continue;
		vis1[nx][ny]=vis[nx][ny]=1;
		dfs(now+1,nx,ny);
		vis[nx][ny]=0;
	}
}
inline void work(){
	fr(i,1,n) fr(j,1,m){
		if(vis1[i][j]) continue;
		if(c[i][j]=='0') continue;
		dfs(0,i,j);
	}
	writeln((ans+1)/2);
}
signed main(){
	freopen("かなで.in","r",stdin);
	freopen("かなで.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

