#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')

using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=59;
int n,a[N],num[N*2],ans;
void dfs(int x,int cnt){
	if(x>n){
		ans=max(ans,cnt);
		return;
	}
	if(num[a[x]])num[a[x]]--,dfs(x+1,cnt),num[a[x]]++;
	if(num[a[x]+1])num[a[x]+1]--,dfs(x+1,cnt),num[a[x]+1]++;
	if(num[a[x]-1])num[a[x]-1]--,dfs(x+1,cnt),num[a[x]-1]++;
	if(!num[a[x]]&&!num[a[x]+1]&&!num[a[x]-1])dfs(x+1,cnt+1);
}
signed main(){
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	cout<<clock()<<endl;
	while(scanf("%d",&n)!=EOF){
		memset(num,0,sizeof(num));
		ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),num[a[i]]++;
		dfs(1,0);
		printen(ans);
	}
	cout<<clock()<<endl;
	return 0;
}
/*
3
1 2 3
8
1 2 3 3 4 2 5 4
*/
