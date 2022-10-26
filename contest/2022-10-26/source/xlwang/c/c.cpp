#include<bits/stdc++.h>
#define int unsigned long long
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
const int Maxn=1e5+10,inf=1e15;
int a[Maxn],n;
inline void init(){
	n=read();
	fr(i,1,n) a[i]=read();
}
inline int getsum(int x,int y){
	int sum=0;
	fr(i,0,59){
		while(1){
			int now1,now2;
			now1=((x>>i)&1);
			now2=((y>>i)&1);
			if(now1==now2) break;
//			cerr<<now1<<' '<<now2<<' '<<x<<' '<<y<<endl;
			++sum,x+=(1ll<<i);
		}
	}
	if(x!=y) return -1;
	return sum;
}
inline void work1(){
	int maxn=0;
	fr(i,1,n) maxn=max(maxn,a[i]);
	int ans=inf;
	fr(i,maxn,maxn+1000){
		int tot=0;
		fr(j,1,n){
			int now;
			now=getsum(a[j],i);
			if(now==-1){
				tot=-1;
				break;
			}
			tot+=now;
		}
		if(tot==-1) continue;
		ans=min(ans,tot);
	}
	writeln(ans);
}
inline void work2(){
	int maxn=0;
	fr(i,1,n) maxn=max(maxn,a[i]);
	int ans=inf;
	fr(i,maxn,maxn+500){
		int tot=0;
		fr(j,1,n){
			int now;
			now=getsum(a[j],i);
			if(now==-1){
				tot=-1;
				break;
			}
			tot+=now;
		}
		if(tot==-1) continue;
		ans=min(ans,tot);
	}
	writeln(ans);
}
inline void work(){
	if(n<=20){
		work1();
		return;
	}
	work2();
	return;
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	init();work();
	return 0;
}

