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
int c[20];
bool flag1[20];
int num[20];
bool flag2[20];
inline void init(){
	n=read();
	k=read();
}
int ln1,ln2;
int L,R;
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
//	writeln(tot);
//	writepl(max(tot,L));
//	writeln(R);
	fr(i,max(tot,L),R){
		int now;
		int P=i/tot%10;
		now=i+(y-P)*tot;
		if(P!=z) continue;
//		writepl(i);
//		writeln(now);
		if(!(now>=L && now<=R)) return false;
	}
	return 1;
}
inline void add(int l,int r){
	if(l>r) return;
//	writepl(l);
//	writeln(r);
	fr(i,l,r) fr(j,l,r) if(i!=j) ++now[i][j]; 
}
inline void getsum(int x){
	while(x){
		num[x%10]++;
		x=x/10;
	}
}
inline void check(int l,int r){
	memset(flag1,0,sizeof(flag1)),memset(flag2,0,sizeof(flag2)),memset(now,0,sizeof(now)),memset(num,0,sizeof(num));
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
	if(r-l<=100){
		fr(i,l,r) getsum(i);
		fr(i,1,k){
			fr(j,1,9) fr(l,1,9) now[j][l]+=(find(i,j,l)&find(i,l,j));
		}
		fr(i,1,9) fr(j,1,9) if(now[i][j]==k && now[j][i]==k && num[i] && num[j]) to[i][j]++;
		return;
	}
//	fr(i,1,ln1) write(a[i]);
//	puts("");
//	fr(i,1,ln2) write(b[i]);
//	puts("");
	flag1[0]=1;
	fr(i,1,k) flag1[i]=flag1[i-1]&(a[i]==0);
	flag2[0]=1;
	fr(i,1,k) flag2[i]=flag2[i-1]&(b[i]==9);
	rf(i,k,1){
		if(flag1[i-1]) add(1,a[i]-1),add(a[i],9);
		else add(1,a[i]-1),add(a[i],a[i]),add(a[i]+1,9);
		if(flag2[i-1]) add(1,b[i]),add(b[i]+1,9);
		else add(1,b[i]-1),add(b[i],b[i]),add(b[i]+1,9);
	}
	fr(i,1,9) fr(j,1,9) if(now[i][j]==2*k) ++to[i][j]; 
}
int vis[10];
inline void work(){
	fr(i,1,n){
		int l,r;
		l=read();
		r=read();
		L=l;
		R=r;
		check(l,r);
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
	freopen("laser.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

