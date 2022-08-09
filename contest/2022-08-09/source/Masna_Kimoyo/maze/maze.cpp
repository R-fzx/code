#include<bits/stdc++.h>
#define printlf(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
using namespace std;
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
const int N=22,A=1e4+5;
int dp[N][N][A],a[N][N];
int n,m,X,ans;
inline void dfs(int x,int y,int val){
	val^=a[x][y];
	if(x==n && y==n){
		if(val==X)	++ans;
		return ;
	}
	if(x<n)	dfs(x+1,y,val);
	if(y<n)	dfs(x,y+1,val);
}
inline void Sub1(){
	dfs(1,1,0);
	print(ans);
	exit(0);
}
inline void Sub2(){
	dp[1][1][a[1][1]]=1;
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=n;++j){
			for(register int k=0;k<=10000;++k){
				dp[i][j][k]+=dp[i][j-1][k^a[i][j]];
				dp[i][j][k]+=dp[i-1][j][k^a[i][j]];
			}
		}
	}
	print(dp[n][m][X]);
}
signed main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),X=read();
	for(register int i=1;i<=n;++i)	
		for(register int j=1;j<=m;++j)
			a[i][j]=read();
	if(n<=10 && m<=10)	Sub1();
	Sub2();
    return 0;
}


