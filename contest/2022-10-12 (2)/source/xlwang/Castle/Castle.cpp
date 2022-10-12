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
const int Maxn=1e3+10,Maxm=2e6+10,mod=2147483647,inf=1e18;
int n,m;
struct node{
	int nxt;
	int to;
	int d;
}e[Maxm];
int head[Maxn],cnt;
int mp[Maxn][Maxn];
inline void add(int u,int v,int w){
	++cnt;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
	e[cnt].d=w;
}
int dis[Maxn];
struct point{
	int dis;
	int pos;
	bool operator < (const point &a) const {
		return dis>a.dis;
	}
};
priority_queue<point> q;
inline void init(){
	n=read();
	m=read();
	fr(i,1,n) fr(j,1,n) mp[i][j]=inf;
	fr(i,1,n) mp[i][i]=0;
	fr(i,1,m){
		int x,y,z;
		x=read();
		y=read();
		z=read();
		add(x,y,z);
		add(y,x,z);
		mp[x][y]=mp[y][x]=min(mp[x][y],z);
	}
}
int vis[Maxn];
inline void dij(){
	fr(i,1,n) dis[i]=inf;
	point tmp;
	dis[1]=0;
	tmp.dis=0;
	tmp.pos=1;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		if(vis[tmp.pos]) continue;
		vis[tmp.pos]=1;
		for(register int i=head[tmp.pos];i;i=e[i].nxt){
			int y,z;
			y=e[i].to;
			z=e[i].d;
			if(dis[y]>dis[tmp.pos]+z){
				dis[y]=dis[tmp.pos]+z;
				if(!vis[y]){
					point ttmp;
					ttmp.dis=dis[y];
					ttmp.pos=y;
					q.push(ttmp);
				}
			}
		}
	}
}
struct ddd{
	int id;
	int mdis;
}k[Maxn];
inline bool cmp(ddd a,ddd b){return a.mdis<b.mdis;}
int now[Maxn];
inline void work(){
//	writeln(mod);
	dij();
	fr(i,1,n) k[i].id=i,k[i].mdis=dis[i];
	sort(k+1,k+n+1,cmp);
	int cnt=0;
	now[++cnt]=1;
	int ans=1;
	fr(i,2,n){
		int tot=0;
		fr(j,1,cnt) if(mp[now[j]][k[i].id]+k[j].mdis==k[i].mdis) ++tot;
		ans=ans*tot%mod;
		now[++cnt]=k[i].id;
	}
	writeln(ans);
}
signed main(){
	freopen("Castle.in","r",stdin);
	freopen("Castle.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

