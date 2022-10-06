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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cout<<(1<<1)<<endl;
	int ans=0;
	for(register int i=1;i<=10;++i){
		int res=1;
		for(register int j=1;j<=i;++j)
			res*=j;
		ans+=res;
	}
	cout<<ans;
    return 0;
}



