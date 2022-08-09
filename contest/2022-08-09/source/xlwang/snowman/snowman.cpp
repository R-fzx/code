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
#define int __int128
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
const int Maxn=5e5+10,mod1=9973,mod2=1e9+7;
int kmp[Maxn];
int n;
int a[Maxn];
int d[Maxn];
inline void init(){
    n=read();
    fr(i,1,n) a[i]=read();
    a[0]=1e8+10;
    fr(i,1,n) d[i]=a[i]-a[i-1];
    fr(i,1,n) d[i]+=1000000010;
}
int hsh[Maxn];
int invhash[Maxn],fac[Maxn];
inline int ksm(int x,int y){
    int sum=1;
    while(y){
        if(y&1) sum=sum*x%mod2;
        x=x*x%mod2;
        y=y/2;
    }
    return sum;
}
map<int,int> mp;
inline int check(int x){
    // mp.clear();
    vector<int> vc;
    int flag=0;
    fr(i,1,n){
        int j=i+x-1;
        int now;
        if(j>n) break;
        now=hsh[j]-fac[x]*hsh[i-1]%mod2+mod2;
        while(now<0) now+=mod2;
        now%=mod2;
        int pop=mp[now];
        if(!pop){
            mp[now]=i;
            vc.push_back(now);
            continue;
        }
        if(i>(pop+x-1)){
            // cout<<pop<<' '<<i<<' '<<j<<endl;
            flag=1;
            break;
        }
    }
    for(register int i=0;i<vc.size();++i) mp[vc[i]]=0;
    return flag;
}
inline void work(){
    int l=1,r=n;
    int ans=0;
    fac[0]=1;
    fr(i,1,n) fac[i]=fac[i-1]*mod1%mod2;
    fr(i,1,n) hsh[i]=hsh[i-1]*mod1%mod2+d[i],hsh[i]%=mod2,invhash[i]=ksm(hsh[i],mod2-2);
    // cout<<"**"<<endl;
    while(l<=r){
        int mid;
        mid=(l+r)>>1;
        // cout<<l<<' '<<r<<endl;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    ++ans;
    // int now;
    // now=hsh[21676-1+ans-1]-hsh[21676-1]*fac[ans-1]%mod2+mod2;
    // now%=mod2;
    // fr(i,21676-1,21676-1+ans-1) writepl(a[i]);
    // // writeln(now);
    // puts("");
    // // now=hsh[51984-1+ans-1]-hsh[51984-1]*fac[ans-1]%mod2+mod2;
    // // now%=mod2;
    // // writeln(now);
    // puts("");
    // fr(i,51984-1,51984-1+ans-1) writepl(a[i]);
    writeln(ans);
}
signed main(){
    freopen("snowman.in","r",stdin);
    freopen("snowman.out","w",stdout);
    init();
    work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
