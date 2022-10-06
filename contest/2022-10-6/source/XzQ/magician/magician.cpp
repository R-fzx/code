#include<bits/stdc++.h>
//去年的冬天，我们笑得很甜 
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define int long long
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
const int N=3e5+9,mod=1e9+9;
int n,m,in[N],vis[N],ans=1;
signed main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	n=read(),m=read();
	while(m--){
		int x=read(),y=read();
		if(vis[x]&&vis[y])ans=(ans<<1)%mod;
		vis[x]=vis[y]=1;
		printen(ans-1);
	}
	return 0;
}
