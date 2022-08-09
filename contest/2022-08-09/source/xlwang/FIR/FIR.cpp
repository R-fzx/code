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
const int Maxn=1e3+10;
int vis[Maxn][Maxn],flag[Maxn][Maxn],col[Maxn][Maxn];
int n;
struct node{
    int x,y;
}e[Maxn];
int X;
inline void init(){
    n=read();
    X=read();
}
vector<node> vc,g;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
inline bool check(int x,int y){
    return x>0 && y>0;
}
inline void dfs(int x,int y,int color){
    // cout<<x<<' '<<y<<endl;
    vc.push_back(node{x,y});
    fr(i,0,3){
        int nx,ny;
        nx=x+dx[i];
        ny=y+dy[i];
        if(!check(nx,ny)) continue;
        if(color!=col[nx][ny]) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny]=1;
        dfs(nx,ny,color);
        vis[nx][ny]=0;
    }
}
inline void tofind(int color){
    g.clear();
    // puts("");
    for(register int i=0;i<vc.size();++i){
        int x=vc[i].x;
        int y=vc[i].y;
        // cout<<x<<' '<<y<<' '<<color<<endl;
        fr(j,0,3){
            int nx,ny;
            nx=x+dx[j];
            ny=y+dy[j];
            // cout<<nx<<' '<<ny<<' '<<col[nx][ny]<<' '<<flag[nx][ny]<<endl;
            if(!check(nx,ny)) continue;
            if(color!=col[nx][ny]) continue;
            if(flag[nx][ny]) continue;
            flag[nx][ny]=1;
            g.push_back(node{nx,ny});
        }
    }
}
int now,pop;
int k;
inline void Check(int x,int y,int color){
    fr(i,0,3){
        int nx,ny;
        nx=x+dx[i];
        ny=y+dy[i];
        if(!check(nx,ny)) continue;
        if(col[nx][ny]==0) k=1;
        if(color!=col[nx][ny]) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny]=1;
        Check(nx,ny,color);
        vis[nx][ny]=0;
    }
}
inline void Check1(int x,int y,int color){
    flag[x][y]=0;
    fr(i,0,3){
        int nx,ny;
        nx=x+dx[i];
        ny=y+dy[i];
        if(!check(nx,ny)) continue;
        if(col[nx][ny]==0) k=1;
        if(color!=col[nx][ny]) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny]=1;
        // flag[nx][ny]=0;
        Check1(nx,ny,color);
        vis[nx][ny]=0;
    }
}
inline void Clear(int x,int y,int color){
    // cout<<"***"<<x<<' '<<y<<endl;
    col[x][y]=0;
    fr(i,0,3){
        int nx,ny;
        nx=x+dx[i];
        ny=y+dy[i];
        if(!check(nx,ny)) continue;
        if(color!=col[nx][ny]) continue;
        // col[nx][ny]=0;
        dfs(nx,ny,color);
    }
}
inline int checkwin(int x,int y,int color){
    int l,r;
    l=r=x;
    while(l && col[l-1][y]==color) --l;
    while(col[r+1][y]==color) ++r;
    if(r-l+1>=X) return 1;
    l=r=y;
    while(l && col[x][l-1]==color) --l;
    while(col[x][r+1]==color) ++r;
    if(r-l+1>=X) return 1;
    l=r=x;
    while(l && col[l-1][y-(x-l)-1]==color) --l;
    while(col[r+1][y+(r-x)+1]==color) ++r;
    if(r-l+1>=X) return 1;
    l=r=x;
    while(l && col[l-1][y+x-(l-1)]==color) --l;
    while(col[r+1][y+x-(r+1)]==color) ++r;
    if(r-l+1>=X) return 1;
    return 0;
}
inline void work(){
    fr(i,1,n){
        e[i].x=read();
        e[i].y=read();
        if(col[e[i].x][e[i].y]){
            // cout<<e[i].x<<' '<<e[i].y<<' '<<col[e[i].x][e[i].y]<<endl;
            // cout<<"*"<<endl;
            puts("illegal");
            // writeln(i);
            return;
        }
        int Col;
        if(i%2==1) Col=1;
        else Col=2;
        // cout<<i<<' '<<Col<<endl;
        col[e[i].x][e[i].y]=Col;
        // cout<<"qaqa"<<i<<endl;    
        // fr(ii,1,6){
        //     fr(jj,1,6) writepl(col[ii][jj]);
        //     puts("");
        // }
        vc.clear();
        // puts("");
        dfs(e[i].x,e[i].y,Col);
        tofind(3-Col);
        // if(i==11){
        //     for(register int j=0;j<vc.size();++j) writepl(vc[j].x),writeln(vc[j].y);
        //     for(register int j=0;j<g.size();++j) writepl(g[j].x),writeln(g[j].y);
        //     puts("*");
        // }
        now=0;
        pop=0;
        k=0;
        int K=0;
        for(register int j=0;j<g.size();++j){
            int x,y;
            x=g[j].x;
            y=g[j].y;
            if(!flag[x][y]) continue;
            flag[x][y]=0;
            k=0;
            Check1(x,y,3-Col);
            if(k==0){
                K=1;
                Clear(x,y,3-Col);
            }
        }
        if(!K){
            k=0;
            Check(e[i].x,e[i].y,Col);
            if(k==0){
                // cout<<"**"<<endl;
                puts("illegal");
                // writeln(i);
                return;
            }
        }
        int win=checkwin(e[i].x,e[i].y,Col);
        if(win){
            if(Col==1) printf("ITer %lld",i);
            else printf("Kitty %lld",i);
            return; 
        }
        // if(i==10){
        // cout<<"qaq"<<i<<endl;    
        // fr(ii,1,6){
        //     fr(jj,1,6) writepl(col[ii][jj]);
        //     puts("");
        // }
        // }
    }
    puts("draw");
}
signed main(){
    freopen("FIR.in","r",stdin);
    freopen("FIR.out","w",stdout);
    init();
    work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
