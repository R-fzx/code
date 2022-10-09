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
const int Maxn=2e2+10,inf=1e11;
int f[Maxn][Maxn*Maxn][2];
int n;
int ans[Maxn][2];
int x[Maxn],y[Maxn];
inline void init(){
	n=read();
	fr(i,1,n) x[i]=read(),y[i]=read();
}
inline void work(){
	fr(i,0,n) fr(j,0,200*n) f[i][j][0]=f[i][j][1]=inf;
	fr(i,0,n) ans[i][0]=ans[i][1]=inf;
	f[0][0][0]=f[0][0][1]=0;
	int sum=0; 
	fr(i,1,n){
		fr(j,0,sum) {
			f[i][j][0]=min(f[i][j][0],f[i-1][j][0]+(sum-j)*x[i]-j*x[i]);
			f[i][j+x[i]][0]=min(f[i][j+x[i]][0],f[i-1][j][0]+j*x[i]-(sum-j)*x[i]);
			ans[i][0]=min(ans[i][0],min(f[i][j][0],f[i][j+x[i]][0]));
		}
		sum+=x[i];
	}
	sum=0;
	fr(i,1,n){
		fr(j,0,sum) {
			f[i][j][1]=min(f[i][j][1],f[i-1][j][1]+(sum-j)*y[i]-j*y[i]);
			f[i][j+y[i]][1]=min(f[i][j+y[i]][1],f[i-1][j][1]+j*y[i]-(sum-j)*y[i]);
			ans[i][1]=min(ans[i][1],min(f[i][j][1],f[i][j+y[i]][1]));
		}
		sum+=y[i];
	}
//	writepl(ans[n][0]),writeln(ans[n][1]);
	write(ans[n][0]+ans[n][1]);
	puts(".00");
}
signed main(){
	freopen("seventeen.in","r",stdin);
	freopen("seventeen.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

