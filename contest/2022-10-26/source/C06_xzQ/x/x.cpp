#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),puts("")
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=1e5+9;
int n,b=1,ans,a[N],x[N],y[N],e[1009][1009];
map<long long,int>vis;
bool check(int x){
	for(int i=1;i<=x;i++)
		for(int j=i+1;j<=x;j++)
			if(!e[a[i]][a[j]])return 0;
	return 1;
}
void dfs(int x,int cnt){
	if(check(cnt))ans=max(ans,cnt);
	else return;
	for(int i=x+1;i<=n;i++){
		a[cnt+1]=i;
		dfs(i,cnt+1);
		a[cnt+1]=0;
	}
}
signed main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read(),y[i]=read();
		if(y[i]!=0)b=0;
		if(!vis[x[i]])ans++,vis[x[i]]++;
	}
	if(b)return print(ans),0;
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(abs(x[i]-x[j])>abs(y[i]+y[j]))e[i][j]=e[j][i]=1;
	dfs(0,0);
	print(ans);
	return 0;
}
/*
4
2 3
3 1
6 1
0 2
*/
