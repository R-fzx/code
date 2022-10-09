#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define int long long
using namespace std;
inline int read(){
	register int x(0),f(1);char c(getchar());
	while((c-'0'>>63)||('9'-c>>63)){if(c=='-')f=-1;c=getchar();}
	while(('0'-c-1>>63)&&(c-'9'-1>>63))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
inline void print(int x){
	if(9-x>>63)print(x/10);
	putchar(x%10+'0');
}
int n,m,ans,len;
inline void dfs(int num,int cnt,int l){
	if(l==len)return;
	for(register int i(1);(i-10>>63);++i){
		register int nm((num<<1)+(num<<3)+i);
		if(m-nm*cnt*i>>63)break;
		if((n-1-nm*cnt*i>>63)&&(nm*cnt*i-m-1>>63))ans++;
		dfs(nm,cnt*i,l+1);
	}
	return;
}
inline void work2(){
//	cout<<clock()<<endl;
	register int t(m);
	for(;t;t/=10,++len);
	dfs(0,1,0);
	print(ans);
//	cout<<endl<<clock()<<endl;
}
signed main(){
	freopen("sillyz.in","r",stdin);
	freopen("sillyz.out","w",stdout);
	n=read(),m=read();
	if(m-n>>63)swap(n,m);
	work2();
	return 0;
}
