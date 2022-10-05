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
//#define double long double 
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int M=2e4+100,N=2505,K=55;
int h[N],nex[M],to[M],e[M],bj[M],tot;
int d1[5]={0,1,1,-1,-1},d2[5]={0,-1,1,1,-1},d3[5]={0,0,0,1,-1},d4[5]={0,1,-1,0,0};
int s[K][K],cnt;
int a[K][K];
char c[K];
string cc;
int dis[N];
bool vis[N];
int n;
int t[N],tt,st,ans=-1;
void add(int x,int y,int z,int b){to[++tot]=y;e[tot]=z;bj[tot]=b;nex[tot]=h[x];h[x]=tot;}
void cg(int k){
	for(int i=1;i<=tot;i++)if(bj[i]==k)e[i]=3;
}
void fc(int k){
	for(int i=1;i<=tot;i++)if(bj[i]==k)e[i]=1;
}
void dij(){
	memset(dis,0x3f,sizeof(dis));dis[st]=0;
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,st));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=nex[i]){
			int v=to[i],w=e[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
void work(){
	int mi=0x3f3f3f3f;
	for(int i=1;i<=tt;i++)mi=min(mi,dis[t[i]]);
	if(mi!=0x3f3f3f3f)ans=max(ans,mi);
}
signed main(){
	freopen("desert.in","r",stdin);
	freopen("desert.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		getline(cin,cc);cc=' '+cc;
		for(int k=1,j=1;j<=n;){
			if(cc[k]==' ')k++;
			else c[j]=cc[k],j++,k++;
		}
		for(int j=1;j<=n;j++){
			s[i][j]=++cnt;
			if(c[j]=='-')a[i][j]=1;
			if(c[j]=='X')a[i][j]=2;
			if(c[j]=='*')a[i][j]=1,t[++tt]=cnt;
			if(c[j]=='@')a[i][j]=1,st=cnt;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(a[i][j]!=1)continue;
			for(int k=1;k<=4;k++)
				if(a[i+d1[k]][j+d2[k]]==1)add(s[i][j],s[i+d1[k]][j+d2[k]],1,k);
			for(int k=1;k<=4;k++)
				if(a[i+d3[k]][j+d4[k]]==1)add(s[i][j],s[i+d3[k]][j+d4[k]],1,k+4);
		}
	for(int i=1;i<=8;i++){
		cg(i);
		dij();
		work();
		fc(i);
	}
	printf("%d",ans);
	return 0;
}
/*
3
- - *
@ X -
- X -
*/
