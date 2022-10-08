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
const int Maxn=1e2+10;
int num[10][10];
int k,n,m,ex,ey;
int vis[Maxn][Maxn];
inline void clear(){
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
}
struct node{
	int c[10][10];
	bool operator < (const node &x) const {
		return c[0][0]>x.c[0][0];
	}
};
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,-1,1};
map<int,int> mp;
inline int getsum(node x){
	int ans=0;
	int now=1;
	fr(i,1,n) fr(j,1,m) ans+=x.c[i][j]*now,now=now*2;
	return ans;
}
inline bool check(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m;
}
inline void work1(){
	queue<node> q;
	node tmp;
	fr(i,1,n) fr(j,1,m) tmp.c[i][j]=vis[i][j];
	mp.clear();
	mp[getsum(tmp)]=1;
	q.push(tmp);
	int Ans=0;
	fr(i,1,n) fr(j,1,m) tmp.c[i][j]=0;
	tmp.c[ex][ey]=1;
	Ans=getsum(tmp);
	while(!q.empty()){
		tmp=q.front();
		q.pop();
//		fr(i,1,n){
//			fr(j,1,m) write(tmp.c[i][j]);
//			puts("");
//		}
//		puts("");
		if(Ans==getsum(tmp)){
			puts("YES");
			return;
		}
		fr(i,1,n) fr(j,1,m) fr(k,0,7){
			int nx=i+3*dx[k];
			int ny=j+3*dy[k];
			if(tmp.c[i][j]==1 && check(nx,ny) && tmp.c[nx][ny]==0){
				node tmp1=tmp;
				tmp1.c[i][j]=0;
				tmp1.c[nx][ny]=1;
				if(mp[getsum(tmp1)]!=1){
					mp[getsum(tmp1)]=1;
					q.push(tmp1);
				}
			}
		}
		fr(i,1,n) fr(j,1,m) fr(k,0,7){
			int nx=i+dx[k];
			int ny=j+dy[k];
			int mx,my;
			mx=i+2*dx[k];
			my=j+2*dy[k];
//			cout<<i<<' '<<j<<' '<<nx<<' '<<ny<<' '<<mx<<' '<<my<<endl;
			if(check(mx,my) && tmp.c[i][j]==1 && check(nx,ny) && tmp.c[nx][ny]==1 && tmp.c[mx][my]==0){
				node tmp1=tmp;
				tmp1.c[i][j]=0;
				tmp1.c[nx][ny]=0;
				tmp1.c[mx][my]=1;
//				cout<<i<<' '<<j<<' '<<nx<<' '<<ny<<' '<<mx<<' '<<my<<endl;
//				fr(ii,1,n){
//					fr(jj,1,m) write(tmp1.c[ii][jj]);
//					puts("");
//				}
//				cout<<mp[getsum(tmp1)]<<endl;
				if(mp[getsum(tmp1)]!=1){
//					fr(ii,1,n){
//						fr(jj,1,m) write(tmp1.c[ii][jj]);
//						puts("");
//					}
					mp[getsum(tmp1)]=1;
					q.push(tmp1);
				}
			}
		}
	}
	fr(i,1,n) fr(j,1,m) tmp.c[i][j]=0;
	tmp.c[ex][ey]=1;
//	fr(i,1,n){
//		fr(j,1,m) write(tmp.c[i][j]);
//		puts("");
//	} 
	puts("NO");
}
inline int getsum1(node x){
	int ans=0;
	int now=1;
	fr(i,1,3) fr(j,1,3) ans+=x.c[i][j]*now,now=now*10;
	return ans;
}
inline bool check1(int x,int y){
	return x>=0 && x<=n && y>=0 && y<=m;
}
inline void work2(){
	n=m=2;
	queue<node> q;
	node tmp;
	fr(i,1,n) fr(j,1,m) tmp.c[i][j]=num[i][j];
	mp.clear();
	mp[getsum(tmp)]=1;
	q.push(tmp);
	int Ans=0;
	fr(i,1,n) fr(j,1,m) tmp.c[i][j]=0;
	tmp.c[ex][ey]=1;
	Ans=getsum(tmp);
	while(!q.empty()){
		tmp=q.front();
		q.pop();
//		fr(i,1,n){
//			fr(j,1,m) write(tmp.c[i][j]);
//			puts("");
//		}
//		puts("");
		if(Ans==getsum(tmp)){
			puts("YES");
			return;
		}
		fr(i,0,n) fr(j,0,m) fr(k,0,7){
			int nx=i+dx[k];
			int ny=j+dy[k];
			int mx,my;
			mx=i+2*dx[k];
			my=j+2*dy[k];
			nx=nx+3,nx%=3,ny=ny+3,ny%=3,mx=mx+3,mx%=3,my=my+3,my%=3;
//			cout<<i<<' '<<j<<' '<<nx<<' '<<ny<<' '<<mx<<' '<<my<<endl;
			if(check(mx,my) && tmp.c[i][j]>=1 && check(nx,ny) && tmp.c[nx][ny]>=1){
				node tmp1=tmp;
				tmp1.c[i][j]--;
				tmp1.c[nx][ny]--;
				tmp1.c[mx][my]++;
//				cout<<i<<' '<<j<<' '<<nx<<' '<<ny<<' '<<mx<<' '<<my<<endl;
//				fr(ii,1,n){
//					fr(jj,1,m) write(tmp1.c[ii][jj]);
//					puts("");
//				}
//				cout<<mp[getsum(tmp1)]<<endl;
				if(mp[getsum(tmp1)]!=1){
//					fr(ii,1,n){
//						fr(jj,1,m) write(tmp1.c[ii][jj]);
//						puts("");
//					}
					mp[getsum(tmp1)]=1;
					q.push(tmp1);
				}
			}
		}
	}
//	fr(i,1,n){
//		fr(j,1,m) write(tmp.c[i][j]);
//		puts("");
//	} 
	puts("NO");
}
inline void work(){
	fr(i,1,k){
		int x,y;
		x=read();
		y=read();
		vis[x][y]=1;
		++num[x%3][y%3];
	}
	if(n<=5 && m<=5) {
		work1();
		return;
	}
	work2();
}
inline void init(){
	while(cin>>k>>n>>m>>ex>>ey){
		clear();
		work();
	}
}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	init();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

