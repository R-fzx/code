//#define fastcall __attribute__((optimize("-O3")))
//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse")
//#pragma GCC optimize("-fgcse-lm")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-ftree-pre")
//#pragma GCC optimize("-ftree-vrp")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-falign-jumps")
//#pragma GCC optimize("-falign-loops")
//#pragma GCC optimize("-falign-labels")
//#pragma GCC optimize("-fdevirtualize")
//#pragma GCC optimize("-fcaller-saves")
//#pragma GCC optimize("-fcrossjumping")
//#pragma GCC optimize("-fthread-jumps")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-fwhole-program")
//#pragma GCC optimize("-freorder-blocks")
//#pragma GCC optimize("-fschedule-insns")
//#pragma GCC optimize("inline-functions")
//#pragma GCC optimize("-ftree-tail-merge")
//#pragma GCC optimize("-fschedule-insns2")
//#pragma GCC optimize("-fstrict-aliasing")
//#pragma GCC optimize("-fstrict-overflow")
//#pragma GCC optimize("-falign-functions")
//#pragma GCC optimize("-fcse-skip-blocks")
//#pragma GCC optimize("-fcse-follow-jumps")
//#pragma GCC optimize("-fsched-interblock")
//#pragma GCC optimize("-fpartial-inlining")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("-freorder-functions")
//#pragma GCC optimize("-findirect-inlining")
//#pragma GCC optimize("-fhoist-adjacent-loads")
//#pragma GCC optimize("-frerun-cse-after-loop")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-ftree-switch-conversion")
//#pragma GCC optimize("-foptimize-sibling-calls")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#include<bits/stdc++.h>
//#define int long long
//#define fr(i,j,k) for(register int i=j;i<=k;++i)
//#define rf(i,j,k) for(register int i=j;i>=k;--i)
//#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
//#define randfind(l,r) (rand()%((r)-(l)+1)+(l))
//#define pb push_back
//#define Times printf("Time:%.3lf\n",clock()/CLOCKS_PER_SEC)
//using namespace std;
//inline int read(){
//	int x=0;
//	bool f=0;
//	char c=getchar();
//	while(!isdigit(c)) f|=(c=='-'),c=getchar();
//	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
//	return f?-x:x;
//}
//inline void write(int x){
//    if(x<0){putchar('-');x=-x;}
//    if(x>9)write(x/10);
//    putchar(x%10+'0');
//}
//inline void writeln(int x){write(x); puts("");}
//inline void writepl(int x){write(x); putchar(' ');}
//const int Maxn=110,inf=1e8;
//int a[Maxn];
//int n;
//int num[Maxn];
//int dp[Maxn][Maxn];
//inline void work(){
//	fr(i,1,101) fr(j,1,101) dp[i][j]=-inf;
//	memset(num,0,sizeof(num));
//	fr(i,1,n) a[i]=read(),num[a[i]]++;
//	int ans=0;
//	dp[0][0]=0;
//	fr(i,1,101) fr(k,0,num[i]){
//		if(k<2) dp[i][k]=max(dp[i][k],dp[i-1][0]);
//		if((num[i]-k)%2==0 && num[i]%2==0){
//			fr(l,0,num[i-1]){
//				if(l%2==0) dp[i][0]=max(dp[i][0],dp[i-1][l]);
//				else dp[i][0]=max(dp[i-1][0],dp[i-1][l]+1);
//			}
//		}
//		if((num[i]-k)%2==0 && num[i]%2==1){
//			fr(l,0,num[i-1]){
//				if(l%2==0) dp[i][0]=max(dp[i][0],dp[i-1][l]);
//			}
//		}
//		fr(l,1,num[i-1]){
//			writepl(i);
//			writepl(num[i]);
//			writepl(k);
//			writeln(l);
//			if(((num[i]-k)%2)!=(l%2) && num[i]-k!=0) dp[i][k]=max(dp[i][k],dp[i-1][l]+1ll);
//			if(((num[i]-k)%2)==(l%2)) dp[i][k]=max(dp[i][k],dp[i-1][l]);
//		}
//	}
//	fr(i,1,5){
//		fr(j,0,num[i]) printf("dp[%lld][%lld]=%lld\n",i,j,dp[i][j]);
//	}
//	writeln(dp[101][0]);
//}
//inline void init(){
//	while(cin>>n) work();
//}
//signed main(){
//	freopen("puppet.in","r",stdin);
//	freopen("puppet.out","w",stdout);
//	init();
//    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
//	return 0;
//}
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
const int Maxn=1e2+10;
int a[Maxn];
int n;
int num[Maxn];
int vis[Maxn];
int cnt;
int ans;
int to[Maxn];
inline void check(){
	int sum=0;
	int now=0;
//	fr(i,1,10) writepl(i),writeln(num[i]);
	fr(i,1,100){
		if(!num[i]){
			if(now%3==0 || now%3==2) sum+=now/3;
			else sum+=now/3+1;
			now=0;
		}
		else{
			++now;
		}
	}
//	writeln(sum);
	ans=max(ans,sum);
}
inline void dfs(int x){
	if(x==(cnt+1)){
		check();
		return;
	}
	if(num[to[x]]<2){
		dfs(x+1);
		return;
	}
	if(num[to[x]]==3){
		if(num[to[x]-1] && num[to[x]+1]){
			--num[to[x]-1];
			--num[to[x]+1];
			--num[to[x]],--num[to[x]];
			dfs(x+1);
			++num[to[x]-1];
			++num[to[x]+1];
			++num[to[x]],++num[to[x]];
		}
		--num[to[x]],--num[to[x]];
		dfs(x+1);
		++num[to[x]],++num[to[x]];
		return;
	}
	if(num[to[x]-1] && num[to[x]+1]){
		--num[to[x]-1];
		--num[to[x]+1];
		--num[to[x]],--num[to[x]];
		dfs(x+1);
		++num[to[x]-1];
		++num[to[x]+1];
		++num[to[x]],++num[to[x]];
	}
	if(num[to[x]-1]){
		--num[to[x]-1];
		--num[to[x]];
		dfs(x+1);
		++num[to[x]-1];
		++num[to[x]];
	}
	if(num[to[x]+1]){
		--num[to[x]+1];
		--num[to[x]];
		dfs(x+1);
		++num[to[x]+1];
		++num[to[x]];
	}
	--num[to[x]],--num[to[x]];
	dfs(x+1);
	++num[to[x]],++num[to[x]];
}
int A[Maxn];
int N;
int VIS[Maxn];
int NUM[Maxn];
inline void Check(){
	int CNT=0;
	fr(i,1,N) if(!VIS[i]) NUM[++CNT]=A[i];
	sort(NUM+1,NUM+CNT+1);
//	writeln(CNT);
//	fr(i,1,CNT) writepl(NUM[i]);
//	puts("");
	if(CNT&1) return;
	for(register int i=2;i<=CNT;i+=2) if(NUM[i]-NUM[i-1]>1) return;
//	cout<<"**"<<endl;
	CNT=0;
	fr(i,1,N) if(VIS[i]) NUM[++CNT]=A[i];
	sort(NUM+1,NUM+CNT+1);
//	writeln(CNT);
//	fr(i,1,CNT) writepl(NUM[i]);
//	puts("");
	for(register int i=2;i<=CNT;i++) if(NUM[i]-NUM[i-1]<=1) return;
//	writeln(CNT);
//	fr(i,1,CNT) writepl(NUM[i]);
//	puts("");
	ans=max(ans,CNT);
}
inline void DFS(int x){
	if(x==(N+1)){
		Check();
		return;
	}
	VIS[x]=1;
	DFS(x+1);
	VIS[x]=0;
	DFS(x+1);
}
inline void work1(){
//	cout<<"**"<<endl;
	ans=0;
	N=0;
	fr(i,1,100) fr(j,1,num[i]) A[++N]=i;
//	fr(i,1,N) writepl(A[i]);
//	puts("");
	DFS(1);
	writeln(ans);
}
inline void work(){
	fr(i,1,n) a[i]=read();
	memset(num,0,sizeof(num));
//	writeln(n);
//	fr(i,1,n) writepl(a[i]);
//	puts("");
	fr(i,1,n) {
		++num[a[i]];
		if(num[a[i]]>3) num[a[i]]-=2;
	}
	cnt=0;
	fr(i,1,100) if(num[i-1]==0 && num[i+1]==0 && num[i]==2) num[i]=0;
	fr(i,1,100) if(num[i]>2) ++cnt,to[cnt]=i;
	int Cnt=0;
	fr(i,1,100) Cnt+=num[i];
	if(Cnt<=20){
		work1();
		return;
	}
	ans=0;
	dfs(1);
	writeln(ans);
//	fr(i,1,10) writepl(i),writeln(num[i]);
//	int ans=0,now=0;
//	int lst=0;
//	fr(i,1,100){
////		writepl(i),writepl(now),writepl(lst),writeln(ans);
//		if(num[i]==0){
//			if(now&1) ++ans;
//			now=lst=0;
//		}
//		if(num[i]==1){
//			if(!lst) now=1,lst=i;
//			else if(i-lst>1){
//				++ans;
//				now=1;
//				lst=i;
//			}
//			else {
//				++now;
//				lst=i;
//			}
//		}
//		if(num[i]==2){
//			if(now==0 && num[i+1]==1){
//				++ans;
//				--num[i+1];
//				continue;
//			}
//			if(now==0) continue;
//			if(now&1){
//				++ans;
//				lst=now=0;
//			}
//			else {
//				lst=i;
//				now=1;
//				++ans;
//			}
//		}
//		if(now==3){
//			now=0;
//			++ans;
//			lst=0;
//		}
//	}
//	if(now&1)++ans;
//	writeln(ans);
}

inline void init(){
	while(cin>>n) work();
}

signed main(){
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	init();
//     printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

