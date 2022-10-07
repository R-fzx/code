#include<cstdio>
int K,M,ans[2050],vis[2050];
int dfs(int S,int x){if(vis[S])return 0;vis[S]=1;ans[x]=S&1;if(x==M)return 1;if(dfs(S<<1&(M-1),x+1)||dfs((S<<1|1)&(M-1),x+1))return 1;return vis[S]=0;}
int main(){freopen("taiko.in","r",stdin);freopen("taiko.out","w",stdout);scanf("%d",&K);M=1<<K;printf("%d ",M);dfs(M-2,1);for(int i=1;i<=M;++i)printf("%d",ans[i]);return!printf("\n");}
