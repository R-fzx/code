#include<bits/stdc++.h>
#define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
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
inline void writeln(int x){write(x);putchar('\n');}
const int Maxn=2e3+10,Maxk=1e6+10,mod=1000000007;
int fac[Maxk];
int f[Maxk];
inline int ksm(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=sum*x%mod;
		x=x*x%mod;
		y=y/2;
	}
	return sum;
}
int n,m,k;
inline void init(){
	n=read();
	m=read();
	k=read();
}
int sum[Maxk];
inline int C(int x,int y){
	return fac[x]*ksm(fac[y],mod-2)%mod*ksm(fac[x-y],mod-2)%mod;
}
inline void work(){
	if(m==1){
		writeln(ksm(k,n));
		return;
	}	
	fac[0]=1;
	fr(i,1,k) fac[i]=fac[i-1]*i%mod;
	f[1]=1;
	fr(i,2,min(n,k)) {
		f[i]=(ksm(i,n))%mod;
		fr(j,1,i-1) f[i]=(f[i]-C(i,j)*f[j]+mod)%mod;
	}
	fr(i,1,min(n,k)) sum[i]=(sum[i-1]+ksm(i,n*(m-2)))%mod;
//	fr(i,1,k) writepl(i),writeln(f[i]);
	int ans=0;
	fr(i,1,min(n,k)){
		int sum=0;
		fr(j,max(0ll,2*i-min(n,k)),i) sum=sum+ksm(j,n*(m-2))*C(k-i,i-j)%mod,sum%=mod;
		ans=(ans+f[i]*f[i]%mod*C(k,i)%mod*sum%mod)%mod;
	}
	writeln(ans);
}
signed main(){
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	init();
	work(); 
	return 0;
}

