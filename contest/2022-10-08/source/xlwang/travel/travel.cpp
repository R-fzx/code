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
const int Maxn=2e2+10,Maxm=1e5+10;
int n,m;
struct node{
	int nxt,to;
}e[Maxm];
int cnt,head[Maxn];
inline void add(int u,int v){
	++cnt;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}
int dfn[Maxn],low[Maxn];
int id;
stack<int> st;
int col[Maxn];
int too[Maxn];
int color;
inline void dfs(int x){
	dfn[x]=low[x]=++id;
	st.push(x);
	for(register int i=head[x];i;i=e[i].nxt){
		int y;
		y=e[i].to;
		writepl(x),writeln(y);
		if(!dfn[y]){
			dfs(y);
			low[x]=min(low[x],dfn[y]);
		}
		else low[x]=min(low[x],low[y]);
	}
	if(dfn[x]==low[x]){
		++color;
		int now;
		do{
			now=st.top();
			st.pop();
			col[now]=color;
			too[color]=now;
		}while(now!=x);
	}
}
//int f[Maxn][2];
int in[Maxn],out[Maxn];
vector<int> edge[Maxn];
int X[Maxn],Y[Maxn];
inline void init(){
	n=read();
	m=read();
	fr(i,1,m){
		int x,y;
		x=read();
		y=read();
		add(x,y);
		X[i]=x;
		Y[i]=y;
	}
}
int vis[Maxn];
inline void dfs1(int x,int Col){
//	cout<<x<<' '<<Col<<endl;
	vis[x]=Col;
	for(register int i=0;i<edge[x].size();++i){
		int y;
		y=edge[x][i];
//		cout<<y<<endl;
		if(vis[y]) continue;
		dfs1(y,Col);
	}
}
vector<int> vc[Maxn][2];
//inline void work(){
//	fr(i,1,n) col[i]=i;
////	fr(i,1,n) if(!dfn[i]) id=0,dfs(i);
////	puts("");
////	fr(i,1,n) writepl(i),writepl(dfn[i]),writeln(low[i]);
////	puts("");
////	fr(i,1,n) writepl(i),writeln(col[i]);
//	fr(i,1,m) {
////		writepl(X[i]);
////		writeln(Y[i]);
//		edge[col[X[i]]].push_back(col[Y[i]]);
//		edge[col[Y[i]]].push_back(col[X[i]]);
//		++in[col[Y[i]]],++out[col[X[i]]];
//	}
////	puts("");
//	int answer=0;
//	fr(i,1,n) if(!vis[i]) dfs1(i,++answer);
////	fr(i,1,n) writepl(i),writeln(vis[i]);
//	fr(i,1,n){
//		if(!in[i]) ++f[vis[i]][0],vc[vis[i]][0].push_back(i);
//		if(!out[i]) ++f[vis[i]][1],vc[vis[i]][1].push_back(i);
//	}
//	int ans=0;
//	fr(i,1,answer) ans+=max(f[i][0],f[i][1]);
//	writeln(ans);
//	fr(i,1,answer){
//		if(f[i][0]>f[i][1]) for(register int j=0;j<vc[i][0].size();++j) writepl(vc[i][0][j]);
//		else for(register int j=0;j<vc[i][1].size();++j) writepl(vc[i][1][j]);
//	}
//}
int Vis[Maxn];
int f[Maxn][2];
int F[Maxn];
inline void dfs2(int x){
	Vis[x]=1;
	for(register int i=head[x];i;i=e[i].nxt){
		int y;
		y=e[i].to;
		if(!Vis[y]) dfs2(y);
	}
	f[x][1]=1;
	for(register int i=head[x];i;i=e[i].nxt){
		int y;
		y=e[i].to;
		f[x][0]+=max(f[y][0],f[y][1]);
	}
	F[vis[x]]=max(F[vis[x]],max(f[x][0],f[x][1]));
}
inline void pprint(int x,int y){
	if(y==1){
		writepl(x);
		return;
	}
	for(register int i=head[x];i;i=e[i].nxt){
		int y;
		y=e[i].to;
		if(f[y][0]<=f[y][1]) pprint(y,1);
		else pprint(y,0);
	}
}
inline void print(int x){
	fr(i,1,n){
		if(!(vis[i]==x)) continue;
		if(f[i][0]==F[x]){
			pprint(i,0);
			return;
		}
		if(f[i][1]==F[x]){
			pprint(i,1);
			return;
		}
	}
}
inline void work(){
	fr(i,1,n) col[i]=i;
	fr(i,1,m) {
//		writepl(X[i]);
//		writeln(Y[i]);
		edge[col[X[i]]].push_back(col[Y[i]]);
		edge[col[Y[i]]].push_back(col[X[i]]);
	}
//	puts("");
	int answer=0;
	fr(i,1,n) if(!vis[i]) dfs1(i,++answer);
	fr(i,1,n) if(!Vis[i]) dfs2(i);
//	fr(i,1,n) writepl(i),writepl(vis[i]),writepl(f[i][0]),writeln(f[i][1]);
	int ans=0;
	fr(i,1,answer) ans+=F[i];
	writeln(ans);
	fr(i,1,answer) print(i);
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

