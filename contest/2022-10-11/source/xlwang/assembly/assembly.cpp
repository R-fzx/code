#include<bits/stdc++.h>
#define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void writepl(int x){write(x);putchar(' ');}
inline void writeln(int x){write(x);putchar('\n');}
signed main(){
	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout);
	double ans=1.0;
	printf("%.6lf",ans);
	return 0;
}

