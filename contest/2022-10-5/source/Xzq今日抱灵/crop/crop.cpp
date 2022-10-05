#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define y1 ggggggg
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
const int N=1e5+9;
struct digit{
	int s,m;
};
int n,A,B,C,D,M,ans;
digit x[N],y[N];
digit operator*(digit r,int g){
	digit t=r;
	t.s*=g;
	int gc=__gcd(t.s,t.m);
	t.s/=gc,t.m/=gc;
	return t;
}
digit operator*(digit r,digit g){
	digit t=r;
	t.s*=g.s,t.m*=g.m;
	int gc=__gcd(t.s,t.m);
	t.s/=gc,t.m/=gc;
	return t;
}
digit operator/(digit r,digit g){
	digit t;
	t.s=g.m,t.m=g.s;
	return r*t;
}
digit operator+(digit r,digit g){
	digit t;
	t.m=r.m*g.m,t.s=r.s*g.m+g.s*r.m;
	int gc=__gcd(t.s,t.m);
	t.s/=gc,t.m/=gc;
	return t;
}
digit operator-(digit r,digit g){
	digit t=g;
	t.s=-t.s;
	return r+t;
}
digit turn(digit r){
	digit t=r;
	int tt=t.s;
	t.s=t.m;
	t.m=tt;
	return t;
}
signed main(){
	freopen("crop.in","r",stdin);
	freopen("crop.out","w",stdout);
	n=read(),A=read(),B=read(),C=read(),D=read(),x[1].s=read(),y[1].s=read(),M=read();
	x[1].m=y[1].m=1;
	for(int i=2;i<=n;i++){
		x[i].m=y[i].m=1;
		x[i].s=(A*x[i-1].s+B)%M;
		y[i].s=(C*y[i-1].s+B)%M;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				digit x1=x[i],y1=y[i],x2=x[j],y2=y[j],x3=x[k],y3=y[k];
				digit k1=turn((x2-x1)/(y1-y2)),k2=turn((x2-x3)/(y3-y2));
				digit b1=y3-k1*x3,b2=y1-k2*x1;
				digit xx=(k1-k2)/(b2-b1),yy=k1*xx+b1;
				if(xx.m==1&&yy.m==1)ans++;
			}
		}
	}
	print(ans);
	return 0;
}
