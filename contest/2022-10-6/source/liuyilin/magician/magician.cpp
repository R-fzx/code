#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int r=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r;
}
const int N=2e5+5,Md=1e9+9;
bool d[N];
int main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	int n=read(),m=read();
	int u,v;
	int ans=1;
	while(m--){
		u=read();v=read();
		if(d[u]&&d[v]){
			ans<<=1;
			if(ans>Md) ans-=Md;
		}
		d[u]=d[v]=true;
		printf("%d\n",ans-1);
	}
	return 0;
}
