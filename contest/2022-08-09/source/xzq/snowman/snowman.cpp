#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=5e5+9;
int n,a[N],ans=1;
int main(){
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	n=read();for(int i=1;i<=n;i++)a[i]=read();
	for(int l=2;l<=n/2;l++)for(int i=1;i<=n-l;i++)for(int j=i+1;j<=n-l+1;j++){if(a[j]-a[i]!=a[j+1]-a[i+1])continue;
		bool b=1;for(int k=2;k<l;k++)if(a[j+k]-a[i+k]!=a[j]-a[i]){b=0;break;}
		if(b)ans=max(ans,min(j-i,l));
	}print(ans);
	return 0;
}
