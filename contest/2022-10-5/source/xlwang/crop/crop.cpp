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
const int Maxn=1e5+10;
int n,a,b,c,d,m;
int x[Maxn],y[Maxn];
inline void into(){
	int X,Y;
	X=x[1];
	Y=y[1];
	fr(i,2,n){
		X=(X*a+b)%m;
		Y=(Y*c+d)%m;
		x[i]=X;
		y[i]=Y;
	}
}
int nx[4],ny[4];
int num[3][3];
int ans;
inline void check(){
	if(!((nx[1]+nx[2]+nx[3])%3==0)) return;
	if(!((ny[1]+ny[2]+ny[3])%3==0)) return;
//	fr(i,1,3) writepl(nx[i]),writeln(ny[i]);
//	puts("");
	if(nx[1]==nx[2] && nx[1]==nx[3] && ny[1]==ny[2] && ny[1]==ny[3]) ans+=num[nx[1]][ny[1]]*(num[nx[1]][ny[1]]-1)*(num[nx[1]][ny[1]]-2);
	else if(nx[1]==nx[2] && ny[1]==ny[2]) ans+=num[nx[1]][ny[1]]*(num[nx[1]][ny[1]]-1)*num[nx[3]][ny[3]];
	else if(nx[1]==nx[3] && ny[1]==ny[3]) ans+=num[nx[1]][ny[1]]*(num[nx[1]][ny[1]]-1)*num[nx[2]][ny[2]];
	else if(nx[2]==nx[3] && ny[2]==ny[3]) ans+=num[nx[1]][ny[1]]*(num[nx[2]][ny[2]])*(num[nx[2]][ny[2]]-1);
	else ans+=num[nx[1]][ny[1]]*num[nx[2]][ny[2]]*num[nx[3]][ny[3]];
}
inline void dfs(int x){
	if(x==4){
		check();
		return;
	}
	fr(i,0,2) fr(j,0,2){
		nx[x]=i;
		ny[x]=j;
		dfs(x+1);
	}
}
inline void init(){
	n=read(),a=read(),b=read(),c=read(),d=read(),x[1]=read(),y[1]=read(),m=read();
	into();
	fr(i,1,n) ++num[x[i]%3][y[i]%3];
//	fr(i,0,2) fr(j,0,2) writepl(i),writepl(j),writeln(num[i][j]);
	dfs(1);
//	fr(i,1,n) writepl(x[i]),writeln(y[i]);
	writeln(ans/6);
}
signed main(){
	freopen("crop.in","r",stdin);
	freopen("crop.out","w",stdout);
	init();
//	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

