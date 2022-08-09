#include<bits/stdc++.h>
#define printen(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
#define int long long
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}while(isdigit(c)){x=x*10+c-'0';c=getchar();}return x*f;}
inline void print(int x){if(x<0)putchar('-'),x=-x;if(x>9)print(x/10);putchar(x%10+'0');}
int n,m,K,ans,a[1009][1009];
void dfs(int x,int y,int cnt){
	if(x==n&&y==m){if(cnt==K)ans++;return;}
	if(y!=m&&a[x][y+1]!=0)dfs(x,y+1,cnt^a[x][y+1]);if(x!=n&&a[x+1][y]!=0)dfs(x+1,y,cnt^a[x+1][y]);
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	dfs(1,1,a[1][1]);print(ans);
	return 0;
}
