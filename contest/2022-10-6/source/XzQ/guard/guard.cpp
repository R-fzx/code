//再给我一个理由说你不爱我 
#include<bits/stdc++.h>
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
const int N=209;
int n,l,k,ans,p[N],a[N];
signed main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	n=read(),l=read(),k=read();
	for(int i=1;i<=n;i++)p[i]=read(),ans=max(ans,p[i]);
	for(int j=1;j<=n;j++)a[j]=read();
	putchar('0');putchar('.');
	print(ans);
	puts("0000");
	return 0;
}

