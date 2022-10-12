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
const int Maxn=5e5+10,Maxm=310*310*2,inf=1e15;
struct node{
	int nxt,to;
	int flow,d;
	int cost,flag;
}e[Maxm];
int cnt=1,head[Maxn];
struct people{
	int val1,val2,val3;
	int id;
}p[Maxn],k[Maxn];
int tot=0;
inline void add(int u,int v,int z,int w){
//	cout<<u<<' '<<v<<' '<<z<<' '<<w<<endl;
	++cnt;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
	e[cnt].flow=e[cnt].d=z;
	e[cnt].cost=w;
}
int maxn=-inf;
inline bool cmp1(people a,people b){return a.val1>=b.val1;}
inline bool cmp2(people a,people b){return a.val2>=b.val2;}
inline bool cmp3(people a,people b){return a.val3>=b.val3;}
int n,A,B,C;
inline void init(){
	n=read(),A=read(),B=read(),C=read();
	fr(i,1,n) p[i].val1=read(),p[i].val2=read(),p[i].val3=read(),p[i].id=i;
}
int vis[Maxn];
int dis[Maxn];
int S,T,T1,T2,T3;
int now[Maxn];
struct ddd{
	int pos;
	int dis;
	bool operator < (const ddd &x) const {
		return dis<x.dis;
	}
};
inline bool bfs(){
	fr(i,1,tot+5) dis[i]=inf,vis[i]=0;
	fr(i,1,tot+5) now[i]=head[i];
	priority_queue<ddd> q;
	ddd tmp;
	tmp.pos=S,tmp.dis=0;
	q.push(tmp);
	dis[S]=0;
	vis[S]=1;
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		vis[tmp.pos]=0;
//		cout<<tmp.pos<<' '<<tmp.dis<<endl;
		for(register int i=now[tmp.pos];i;i=e[i].nxt){
			if(!e[i].flow) continue;
			int y=e[i].to;
			if(dis[y]>dis[tmp.pos]+e[i].cost){
				dis[y]=dis[tmp.pos]+e[i].cost;
				if(!vis[tmp.pos]){
					ddd ttmp;
					ttmp.dis=dis[y];
					ttmp.pos=y;
					q.push(ttmp);
					vis[tmp.pos]=1;
				}
				if(y==T) return true;
			}
		}
	}
	return dis[T]!=inf;
}
int answer;
inline int dfs(int x,int f){
//	cout<<x<<' '<<f<<endl;
	if(x==T) return f;
	if(!f) return 0;
	int ans=0;
	for(register int i=now[x];i;i=e[i].nxt){
		int y;
		y=e[i].to;
		now[x]=i;
		if(!(dis[y]==dis[x]+e[i].cost)) continue;
		if(!e[i].flow) continue;
		int k=min(f,e[i].flow);
		int now=dfs(y,k);
		ans+=now;
//		cout<<y<<' '<<k<<' '<<now<<endl;
//		printf("answer:%lld %lld\n",now,e[i].cost);
		answer+=now*e[i].cost;
		f-=now;
		e[i].flow-=now;
		e[i^1].flow+=now;
	}
	return ans;
}
inline void work(){
	if(A+B+C>n){
		puts("I am a godlike cowcowcow");
		return;
	}
	sort(p+1,p+n+1,cmp1);
	int lst=p[A+B+C].val1;
	fr(i,1,n){
		if(p[i].val1<lst) break;
		if(vis[p[i].id]) continue;
		vis[p[i].id]=1;
		k[++tot]=p[i];
	}
	sort(p+1,p+n+1,cmp2);
	lst=p[A+B+C].val2;
	fr(i,1,n){
		if(p[i].val2<lst) break;
		if(vis[p[i].id]) continue;
		vis[p[i].id]=1;
		k[++tot]=p[i];
	}
	sort(p+1,p+n+1,cmp3);
	lst=p[A+B+C].val3;
	fr(i,1,n){
		if(p[i].val3<lst) break;
		if(vis[p[i].id]) continue;
		vis[p[i].id]=1;
		k[++tot]=p[i];
	}
	S=tot+1,T1=tot+2,T2=tot+3,T3=tot+4,T=tot+5;
	int maxn=-inf;
	fr(i,1,tot) maxn=max(maxn,max(max(k[i].val1,k[i].val2),k[i].val3)); 
	fr(i,1,tot){
		add(S,i,1,0),add(i,S,0,0);
		add(i,T1,1,-k[i].val1),add(T1,i,0,k[i].val1);
		add(i,T2,1,-k[i].val2),add(T2,i,0,k[i].val2);
		add(i,T3,1,-k[i].val3),add(T3,i,0,k[i].val3);
	}
	add(T1,T,A,0),add(T,T1,0,0);
	add(T2,T,B,0),add(T,T2,0,0);
	add(T3,T,C,0),add(T,T3,0,0);
	int ans=0;
//	bfs();
//	fr(i,1,tot+5){
//		cout<<i<<": ";
//		for(register int j=now[i];j;j=e[j].nxt){
//			writepl(e[j].to);
//		}
//		puts("");
//	}
	while(bfs()){
//		fr(i,1,tot+5)
//		fr(i,1,tot+5) printf("dis: "),writepl(i),writeln(dis[i]);
//		puts("");
		ans+=dfs(S,inf);
	}
	writeln(-answer);
	int ans1=0;
	fr(i,1,tot+5){
		for(register int j=now[i];j;j=e[j].nxt){
			if(e[j].flow==0) ans1+=e[j].cost*e[j].d;
//			writepl(i),writepl(e[j].to),writepl(e[j].flow),writeln(e[j].cost);
		}
	}
	writeln(-ans1);
}
signed main(){
	freopen("ゆりっぺ.in","r",stdin);
	freopen("ゆりっぺ.out","w",stdout);
	init();
	work(); 
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
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
//const int Maxn=5e5+10,Maxm=310*310*2,inf=1e15;
//int dp[2][310][310][310];
//int n;
//struct people{
//	int val1,val2,val3;
//	int id;
//}p[Maxn],k[Maxn];
//int tot=0;
//inline bool cmp1(people a,people b){return a.val1>=b.val1;}
//inline bool cmp2(people a,people b){return a.val2>=b.val2;}
//inline bool cmp3(people a,people b){return a.val3>=b.val3;}
//int n,A,B,C;
//inline void init(){
//	n=read(),A=read(),B=read(),C=read();
//	fr(i,1,n) p[i].val1=read(),p[i].val2=read(),p[i].val3=read(),p[i].id=i;
//	if(A+B+C>n){
//		puts("I am a godlike cowcowcow");
//		return;
//	}
//	sort(p+1,p+n+1,cmp1);
//	int lst=p[A+B+C].val1;
//	fr(i,1,n){
//		if(p[i].val1<lst) break;
//		if(vis[p[i].id]) continue;
//		vis[p[i].id]=1;
//		k[++tot]=p[i];
//	}
//	sort(p+1,p+n+1,cmp2);
//	lst=p[A+B+C].val2;
//	fr(i,1,n){
//		if(p[i].val2<lst) break;
//		if(vis[p[i].id]) continue;
//		vis[p[i].id]=1;
//		k[++tot]=p[i];
//	}
//	sort(p+1,p+n+1,cmp3);
//	lst=p[A+B+C].val3;
//	fr(i,1,n){
//		if(p[i].val3<lst) break;
//		if(vis[p[i].id]) continue;
//		vis[p[i].id]=1;
//		k[++tot]=p[i];
//	}
//}
//
//inline void work(){
//	fr(i,1,n){
//		now=now^1;
//		for(register int j1=0;j1<=A && j1<=i;++j1)
//		for(register int j2=0;j2<=B && j1+j2<=i;++j2)
//		for(register int j3=0;j3<=C && j1+j2+j3<=i;++j3){
//			
//		}
//	}
//}
//signed main(){
////	freopen("ゆりっぺ.in","r",stdin);
////	freopen("ゆりっぺ.out","w",stdout);
//	init();
//	work();
//    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
//	return 0;
//}

