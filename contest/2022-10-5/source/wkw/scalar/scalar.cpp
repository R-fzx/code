#include<bits/stdc++.h>
#define int long long 
#define printsp(x) print(x),putchar(' ')
#define printlf(x) print(x),putchar('\n')
using namespace std;
inline int read(){
	int x=0;bool w=0;char c=getchar();
	while(!isdigit(c))	w|=c=='-',c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return w?-x:x;
}
inline void print(int x){
	if(x>9)	print(x/10);
	if(x<0)	putchar('-'),x=-x;
	putchar('0'+x%10);
}
int n,ans;
const int N=805;
int a1[N],a2[N];
signed main(){
	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)
		a1[i]=read();
	for(register int i=1;i<=n;++i)
		a2[i]=read();
	sort(a1+1,a1+n+1);
	sort(a2+1,a2+n+1,greater<int>());
	for(register int i=1;i<=n;++i)
		ans+=a1[i]*a2[i];
	print(ans);
	return 0;
}

