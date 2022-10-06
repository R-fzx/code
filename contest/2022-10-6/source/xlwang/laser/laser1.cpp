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
const int Maxn=1e4+10;
int to[10][10];
int now[10][10];
int n,k;
int a[20],b[20];
int L,R;
int c[20];
bool flag1[20];
bool flag2[20];
inline void init(){
	n=read();
	k=read();
}
int ln1,ln2;
inline void add(int l,int r){
	if(l>r) return;
//	writepl(l);
//	writeln(r);
	fr(i,l,r) fr(j,l,r) if(i!=j) ++now[i][j]; 
}
inline int ksm(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=sum*x;
		x=x*x;
		y=y/2;
	}
	return sum;
}
inline bool find(int x,int y,int z){
	int tot=ksm(10,x-1);
	int flag=0;
//	writeln(tot);
//	writepl(max(tot,L));
//	writeln(R);
	fr(i,max(tot,L),R){
		int now;
		int P=i/tot%10;
		now=i+(y-P)*tot;
		if(P!=z) continue;
		flag=1;
//		writepl(i);
//		writeln(now);
		if(!(now>=L && now<=R)) return false;
	}
	return flag;
}
inline void check(int l,int r){
	memset(now,0,sizeof(now));
	ln1=ln2=0;
	int x=l;
	while(x){
		c[++ln1]=x%10;
		x=x/10;
	}
	fr(i,1,ln1) a[i]=c[i];
	x=r;
	while(x){
		c[++ln2]=x%10;
		x=x/10;
	}
	fr(i,1,ln2) b[i]=c[i];
//	fr(i,1,ln1) write(a[i]);
//	puts("");
//	fr(i,1,ln2) write(b[i]);
//	puts("");
//	writeln(find(1,9,1));
	fr(i,1,k){
		fr(j,1,9) fr(l,1,9) now[j][l]+=(find(i,j,l)&find(i,l,j));
	}
	fr(i,1,9) fr(j,1,9) if(now[i][j]==k && now[j][i]==k) to[i][j]++;
	fr(i,1,k) fr(j,1,9) fr(l,1,9) writepl(i),writepl(j),writepl(l),writeln(find(i,j,l));
}
int vis[10];
inline void work(){
	fr(i,1,n){
		L=read();
		R=read();
		check(L,R);
	}
	fr(i,1,9){
		if(vis[i]) continue;
		write(i);
		vis[i]=1;
		fr(j,1,9) if(to[i][j]==n && !vis[j]) write(j),vis[j]=1;
		puts("");
	}
}
signed main(){
	freopen("laser.in","r",stdin);
	freopen("laser1.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

