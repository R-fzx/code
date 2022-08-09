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
const int N=5e4+5;
int a[N];
int n,ans;
signed main(){
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i)	a[i]=read();
	for(register int k=n/2;k;--k){
		for(register int i=1;i<=n-2*k+1;++i)
			for(register int j=i+k;j<=n-k+1;++j){
				bool flag=0;
//				cout<<k<<' '<<i<<' '<<j<<endl;
				for(register int l=1;l<k;++l){
					int dis=a[i]-a[j];
					if(a[i+l]-a[j+l]!=dis){
						flag=1;
						break;
					}
				}
				if(!flag){
					print(k);
					return 0;
				}
			}			
	}
//	print(ans);
    return 0;
}


