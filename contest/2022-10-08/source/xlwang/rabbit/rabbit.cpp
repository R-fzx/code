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
const int Maxn=10;
int n;
int ans;
inline void init(){
	n=read();
}
int num[Maxn][Maxn];
int answer[Maxn*Maxn][3];
inline void dfs(int x){
	ans=max(ans,x);
	if(ans==n*(n-1)/2) return;
	fr(i,1,n) fr(j,i+1,n) fr(k,j+1,n) {
		if(num[i][j]>=3 || num[j][k]>=3 || num[i][k]>=3) continue;
		++num[j][k],++num[i][j],++num[i][k];
		dfs(x+1);
		--num[j][k],--num[i][j],--num[i][k];
	}
}
inline void out(){
	writeln(ans);
	fr(i,1,ans) writepl(answer[i][0]),writepl(answer[i][1]),writeln(answer[i][2]);
	puts("");
}
inline void dfs1(int x){
	if(x==ans){
		out();
		exit(0);
		return;
	}
	fr(i,1,n) fr(j,i+1,n) fr(k,j+1,n) {
		if(num[i][j]>=3 || num[j][k]>=3 || num[i][k]>=3) continue;
		++num[j][k],++num[i][j],++num[i][k];
		answer[x+1][0]=i,answer[x+1][1]=j,answer[x+1][2]=k;
		dfs1(x+1);
		--num[j][k],--num[i][j],--num[i][k];
	}
}
inline void work(){
	if(n>=9){
		writeln(n*(n-1)/2);
		write(1);
		return;
	} 
	dfs(0);
	memset(num,0,sizeof(num));
	dfs1(0);
}
signed main(){
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

