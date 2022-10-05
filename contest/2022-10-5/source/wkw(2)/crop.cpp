#include<bits/stdc++.h>
#define int long long 
#define printsp(x) print(x),putchar(' ')
#define printlf(x) print(x),putchar('\n')
using namespace std;
inline int read(){
	int x=0;bool w=0;char c=getchar();
	while(!isdigit(c))	w|=c=='-',c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return w?-x:x;
}
inline void print(int x){
	if(x>9)	print(x/10);
	if(x<0)	putchar('-'),x=-x;
	putchar('0'+x%10);		
}
const double eps=1e-5;
const int N=1e6+5;
int x[N],y[N];
int n,A,B,C,D,mod,ans;
inline bool check(int a,int b,int c){
	double ax=x[a],ay=y[a],bx=x[b],by=y[b],cx=x[c],cy=y[c];
	double kab=(ay-by)/(ax-bx);
	double kct=-1/kab,bab=ay-ax*kab;
	double bct=cy-cx*kct;
	double kac=(ay-cy)/(ax-cx);
	double kbr=-1/kac,bbr=by-kbr*bx;
	double xp=(bbr-bct)/(kct-kbr),yp=xp*kct+bct;
	if((xp-double((int)xp))<eps)	return 1;
	return 0;	
}
signed main(){
//	freopen("crop.in","r",stdin);
//	freopen("crop.out","w",stdout);
	n=read(),A=read(),B=read(),C=read(),D=read(),x[1]=read(),y[1]=read(),mod=read();
	int X=x[1],Y=y[1];
	for(register int i=2;i<=n;++i){
		X=(A*X+B)%mod;
		Y=(C*Y+D)%mod;
		x[i]=X,y[i]=Y;	
	}
	for(register int i=1;i<n-1;++i){
		for(register int j=i+1;j<n;++j){
			for(register int k=j+1;k<=n;++k){
				cout<<x[i]<<' '<<x[j]<<' '<<x[k]<<' '<<endl;
				cout<<y[i]<<' '<<y[j]<<' '<<y[k]<<' '<<endl;
				int xx=x[i]+x[j]+x[k]/3,yy=y[i]+y[j]+y[k]/3;
				cout<<xx<<' '<<yy<<" xxuy\n";
				if(xx*3==x[i]+x[j]+x[k]&&yy*3==y[i]+y[j]+y[k])	++ans;
			}
		}
	}
	print(ans/2);
	return 0;
} 
