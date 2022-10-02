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
const int Maxn=2e3+10;
struct node{
	int a[1010];
	int ln;
	node(){
		ln=1;
		memset(a,0,sizeof(a));
	}
};
void print(node &x){
	rf(i,x.ln,1) write(x.a[i]);
	puts("");
}
node operator +(node x,node y){
	node sum;
	sum.ln=max(x.ln,y.ln);
	fr(i,1,sum.ln){
		sum.a[i]+=x.a[i]+y.a[i];
		sum.a[i+1]+=sum.a[i]/10;
		sum.a[i]%=10;
	}
	while(sum.a[sum.ln+1]) sum.ln++,sum.a[sum.ln+1]+=sum.a[sum.ln]/10,sum.a[sum.ln]%=10;
	return sum;
}
node operator *(node x,node y){
	node sum;
	fr(i,1,x.ln) fr(j,1,y.ln) sum.a[i+j-1]+=x.a[i]*y.a[j],sum.a[i+j]+=sum.a[i+j-1]/10,sum.a[i+j-1]%=10;
	sum.ln=x.ln+y.ln-1;
	fr(i,1,sum.ln){
		sum.a[i+1]+=sum.a[i]/10;
		sum.a[i]%=10;
	}
	while(sum.a[sum.ln+1]) sum.ln++,sum.a[sum.ln+1]+=sum.a[sum.ln]/10,sum.a[sum.ln]%=10;
	return sum;
}
node operator -(node x,node y){
	node sum;
	sum.ln=x.ln;
	fr(i,1,x.ln){
		if(x.a[i]<y.a[i]) x.a[i]=x.a[i]+10,x.a[i+1]-=1;
		sum.a[i]=x.a[i]-y.a[i];
	}
	while(sum.ln>1 && sum.a[sum.ln]==0) --sum.ln;
	return sum;
}
node base;
node Base[10];
bool operator < (node x,node y){
	if(x.ln<y.ln) return true;
	if(x.ln>y.ln) return false;
	rf(i,x.ln,1) {
		if(x.a[i]==y.a[i]) continue;
		if(x.a[i]>y.a[i]) return false;
		return true;
	}
	return false;
}
node operator /(node x,node y){
	node sum,now;
	int pop=x.ln;
	while(pop){
		if(!(now.ln==1 && now.a[1]==0))now=now*base;
		now=now+Base[x.a[pop]];
//		print(now);
		--pop;
		int ans=0;
		fr(i,1,10) {
			node tmp;
			tmp=y*Base[i];
//			writepl(i);
//			print(tmp);
			if(now<tmp){
				ans=i-1;
				break;
			}
		}
//		writeln(ans);
		if(!(sum.ln==1 && sum.a[1]==0))sum=sum*base;
		if(ans!=0) sum=sum+Base[ans];
//		print(sum);
		if(ans!=0){
			node tmp;
			tmp=y*Base[ans];
			now=now-tmp;
		}
	}
	return sum;
}
inline void init(){
	base.ln=2;
	base.a[2]=1;
	fr(i,0,9) Base[i].a[1]=i;
}
int qsum[Maxn];
int n;
int h[Maxn];
node fac[110];
node to[110];
inline node C(int x,int y){
	if(x<y){
		node tmp;
		tmp.ln=1;
		tmp.a[1]=0;
		return tmp;
	}
	node tmp;
	tmp=fac[x]/fac[x-y];
	return tmp;
}
inline void work(){
//	print(base);
//	node x,y;
//	node z;
//	x.ln=3;
//	x.a[3]=2;
//	x.a[2]=1;
//	x.a[1]=7;
//	y.ln=1;
//	y.a[1]=5;
//	z=x/y;
//	print(x);
//	print(y);
////	writepl(z);
//	print(z);
	node now;
	now.ln=1;
	now.a[1]=0;
	fac[0].ln=1;
	fac[0].a[1]=1;
	fr(i,1,70) {
		now=now+Base[1];
		fac[i]=fac[i-1]*now;
		to[i]=now;
	}
//	print(fac[70]);
	n=read();
	fr(i,1,n) h[i]=read();
	fr(i,1,n) ++qsum[h[i]];
	fr(i,1,1000) qsum[i]+=qsum[i-1];
//	writeln(qsum[37]);
	node ans;
	node tmp;
	fr(i,1,n){
		fr(j,1,n){
			fr(k,1,min(j,qsum[h[i]])){
//				cout<<i<<' '<<j<<' '<<k<<endl;
//				print(ans);
				if(k==j){
//					cout<<n-k<<' '<<qsum[h[i]]-1<<' '<<k-1<<endl;
					tmp=fac[n-k];
//					print(tmp);
					tmp=fac[n-k]*C(qsum[h[i]]-1,k-1)*to[k];
//					print(tmp);
					ans=ans+tmp;
				}
				else {
					tmp=fac[n-k-1]*C(qsum[h[i]]-1,k-1)*to[(n-qsum[h[i]])]*to[k];
//					print(tmp);
					ans=ans+tmp;
				}
			}
		}
	}
//	print(ans);
	node To;
	fr(i,1,1000) To=To+Base[1];
	ans=ans*To;
	ans=ans/fac[n];
//	print(ans);
	rf(i,ans.ln,4) write(ans.a[i]);
	putchar('.');
	if(ans.a[1]>=5) ans.a[2]++;
	rf(i,3,2) write(ans.a[i]);
}
signed main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	init();
	work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

