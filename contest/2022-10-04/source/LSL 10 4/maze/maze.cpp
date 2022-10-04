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
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
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
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
//#define int long long
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int M=8e4+100,N=1e4+100,K=105;
string c;
int a[K][K],s[K][K],cnt;
double L;
int h[N],nex[M],to[M],tot;
double dis[N],e[M];
bool vis[N],bj[M];
int T,n,st,t,m;
void add(int x,int y,double z,bool b){to[++tot]=y;e[tot]=z;bj[tot]=b;nex[tot]=h[x];h[x]=tot;}
void ch(double d){
	for(int i=1;i<=tot;i++)
	if(bj[i]==1)e[i]=d;
}
void dij(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n*m;i++)dis[i]=0x3f3f3f3f;
	dis[st]=0;
	priority_queue<pair<double,int> >q;
	q.push(make_pair(0,st));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nex[i]){
			int v=to[i];
			if(dis[v]>dis[u]+e[i]){
				dis[v]=dis[u]+e[i];
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	T=read();
	while(T--){
		memset(h,0,sizeof(h));memset(s,0,sizeof(s));tot=0,cnt=0;memset(a,0,sizeof(a));memset(bj,0,sizeof(bj));
		scanf("%lf",&L);n=read(),m=read();
		for(int i=1;i<=n;i++){
			getline(cin,c);c=' '+c;
			for(int j=1;j<=m;j++){
				s[i][j]=++cnt;
				if(c[j]=='#')a[i][j]=1;
				if(c[j]=='S')st=cnt;
				if(c[j]=='E')t=cnt;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(a[i][j]==0){
					if(a[i+1][j]==0){
						add(s[i][j],s[i+1][j],1,1);
						add(s[i+1][j],s[i][j],1,1);
					}
					if(a[i-1][j]==0){
						add(s[i][j],s[i-1][j],1,1);
						add(s[i-1][j],s[i][j],1,1);
					}
					if(a[i][j+1]==0){
						add(s[i][j],s[i][j+1],1,0);
						add(s[i][j+1],s[i][j],1,0);
					}
					if(a[i][j-1]==0){
						add(s[i][j],s[i][j-1],1,0);
						add(s[i][j-1],s[i][j],1,0);
					}
				}
			}
		double l=0,r=10;
		while(r-l>1e-6){
			double mid=(l+r)/2;
			ch(mid);
			dij();
			if(L<dis[t])r=mid;
			else l=mid;
		}
		printf("%0.5lf\n",l);
	}
	return 0;
}
/*
-1
2.5 4 5
#####
#S  #
#  E#
#####
21 13 12
############
#S##     #E#
# ##  #  # #
#   # #  # #
### # #  # #
#   # #  # #
#  ## #  # #
##  # #  # #
### # #  # #
##  # #  # #
#  ## #    #
#     #    #
############
*/
