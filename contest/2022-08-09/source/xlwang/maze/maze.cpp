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
int f[25][25][20010];
int a[25][25];
int n,m,k;
inline void init(){
    n=read();
    m=read();
    k=read();
    fr(i,1,n) fr(j,1,m) a[i][j]=read();
}
int ans;
inline bool find(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=m) return 1;
    return 0;
}
int dx[]={0,1};
int dy[]={1,0};
pair<int,int> num[10010];
int cnt;
inline void check(){
    int now=0;
    fr(i,1,cnt) now=now^a[num[i].first][num[i].second];
    if(now==k) ++ans;
}
inline void dfs(int x,int y){
    if(x==n && y==m){
        check();
        return;
    }
    fr(i,0,1){
        int nx;
        int ny;
        nx=x+dx[i];
        ny=y+dy[i];
        if(!find(nx,ny) || a[nx][ny]==0) continue;
        num[++cnt]=make_pair(nx,ny);
        dfs(nx,ny);
        --cnt;
    }
}
inline void work1(){
    num[++cnt]=make_pair(1ll,1ll);
    dfs(1,1);
    writeln(ans);
}
inline void work(){
    if(n<=10 && m<=10){
        work1();
        return;
    }
    int flag=0;
    fr(i,1,n) fr(j,1,m){
        if(a[i][j]>10000){
            flag=1;
            break;
        }
    }
    if(n<=20 && m<=20 && flag==0){
        f[1][1][a[1][1]]=1;
        fr(i,1,n) fr(j,1,m){
            if(i==1 && j==1) continue;
            if(a[i][j]==0) continue;
            fr(l,0,20000) f[i][j][l]+=f[i][j-1][l^a[i][j]]+f[i-1][j][l^a[i][j]];
        }
        // writeln(f[2][1][3]);
        writeln(f[n][m][k]);
        return;
    }
    work1();
    return;
}
signed main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    init();
    work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
