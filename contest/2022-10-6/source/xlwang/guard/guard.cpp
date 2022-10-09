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
const int Maxn=2e2+10;
double f[Maxn];
double g[Maxn][Maxn];
int n,l,siz;
double h[Maxn][Maxn];
struct node{
	double val;
	int a;
}e[Maxn];
inline bool cmp(node a,node b){
	return a.a<b.a;
}
inline void init(){
	n=read();
	l=read();
	siz=read();
	fr(i,1,n) cin>>e[i].val,e[i].val/=100.0;
	fr(i,1,n) e[i].a=read();
}
inline void work(){
	sort(e+1,e+n+1,cmp);
	int now=0;
	fr(i,1,n) {
		if(e[i].a!=-1){
			now=i-1;
			break;
		}
	}
	f[0]=1;
	fr(i,1,now){
		rf(j,i,1) f[j]=f[j]*(1.0-e[i].val)+f[j-1]*e[i].val;
		f[0]=f[0]*(1.0-e[i].val);
//		fr(j,0,now) printf("%.3lf ",f[j]);
//		puts("");
	}
//	fr(i,0,now) printf("%.3lf ",f[i]);
//	puts("");
	g[0][0]=1;
	fr(k,now+1,n){
		fr(i,0,n) fr(j,0,n) h[i][j]=g[i][j],g[i][j]=g[i][j]*(1.0-e[k].val);
		fr(i,0,k-now) fr(j,0,n) g[i+1][min(n,j+e[k].a)]+=h[i][j]*e[k].val;
	}
//	fr(i,0,n) fr(j,0,n) printf("g[%lld][%lld]=%.6lf\n",i,j,g[i][j]);
	double ans=0;
	fr(i,0,n) fr(j,0,n) fr(k,0,n){
		if(i+j<l) continue;
		if(k+siz<i) continue;
		ans+=f[i]*g[j][k];
	}
	printf("%.6lf\n",ans);
}
signed main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
