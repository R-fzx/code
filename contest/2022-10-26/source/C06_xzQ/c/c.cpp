#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),puts("")
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int N=1e5+9;
int n,a[N],b[N],clk,cnt,ans=LONG_LONG_MAX,l,r=(int)1e18;
map<long long,int>num;
int calc(int x){
	int tot=0;
	for(int i=1;i<=cnt;i++){
		int tmp=x-b[i],tmp2=0;
		while(tmp){
			tmp2++;
			tmp-=(1ll<<(long long)(log2(tmp)));
		}
		tot+=tmp2*num[b[i]];
	}
	return tot;
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	clk=clock();
	n=read();
	if(n==1)return puts("0"),0;
	for(int i=1;i<=n;i++){
		a[i]=read();l=max(l,a[i]);
		if(!num[a[i]])b[++cnt]=a[i];
		num[a[i]]++;
	}
	for(int i=l;;i+=2){
		ans=min(ans,calc(i));
		if(clock()-clk>2800)break;
	}
	print(ans);
	return 0;
}
/*
3
2 2 8
*/
