#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')

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
const int N=309;
int n,h[N],q[N];
double ans,p,s[N];
signed main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)h[i]=read();
	for(int i=1;i<=n;i++)q[i]=i;
	do{
		memset(s,0,sizeof(s));
		h[0]=1009;
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				if(h[q[i]]>=h[q[j]])s[q[j]]=(double)(j-i);
		}
		for(int i=1;i<=n;i++)ans+=s[i];
		p++;
	}while(next_permutation(q+1,q+n+1));
	printf("%.2lf",ans/p);
	return 0;
}
