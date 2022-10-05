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
const int Maxn=1e2+10,inf=1e9;
int n;
char c[Maxn][Maxn];
int dis[Maxn][Maxn];
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,1,-1};
inline bool check(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=n;
}
struct node{
	int x;
	int y;
	int dis;
	bool operator < (const node &x) const {
		return dis>x.dis;
	}
};
priority_queue<node> q;
inline void init(){
	n=read();
	fr(i,1,n) scanf("%s",c[i]+1);
}
int ex,ey;
int vis[Maxn][Maxn];
map<int,int> mp[Maxn][Maxn];
inline void dij(){
	fr(i,1,n) fr(j,1,n) dis[i][j]=inf;
	fr(i,1,n) fr(j,1,n){
		if(c[i][j]=='*'){
			dis[i][j]=0;
			node tmp;
			tmp.x=i;
			tmp.y=j;
			tmp.dis=0;
			q.push(tmp);
		}
	}
	while(!q.empty()){
		node tmp;
		tmp=q.top();
		q.pop();
		if(vis[tmp.x][tmp.y]) continue;
		vis[tmp.x][tmp.y]=1;
		if(tmp.x==ex && tmp.y==ey){
			writeln(tmp.dis);
			return;
		}
		fr(i,0,7){
			int nx=tmp.x+dx[i];
			int ny=tmp.y+dy[i];
			if(!check(nx,ny)) continue;
			if(c[nx][ny]=='X') continue;
			if(!mp[nx][ny][tmp.dis] || mp[nx][ny][tmp.dis]==i){
				if(dis[nx][ny]>dis[tmp.x][tmp.y]+3){
					mp[nx][ny][tmp.dis]=i;
					dis[nx][ny]=dis[tmp.x][tmp.y]+3;
					if(!vis[nx][ny]){
						node ttmp;
						ttmp.x=nx;
						ttmp.y=ny;
						ttmp.dis=dis[nx][ny];
						q.push(ttmp);
					}
				}
			}
			else {
				if(dis[nx][ny]>dis[tmp.x][tmp.y]+1){
					dis[nx][ny]=dis[tmp.x][tmp.y]+1;
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
	puts("-1");
}
inline void work(){
	fr(i,1,n) fr(j,1,n){
		if(c[i][j]=='@'){
			ex=i;
			ey=j;
			break;
		}
	}
	dij();
}
signed main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
    init();
    work();
	// printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

