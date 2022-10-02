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
const int Maxn=510;
int a[Maxn][Maxn],l[Maxn][Maxn],r[Maxn][Maxn],num[Maxn][Maxn];
struct node{
	int x,y;
	int number;
}e[Maxn*Maxn];
inline bool cmp(node a,node b){
	return a.number<b.number;
}
int cnt;
int n;
inline void init(){
	n=read();
	fr(i,1,n) fr(j,1,n) num[i][j]=read();
	fr(i,1,n) fr(j,1,n){
		if(num[i][j]==0) continue;
		if(i>j) continue;
		e[++cnt].x=i,e[cnt].y=j,e[cnt].number=num[i][j];
	}
	sort(e+1,e+cnt+1,cmp);
	fr(i,1,n) fr(j,1,n) l[i][j]=read();
	fr(i,1,n) fr(j,1,n) r[i][j]=read();
	fr(i,1,n) fr(j,1,n) {
		if(!num[i][j]) a[i][j]=l[i][j];
		else a[i][j]=r[i][j];
	}
}
inline int out(){
	int ans=0;
	fr(i,1,n) fr(j,1,n) ans+=num[i][j]*a[i][j];
	return ans;
}
inline void work1(int x){
	int flag=0;
	fr(i,1,n) if(num[i][i]==0){
		flag=1;
		break;
	}
	if(!flag && x%2==1){
		int answer=out(),minn=num[1][1];
		fr(i,1,n) minn=min(minn,num[i][i]);
		writeln(answer-minn);
		return;
	}
	int answer=out();
	writeln(answer);
}
inline void work2(int x){
	fr(i,1,cnt){
		int nx,ny;
		nx=e[i].x;
		ny=e[i].y;
		if(x==0 || x==1) break;
		if(x<=2*(a[nx][ny]-l[nx][ny])){
			int y;
			if(x%2==1) y=-1;
			y+=x;
			x-=y;
			y=y/2;
			a[nx][ny]-=y;
			a[ny][nx]-=y;
		}
		else {
			x-=2*(a[nx][ny]-l[nx][ny]);
			a[nx][ny]=l[nx][ny];
			a[ny][nx]=l[nx][ny];
		}
	}
	if(x==0){
		int answer=out();
		writeln(answer);
		return;
	}
	int answer=out();
	int minn1,minn2;
	int flag=0;
	minn1=0;
	int maxn1=0;
	minn2=100000000;
	fr(i,1,n) if(!(a[i][i]==r[i][i])){
		flag=1;
		maxn1=max(maxn1,num[i][i]);
	}
	fr(i,1,n) fr(j,1,n){
		if(i==j){
			if(a[i][j]!=l[i][j]) minn2=min(minn2,num[i][j]);
		}
		else {
			if(a[i][j]!=l[i][j] && flag) minn1=min(minn1,num[i][j]+num[j][i]);
		}
	}
	answer=answer-min(minn2,minn1-maxn1);
	writeln(answer);
}
inline void work(){
	int ans=0;
	fr(i,1,n) fr(j,1,n) ans+=a[i][j];
	if(ans<=0){
		work1(ans);
		return;
	}
	work2(ans);
	return;
}
signed main(){
	freopen("garland.in","r",stdin);
	freopen("garland.out","w",stdout);
	init();
	work(); 
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

