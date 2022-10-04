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
const int Maxn=1e2+10,inf=1e7;
const double eps=1e-7;
char c[Maxn][Maxn];
double ans;
int n,m;
struct node{
	int x,y;
	double dis;
	bool operator < (const node &x) const {
		return dis>x.dis;
	}
};
priority_queue<node> q;
int vis[Maxn][Maxn];
double dis[Maxn][Maxn];
int tx,ty,sx,sy;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
inline bool find(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m;
}
inline void dij(double x){
	node tmp;
	tmp.x=tx,tmp.y=ty,tmp.dis=0;
	dis[tx][ty]=0;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		if(vis[tmp.x][tmp.y]) continue;
		vis[tmp.x][tmp.y]=1;
		fr(i,0,3){
			int nx,ny;
			nx=tmp.x+dx[i];
			ny=tmp.y+dy[i];
			if(!find(nx,ny)) continue;
			if(c[nx][ny]=='#') continue;
			double us=0;
			if(ny==tmp.y) us=x;
			else us=1.0;
			if(dis[nx][ny]>dis[tmp.x][tmp.y]+us){
				dis[nx][ny]=dis[tmp.x][tmp.y]+us;
				if(!vis[nx][ny]){
					node ttmp;
					ttmp.x=nx;
					ttmp.y=ny;
					ttmp.dis=dis[nx][ny];
					q.push(ttmp);
				}
			}
		}
	}
}
inline bool check(double x){
//	cout<<x<<endl;
	fr(i,1,n) fr(j,1,m) dis[i][j]=inf,vis[i][j]=0;
	dij(x);
//	fr(i,1,n){
//		fr(j,1,m) printf("%.3lf ",dis[i][j]);
//		puts("");
//	}
	return dis[sx][sy]<=ans;
}
inline void work(){
	cin>>ans;
	n=read();
	m=read();
	fr(i,1,n) fr(j,1,m){
		char s;
		while(1){
			s=getchar();
			if(s==' ' || s=='#' || s=='S' || s=='E') break;
		}
		c[i][j]=s;
		if(s=='S') tx=i,ty=j;
		if(s=='E') sx=i,sy=j;
	}
//	cout<<tx<<' '<<ty<<' '<<sx<<' '<<sy<<endl;
	double l,r;
	l=0;
	r=10.0;
	while(r-l>eps){
		double mid;
		mid=(l+r)*0.5;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.5lf\n",l);
//	fr(i,1,n){
//		fr(j,1,m) putchar(c[i][j]);
//		puts("");
//	}
//	return;
}
inline void init(){
	int t=read();
	while(t--) work();
	return;
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	init();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

