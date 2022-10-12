#include<stdio.h>
#include<stdlib.h>
long i,j,tt,t,x,n;
long s[1001],leaf[1001],num[1001],tree[1001][1001],w[1001][1001];
void dfs(long x){
     long i;
     for (i=num[x];i>=1;i--){
         dfs(tree[x][i]);
         s[tree[x][i]]*=s[tree[x][i+1]]*w[leaf[tree[x][i+1]]][leaf[tree[x][i]]]%10007;
         s[tree[x][i]]%=10007;
         leaf[tree[x][i]]+=leaf[tree[x][i+1]];
         }
     s[x]=s[tree[x][1]];
     leaf[x]=leaf[tree[x][1]]+1;
     return;
}
int main(){
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    scanf("%ld",&t);
	for (i=1;i<=1000;++i)
		w[0][i]=1;
	for (i=1;i<=1000;++i)
		for (j=1;j<=1000;++j)
			w[i][j]=(w[i][j-1]+w[i-1][j])%10007;
    for (tt=1;tt<=t;tt++){
        scanf("%ld",&n);
        for (i=1;i<=n;i++)
            s[i]=leaf[i]=num[i]=0;
        for (i=1;i<=n;i++){
            scanf("%ld",&x);num[i]=x;tree[i][x+1]=0;
            for (j=1;j<=x;j++)
                scanf("%ld",&tree[i][j]);
            }
        s[0]=1;
        dfs(1);
        printf("%ld\n",s[1]);
        }
    return 0;
}
