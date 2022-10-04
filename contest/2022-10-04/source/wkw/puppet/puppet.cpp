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
const int N=55,INF=1e8;
int a[N],num[N];
int n,ans;
inline void dfs(int x,int res){
	bool flag=0;
	if(x==n+1){
		ans=max(ans,n-res);
		return ;
	}
	if(num[a[x]]){
		num[a[x]]--;
		dfs(x+1,res+1);
		num[a[x]]++;
		flag=1;
	}
	if(num[a[x]+1]){
		num[a[x]+1]--;
		dfs(x+1,res+1);
		num[a[x]+1]++;
		flag=1;
	}
	if(num[a[x]-1]){
		num[a[x]-1]--;
		dfs(x+1,res+1);
		num[a[x]-1]++;
		flag=1;
	}
	if(!flag)	dfs(x+1,res);
}
inline void Init(){
	ans=0;
	for(register int i=1;i<=n;++i)	a[i]=read();
	memset(num,0,sizeof(num));
	for(register int i=1;i<=n;++i)	num[a[i]]++;
	sort(a+1,a+n+1);
	dfs(1,0);
	printlf(ans);
}
signed main(){
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	while(cin>>n){
		Init();
	}
    return 0;
}


