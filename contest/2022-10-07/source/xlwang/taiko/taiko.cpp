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
//int c[50][50];
//inline void init(){
//	fr(i,0,32) c[i][0]=1;
//	fr(i,1,32) fr(j,1,i) c[i][j]=c[i-1][j-1]+c[i-1][j];
//	writeln(c[32][16]);
//}
//const int Maxn=1e5+10;
//int n;
//int a[Maxn];
//inline void init(){
//	n=read();
//}
//inline int ksm(int x,int y){
//	int sum=1;
//	while(y){
//		if(y&1) sum=sum*x;
//		x=x*x;
//		y=y/2;
//	}
//	return sum;
//}
//int num[2];
//int vis[Maxn];
//map<int,int> mp;
//inline void check(){
//	num[0]=num[1]=0;
//	fr(i,1,ksm(2,n)) ++num[a[i]];
//	if(num[0]!=num[1]) return;
////	fr(i,1,ksm(2,n)) write(a[i]);
////	puts("");
//	fr(i,1,ksm(2,n)) fr(j,i+1,ksm(2,n)){
//		int flag=1;
//		int now1,now2;
//		now1=i;
//		now2=j;
//		for(register int k=0;k<n;++k){
//			if(a[now1]!=a[now2]){
//				flag=0;
//				break;
//			}
//			++now1,++now2;
//		}
//		if(flag) return;
//	}
//	int s=0;
//	fr(i,1,ksm(2,n)) s=s+a[i]*ksm(2,i-1);
//	if(mp[s]) return;
//	mp[s]=1; 
//	fr(i,1,ksm(2,n)) write(a[i]);
//	puts("");
////	exit(0);
//}
//inline void dfs(int x){
//	if(x==(ksm(2,n)-n+1)){
//		check();
//		return;
//	}
//	a[x]=1;
//	dfs(x+1);
//	a[x]=0;
//	dfs(x+1);
//}
//inline void work(){
//	fr(i,1,n) a[i]=0;
//	fr(i,ksm(2,n)-n+1,ksm(2,n)) a[i]=1;
////	fr(i,n+1,2*n) a[i]=1;
////	num[0]=num[1]=n;
////	dfs(2*n+1);
//	dfs(n+1);
//}
const int Maxn=1e5+10;
int n;
int num[Maxn];
int vis[Maxn];
int to[Maxn][2];
inline void check(){
	writepl(1<<n);
	fr(i,1,n) write(0);
	fr(j,2,(1<<n)-n+1) write(num[j]%2);
	exit(0);
}
inline void dfs(int x,int z){
	if(z==(1<<n)+1){
		check();
		return;
	}
	fr(i,0,1){
		int y;
		y=to[x][i];
		if(vis[y]) continue;
		num[z]=y;
		vis[y]=1;
		dfs(y,z+1);
		vis[y]=0;
	}
}
inline void init(){
	n=read();
}
inline void work(){
	fr(i,0,(1<<n)-1) to[i][0]=to[i][1]=-1;
	fr(i,0,(1<<n)-1) fr(j,0,(1<<n)-1){
		int now1,now2;
		if(i>=(1<<(n-1))) now1=i-(1<<(n-1));
		else now1=i;
		now2=j/2;
		if(now1==now2){
			if(to[i][0]!=-1) to[i][1]=j;
			else to[i][0]=j;
		}
	}
	fr(i,0,(1<<n)-1) if(to[i][0]>to[i][1]) swap(to[i][0],to[i][1]);
//	fr(i,0,(1<<n)-1) writepl(i),writepl(to[i][0]),writeln(to[i][1]);
	dfs(0,1);
}
signed main(){
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout); 
    init();
    work();
	// printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

