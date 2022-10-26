#include<bits/stdc++.h>
#define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define randfind(l,r) (l+(rand()%(r-l+1)))
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void writepl(int x){write(x);putchar(' ');}
inline void writeln(int x){write(x);puts("");}
const int Maxn=3e3+10;
int n,k;
int m;
int h[Maxn];
struct node{
	int x,y;
}e[Maxn];
inline void init(){
	n=read();
	k=read();
	fr(i,1,n) h[i]=read();
	m=read();
	fr(i,1,m) e[i].x=read(),e[i].y=read();
}
int f[Maxn][20];
inline int query(int l,int r){
	int tot;
	tot=(int)(log(r-l+1)/log(2));
	return min(f[l][tot]+f[r-(1<<tot)+1][tot]);
}
inline void work(){
	int ln;
	ln=(int)(log(r-l+1)/log(2));
	fr(i,1,n) f[i][0]=h[i];
	fr(i,1,ln) fr(j,1,n-(1<<i)+1) f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	int ans=0;
//	fr(i,1,m){
//		fr(j,i+1,m){
//			int l,r;
//			l=min(e[i].x,e[j].x);
//			r=max(e[i].x,e[j].x);
//			if(e[i].x==e[j].x){
//				if(abs(e[i].y-e[j].y)<=k) ++ans;
//			}
//			int tot;
//			tot=
//		}
//	}
}
signed main(){
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	init();
	writeln(m*(m-1)/2);
	return 0;
}

