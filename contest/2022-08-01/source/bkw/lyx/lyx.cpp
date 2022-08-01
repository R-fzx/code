#include<bits/stdc++.h>
#define printlf(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
using namespace std;
const int N=1e5+5,M=2e5+5;
struct node{
	int nxt,to;
}Edge[M];
int n,tot,m,ans;
int head[N],f[N],in[N],out[N];
inline int read(){
    int x=0;
    bool w=0;
    char c=getchar();
    while(!isdigit(c))  w|=c=='-',c=getchar();
    while(isdigit(c))   x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void print(int x){
    if(x<0) x=-x,putchar('-');
    if(x>9) print(x/10);
    putchar('0'+x%10);
}
inline void add(int u,int v){
	Edge[++tot].to=v;
	Edge[tot].nxt=head[u];
	head[u]=tot;
}
inline int dfs(int x){
	for(register int i=head[x];i;i=Edge[i].nxt){
		int v=Edge[i].to;
		if(f[v]==0)	dfs(v);
		f[x]+=f[v];
	}
}
signed main(){
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=m;++i){
		int u=read(),v=read();
		add(v,u);
		in[u]++,out[v]++;
	}
	for(register int i=1;i<=n;++i)
		if(out[i]==0)	f[i]=1;
	for(register int i=1;i<=n;++i)
		if(in[i]==0)	dfs(i),ans+=f[i];
	print(ans);
    return 0;
}

