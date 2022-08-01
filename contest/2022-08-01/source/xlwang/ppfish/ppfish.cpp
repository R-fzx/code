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
const int Maxn=2e3+10,Maxl=1e6+10,base1=101,base2=103,mod=998244353;
map<pair<int,int> ,int> mp;
map<int,int> mp1;
char c[Maxn][30];
char s[Maxl];
int n;
inline int getsum(char c){
    return c-'a'+1;
}
inline void init(){
    n=read();
    fr(i,1,n) scanf("%s",c[i]+1);
    int maxn=0;
    fr(i,1,n) maxn=max(1ull*maxn,strlen(c[i]+1));
    scanf("%s",s+1);
    // writeln(maxn);
    int ln=strlen(s+1);
    fr(i,1,ln){
        int sum1=0;
        int tot=0;
        int k=i-1;
        int sum2=0;
        while(tot<maxn){
            ++k;
            if(k>ln) break;
            ++tot;
            sum1=sum1*base1%mod+getsum(s[k]);
            sum1%=mod;
            sum2=sum2*base2%mod+getsum(s[k]);
            sum2%=mod;
            mp[make_pair(sum1,sum2)]++;
        }
    }
    return;
}
int num[Maxn];
double ans[Maxn][Maxn];
int num1[Maxn];
inline void work(){
    fr(i,1,n){
        int now1=0,now2=0;
        for(register int j=1;j<=strlen(c[i]+1);++j){
            now1=now1*base1%mod+getsum(c[i][j]);
            now2=now2*base2%mod+getsum(c[i][j]);
        }
        num[i]=mp[make_pair(now1,now2)];
        // int num;
        // num=mp[make_pair(now1,now2)];
        // writepl(i);writeln(num);
    }
    double p;
    int k;
    cin>>p;
    k=read();
    // k=2;
    fr(i,1,n) num1[i]=num[i];
    sort(num1+1,num1+n+1);
    int Num=0;
    fr(i,1,n) if(!mp1[num1[i]]) mp1[num1[i]]=++Num;
    ans[1][1]=1-p;
    // fr(i,1,n) writepl(mp1[num[i]]);
    fr(i,1,k) ans[0][i]=1;
    // puts("");
    fr(j,2,k) fr(i,1,n) ans[i][j]=(p)*ans[i][j-1]+(1-p)*ans[i-1][j-1]; 
    // cout<<ans[0][1]<<endl;
    fr(i,1,n) printf("%.3lf ",1.0-ans[mp1[num[i]]][k]);  
    return;
}
signed main(){
    freopen("ppfish.in","r",stdin);
    freopen("ppfish.out","w",stdout);
    init();
    work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
