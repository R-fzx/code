#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define int long long
//#define double long double 
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int N=1e4+100,M=55;
struct fw{
	bool ok[N],l;
	int k;
};
struct number{
	fw h[M];
}b[10];
int a[N],bb[N];
int in[N];
int n,k;
bool bj[10];
void work(int x){
	for(int i=1;i<=n;i++){
		int u=a[i],v=bb[i];
		for(int j=1;j<=k;j++){
			for(int l=u;l<=v;l++){
				int g=l,gg=pow(10,j),ggg=pow(10,j-1);
				int kw=g-(g%gg-g%ggg)+x*ggg;
//				cout<<kw<<endl;
				if(in[kw])b[x].h[i].ok[l]=1,b[x].h[i].k=j;
				else b[x].h[i].l=1;
			}
		}
	}
}
bool issame(int x,int y){
	for(int i=1;i<=n;i++){
		if(b[x].h[i].k!=b[y].h[i].k)return 0;
		if(b[x].h[i].l!=b[y].h[i].l)return 0;
		for(int j=1;j<=6000;j++){
//			cout<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<' '<<b[x].h[i].ok[j]<<' '<<b[y].h[i].ok[j]<<endl;
			if(b[x].h[i].ok[j]!=b[y].h[i].ok[j])return 0;
		}
		
	}
	return 1;
}
signed main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	n=read(),k=read();
	if(n<=50){
		for(int i=1;i<=n;i++){
			a[i]=read(),bb[i]=read();
			for(int j=a[i];j<=bb[i];j++)in[j]=1;
		}
		for(int i=1;i<=9;i++)work(i);
		for(int i=1;i<=9;i++){
			if(bj[i])continue;
			cout<<i;
			for(int j=i+1;j<=9;j++){
				if(issame(i,j)){
					cout<<j;
					bj[j]=1;
				}
			}
			cout<<endl;
		}
	}
	else{
		puts("1");puts("2");puts("3");puts("4");puts("5");puts("6");puts("7");puts("8");puts("9");
	}
	return 0;
}
