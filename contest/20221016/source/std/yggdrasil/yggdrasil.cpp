#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define F(i,a,b) for(register int i=(a);i<=(b);i++)
#define E(i,u) for(register int i=head[u];i;i=nxt[i])
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),p1==p2?EOF:*p1++)
using namespace std;
typedef long long LL;

char buf[1<<20],*p1,*p2;
inline int read() {
    int x=0,f=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-')f=-f;c=getchar();}
    while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
    return x*f;
}

const int N=700010;
int n,cnt,root;
int da[N],nxt[N<<1],to[N<<1],cost[N<<1],head[N],siz[N];
LL sum,ans;
LL f[N];

void dfs1(int u,int pre) {
    siz[u]=1;
    E(i,u) {
        int v=to[i];if(v==pre) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        f[1]+=(LL)max((LL)cost[i]-da[u],0ll)*(LL)siz[v];//1
    }
}

void dfs2(int u,int pre) {
    E(i,u) {
        int v=to[i];if(v==pre) continue;
        f[v]=f[u]-(cost[i]-da[u])*siz[v]+(cost[i]-da[v])*(n-siz[v]);
        if(f[v]<=f[root]) root=f[v]<f[root]?v:min(root,v);
        dfs2(v,u);
    }
}

#define add(a,b,c) nxt[++cnt]=head[a],to[cnt]=b,cost[cnt]=c,head[a]=cnt
int main() {
    freopen("yggdrasil.in","r",stdin);
    freopen("yggdrasil.out","w",stdout);
    
    n=read();
    F(i,1,n) da[i]=read();
    F(i,1,n-1) {
        int u=read(),v=read(),w=read();
        add(u,v,w);add(v,u,w);
    }
    dfs1(1,0);
    root=1;
    dfs2(1,0);
    printf("%d\n%lld",root,f[root]);
    return 0;
}
