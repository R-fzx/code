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
const int mod=1e9+7;
int n;
inline int qp(int a,int b){
	int res=1;
	while(b){
		if(b&1)	res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}	
	return res;
}
signed main(){
//	freopen("sakura.in","r",stdin);
//	freopen("sakura.out","w",stdout);
    return 0;
}



