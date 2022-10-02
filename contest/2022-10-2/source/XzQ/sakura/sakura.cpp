#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define int long long
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
const int mod=1e9+7;
int _n,ans;
struct digit{
	int len,a[10009];
};
digit zero,one;
digit operator*(digit t,int y){
	digit x=t;
	for(int i=1;i<=x.len;i++)x.a[i]*=y;
	for(int i=x.len;i>=1;i--)x.a[i-1]+=x.a[i]/10,x.a[i]%=10;
	if(x.a[0]){
		x.len++;
		for(int i=x.len;i>=1;i--)x.a[i]=x.a[i-1];
	}
	return x;
}
digit operator+(digit x,digit y){
	digit cnt;
	memset(cnt.a,0,sizeof(cnt.a));
	cnt.len=max(x.len,y.len);
	for(int i=1;i<=cnt.len;i++){
		cnt.a[cnt.len-i+1]=((x.len-i<0)?0:x.a[x.len-i+1])+((y.len-i<0)?0:y.a[y.len-i+1]);
	}
	for(int i=cnt.len;i>=1;i--)cnt.a[i-1]+=cnt.a[i]/10,cnt.a[i]%=10;
	if(cnt.a[0]){
		cnt.len++;
		for(int i=cnt.len;i>=1;i--)cnt.a[i]=cnt.a[i-1];
	}
	return cnt;
}
digit operator-(digit x,digit y){
	digit cnt;
	memset(cnt.a,0,sizeof(cnt.a));
	cnt.len=max(x.len,y.len);
	for(int i=1;i<=cnt.len;i++){
		cnt.a[cnt.len-i+1]=((x.len-i<0)?0:x.a[x.len-i+1])-((y.len-i<0)?0:y.a[y.len-i+1]);
	}
	for(int i=cnt.len;i>=1;i--)
		if(cnt.a[i]<0)cnt.a[i-1]--,cnt.a[i]+=10;
	if(!cnt.a[1]){
		cnt.len--;
		for(int i=1;i<=cnt.len;i++)cnt.a[i]=cnt.a[i+1];
	}
	return cnt;
}
bool operator>(digit x,digit y){
	if(x.len>y.len)return 1;
	if(x.len<y.len)return 0;
	for(int i=1;i<=x.len;i++){
		if(x.a[i]>y.a[i])return 1;
		if(x.a[i]<y.a[i])return 0;
	}
	return 0;
}
bool operator<(digit x,digit y){
	if(x.len>y.len)return 0;
	if(x.len<y.len)return 1;
	for(int i=1;i<=x.len;i++){
		if(x.a[i]>y.a[i])return 0;
		if(x.a[i]<y.a[i])return 1;
	}
	return 0;
}
bool operator == (digit x,digit y){
	if(x.len!=y.len)return 0;
	for(int i=1;i<=x.len;i++){
		if(x.a[i]!=y.a[i])return 0;
	}
	return 1;
}
bool operator != (digit x,digit y){
	if(x==y)return 0;
	return 1;
}
digit operator/(digit x,digit y){
	digit cnt;
	memset(cnt.a,0,sizeof(cnt.a));
	cnt.len=1;
	while(x>y){
		cnt=cnt+one;
		x=x-y;
	}
	if(x==y)cnt=cnt+one;
	return cnt;
}
digit operator%(digit x,digit y){
	digit cnt;
	while(x>y){
		x=x-y;
	}
	if(x==y)return zero;
	return x;
}
digit operator*(digit x,digit y){
	digit cnt;
	memset(cnt.a,0,sizeof(cnt.a));
	for(int i=1;i<=x.len;i++){
		cnt=cnt*10+y*x.a[i];
	}
	return cnt;
}
void write(digit x){
	for(int i=1;i<=x.len;i++)print(x.a[i]);
	puts("");
}
void work(){
	int n=1;
	for(int i=2;i<=_n;i++)n*=i;
	for(int x=n+1;x<n*2;x++){
		if((n*x)%(x-n)!=0)continue;
		ans=(ans+1)%mod;
	}
	print(ans+1);
}
signed main(){
	freopen("sakura.in","r",stdin);
	freopen("sakura.out","w",stdout);
	_n=read();
	if(_n<=11)return work(),0;
	digit n;
	n.len=1,n.a[1]=1;
	zero.len=1,zero.a[1]=0;
	one.len=1,one.a[1]=1;
	for(int i=2;i<=_n;i++)n=n*i;
	for(digit x=n+one;x<n*2;x=x+one){
		if((n*x)%(x-n)!=zero)continue;
		ans=(ans+2)%mod;
	}
	print((ans+1)%mod);
	return 0;
}
