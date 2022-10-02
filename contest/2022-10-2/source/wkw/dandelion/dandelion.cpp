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
const int N=4e4+5;
int a[N],b[N],color[N];
int n,m,ans;
signed main(){
	freopen("dandelion.in","r",stdin);
	freopen("dandelion.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;++i)	a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	int _n=unique(b+1,b+n+1)-b-1;
	for(register int i=1;i<=n;++i)	a[i]=lower_bound(b+1,b+_n+1,a[i])-b;
	
	for(register int i=1;i<=m;++i){
		int l0=read(),r0=read();
		int l=(l0+ans-1)%n+1,r=(r0+ans-1)%n+1;
		if(l>r)	swap(l,r);
		ans=0;
		int sum=0;
		for(register int j=1;j<=n;++j)	color[j]=0;
		for(register int j=l;j<=r;++j){
			color[a[j]]++;
			if(color[a[j]]>sum)	ans=a[j],sum=color[a[j]];		
			else	if(color[a[j]]==sum && ans>a[j])	ans=a[j];
		}
		ans=b[ans];
		printlf(ans);
	}
	
    return 0;
}



