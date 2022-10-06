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
const int N=205;
double p[N],ans;
int flag[N],a[N];
int L,K,n;
inline void dfs(int stp,int lst){
//	cout<<stp<<' '<<lst<<" stplst\n";
	if(stp>=L){
		double res=1;
		int bag=K;
//		for(register int i=1;i<=n;++i)
//			cout<<flag[i]<<' ';cout<<" flag\n";
		for(register int i=1;i<=n;++i){
			if(flag[i]){
				res*=(p[i]/100);
				if(a[i]==-1)	bag--;
				else	bag+=a[i];
			}
			else	res*=((100-p[i])/100);
		}
//		cout<<bag<<' '<<res<<endl;
		if(bag>=0)	ans+=res;
	}
	for(register int i=lst+1;i<=min(n,n-(L-stp)+1);++i){
		flag[i]=1;
		dfs(stp+1,i);
		flag[i]=0;
	}
}
signed main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	n=read(),L=read(),K=read();
	for(register int i=1;i<=n;++i)	p[i]=read();
	for(register int i=1;i<=n;++i)	a[i]=read();
	dfs(0,0);
	printf("%.6lf",ans);
    return 0;
}


