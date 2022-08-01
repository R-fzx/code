#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0)x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=2e5+9;
int n,m,ans,maxin,f[N],in[N];
vector<int>e[N];
void dfs(int x){
	if(e[x].size()==0){
		ans++;
		return;
	}
	for(int i=0;i<e[x].size();i++)dfs(e[x][i]);
	return;
}
int main(){
	freopen("lyx.in","r",stdin);
	freopen("lyx.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		e[x].push_back(y);
		in[y]++;
	}
	for(int i=1;i<=n;i++)if(in[i]==0)dfs(i);
	print(ans);
	return 0;
}
