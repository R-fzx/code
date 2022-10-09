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
int n;
double r;
double kpow(double x,int k,double res=1){
	if(k==0)return 1;
	for(;k;k>>=1,x*=x)if(k&1)res*=x;
	return res;
}
signed main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		scanf("%lf",&r);
		double t=kpow(0.1,n)*5,t2=kpow(10,n);
		for(double i=1;;i++){
			int x=((i*r+t)*t2)/10;
			bool b=1;
			for(int i=1;i<n;i++){
				if(x%10!=0){b=0;break;}
				x/=10;
			}
			if(b){
				printen((int)i);
				break;
			}
		}
	}
	return 0;
}
