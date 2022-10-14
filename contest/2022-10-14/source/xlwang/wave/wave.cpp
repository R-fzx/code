//#define fastcall __attribute__((optimize("-O3")))
//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse")
//#pragma GCC optimize("-fgcse-lm")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-ftree-pre")
//#pragma GCC optimize("-ftree-vrp")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-falign-jumps")
//#pragma GCC optimize("-falign-loops")
//#pragma GCC optimize("-falign-labels")
//#pragma GCC optimize("-fdevirtualize")
//#pragma GCC optimize("-fcaller-saves")
//#pragma GCC optimize("-fcrossjumping")
//#pragma GCC optimize("-fthread-jumps")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-fwhole-program")
//#pragma GCC optimize("-freorder-blocks")
//#pragma GCC optimize("-fschedule-insns")
//#pragma GCC optimize("inline-functions")
//#pragma GCC optimize("-ftree-tail-merge")
//#pragma GCC optimize("-fschedule-insns2")
//#pragma GCC optimize("-fstrict-aliasing")
//#pragma GCC optimize("-fstrict-overflow")
//#pragma GCC optimize("-falign-functions")
//#pragma GCC optimize("-fcse-skip-blocks")
//#pragma GCC optimize("-fcse-follow-jumps")
//#pragma GCC optimize("-fsched-interblock")
//#pragma GCC optimize("-fpartial-inlining")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("-freorder-functions")
//#pragma GCC optimize("-findirect-inlining")
//#pragma GCC optimize("-fhoist-adjacent-loads")
//#pragma GCC optimize("-frerun-cse-after-loop")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-ftree-switch-conversion")
//#pragma GCC optimize("-foptimize-sibling-calls")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#include<bits/stdc++.h>
//#define int long long
//#define fr(i,j,k) for(register int i=j;i<=k;++i)
//#define rf(i,j,k) for(register int i=j;i>=k;--i)
//#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
//#define randfind(l,r) (rand()%((r)-(l)+1)+(l))
//#define pb push_back
//#define Times printf("Time:%.3lf\n",clock()/CLOCKS_PER_SEC)
//using namespace std;
//inline int read(){
//	int x=0;
//	bool f=0;
//	char c=getchar();
//	while(!isdigit(c)) f|=(c=='-'),c=getchar();
//	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
//	return f?-x:x;
//}
//inline void write(int x){
//    if(x<0){putchar('-');x=-x;}
//    if(x>9)write(x/10);
//    putchar(x%10+'0');
//}
//inline void writeln(int x){write(x); puts("");}
//inline void writepl(int x){write(x); putchar(' ');}
//const int Maxn=30,Maxm=(1<<20)+10;
//int n;
//int a[Maxn];
//int num[Maxn];
//inline void work(){
//	fr(i,1,n) a[i]=i;
//	memset(num,0,sizeof(num));
//	int answer=0;
//	do{
//		int flag=1;
//		fr(i,2,n-1){
//			int now=0;
//			if(a[i]>a[i-1]) ++now;
//			if(a[i]>a[i+1]) ++now;
//			if(now==1){
//				flag=0;
//				break;
//			}
//		}
//		if(flag) {
//			fr(i,1,n) writepl(a[i]);
//			puts("");
//			++answer;
//			++num[a[1]];
//		}
//	}while(next_permutation(a+1,a+n+1));
//	writeln(answer);
//	fr(i,1,n) writepl(i),writeln(num[i]);
//}
//inline void init(){
//	while(cin>>n) work(),puts("");
//}
//signed main(){
//	freopen("wave.in","r",stdin);
//	freopen("wave.out","w",stdout); 
//	init();
//    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
//	return 0;
//}
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
const int Maxn=30;
int f[Maxn][Maxn][2];
int g[Maxn][Maxn][2];
int sum[Maxn];
int vis[Maxn];
int n,c;
inline void add(int l,int r){
	if(l>r) return;
	fr(i,l,r) ++sum[i];
}
inline int Find(int x){
//	fr(i,1,n) writepl(vis[i]);
//	puts("");
//	writepl(x);
	int sum=0;
	fr(i,1,n){
		if(!vis[i]){
			++sum;
			if(sum==x){
				vis[i]=1;
				return i;
			}
		}
	}
}
inline void dfs(int x,int now,int flag,int tot){
//	cout<<endl<<x<<' '<<now<<' '<<flag<<' '<<tot<<endl;
	writepl(Find(now));
	if(x==1) return;
	if(x==2){
		fr(i,1,n) if(!vis[i]){
//			putchar('*');
			write(i);
			return;
		}
	}
	memset(g,0,sizeof(g));
	g[2][1][1]=g[2][2][0]=1;
	fr(i,3,x) fr(j,1,i) fr(k,1,i){
		if(j==k) continue;
		if(j<k){
			g[i][j][1]+=g[i-1][k-1][0];
			if(i==x && j==now && flag==1 && g[i][j][1]>=tot){
				dfs(i-1,k-1,0,tot-g[i][j][1]+g[i-1][k-1][0]);
				return;
			}
		}
		else{
			g[i][j][0]+=g[i-1][k][1];
			if(i==x && j==now && flag==0 && g[i][j][0]>=tot){
				dfs(i-1,k,1,tot-g[i][j][0]+g[i-1][k][1]);
				return;
			}
		}
	}
}
inline void work(){
	n=read();
	c=read();
//	if(n==1 && c==1){
//	cout<<1;
//	return;
//}
	memset(vis,0,sizeof(vis));
	memset(sum,0,sizeof(sum));
	fr(i,1,n){
		if(f[n][i][0]<c) c-=f[n][i][0];
		else {
			dfs(n,i,0,c);
			return;
		}
		if(f[n][i][1]<c) c-=f[n][i][1];
		else {
			dfs(n,i,1,c);
			return;
		}
	}
}
inline void init(){
	int N=20;
	f[2][1][1]=f[2][2][0]=1;
	fr(i,3,N) fr(j,1,i) fr(k,1,i){
		if(j==k) continue;
		if(j<k) f[i][j][1]+=f[i-1][k-1][0];
		else f[i][j][0]+=f[i-1][k][1];
	}
//	fr(j,1,4) fr(k,0,1) printf("f[4][%lld][%lld]=%lld\n",j,k,f[4][j][k]);
	int t=read();
	while(t--) work(),puts("");
}
signed main(){
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	init();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

