#include<bits/stdc++.h>
#define int long long 
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
const int N=2e5+5,mod=1e9+9;
struct node{
	int u,v;
}e[N];
int n,m,ans=1,st=1;
int siz[N];
inline int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)	res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	n=read(),m=read();
//	for(register int i=1;i<=m;++i){
//		e[i].u=read(),e[i].v=read();
//		for(register int j=st;j<(1<<i);++j){
//			int flag=0;
//			memset(siz,0,sizeof(siz));
//			for(register int k=1;k<=i;++k){
////				cout<<(k-1<<1)<<' '<<j<<" what??\n";
//				if(ksm(2,k-1)&j){
////					cout<<k<<' '<<j<<" kj\n";
//					siz[e[k].u]++,siz[e[k].v]++;
//					if(siz[e[k].u]&1)	flag++;
//					if(siz[e[k].v]&1)	flag++;
//					if(siz[e[k].u]%2==0)	--flag;
//					if(siz[e[k].v]%2==0)	--flag;
//				}
//			}
//			if(flag==0)	++ans;
//		}	
//		st=1<<i;
//		printlf(ans%mod);
//	}
	for(register int i=1;i<=m;++i){
		int u=read(),v=read();
		if(siz[u] && siz[v]){
			ans<<=1;
			ans%=mod;
		}
		siz[u]=siz[v]=1;	
		printlf(ans-1);
	}
    return 0;
}


