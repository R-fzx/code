#include<bits/stdc++.h>
#define int long long
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
int m=100000;
double l;
int n;
int fm,ffm;
signed main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	srand(rand());
	while(scanf("%lld",&n)!=EOF){
		scanf("%lf",&l);
		fm=pow(10,n);
		int g=(long long)(l*fm);
		int gg=__gcd(fm,g);
		fm/=gg;
		ffm=2e18;
		if(fm<=10000000){
			for(int i=fm;i>=1;i--){
				int f=(long long)(l*i),ff=i,f2=f+1,ff2=i;
				int d=__gcd(f,ff),d2=__gcd(f2,ff2);
				f/=d,ff/=d;f2/=d2,ff2/=d2;
				double ll=1.0*f/ff,ll2=1.0*f2/ff2;
				ll=(double)1.0*(long long)(ll*fm+0.5)/fm;
				ll2=(double)1.0*(long long)(ll2*fm+0.5)/fm;
				if(ll==l){
					if(ff<ffm)ffm=ff;
				}
				else if(ll2==l){
					if(ff2<ffm)ffm=ff2;
				}
			}
			for(int i=fm+1;i<=fm+100;i++){
				int f=(long long)(l*i),ff=i,f2=f+1,ff2=i;
				int d=__gcd(f,ff),d2=__gcd(f2,ff2);
				f/=d,ff/=d;f2/=d2,ff2/=d2;
				double ll=1.0*f/ff,ll2=1.0*f2/ff2;
				ll=(double)((long long)(ll*fm+0.5))/fm;
				ll2=(double)((long long)(ll2*fm+0.5))/fm;
				if(ll==l&&ff<ffm)ffm=ff;
				if(ll2==l&&ff2<ffm)ffm=ff2;
				if(ll!=l&&ll2!=l)break;
			}
			printf("%lld\n",ffm);
		}
		else {
			for(int i=1;i<=m;i++){
				int f=(long long)(l*i),ff=i,f2=f+1,ff2=i;
				int d=__gcd(f,ff),d2=__gcd(f2,ff2);
				f/=d,ff/=d;f2/=d2,ff2/=d2;
				double ll=1.0*f/ff,ll2=1.0*f2/ff2;
				ll=(double)1.0*(long long)(ll*fm+0.5)/fm;
				ll2=(double)1.0*(long long)(ll2*fm+0.5)/fm;
				if(ll==l){
					if(ff<ffm)ffm=ff;
				}
				else if(ll2==l){
					if(ff2<ffm)ffm=ff2;
				}
			}
			int jl=1;
			for(int k=0;k<=5;k++){
				int x=rand()%fm+jl;
				jl=x+m;
				for(int i=x;i<=x+m;i++){
					int f=(long long)(l*i),ff=i,f2=f+1,ff2=i;
					int d=__gcd(f,ff),d2=__gcd(f2,ff2);
					f/=d,ff/=d;f2/=d2,ff2/=d2;
					double ll=1.0*f/ff,ll2=1.0*f2/ff2;
					ll=(double)1.0*(long long)(ll*fm+0.5)/fm;
					ll2=(double)1.0*(long long)(ll2*fm+0.5)/fm;
					if(ll==l){
						if(ff<ffm)ffm=ff;
					}
					else if(ll2==l){
						if(ff2<ffm)ffm=ff2;
					}
				}
			}
			printf("%lld\n",ffm);
		}
	}
	return 0;
}
/*
3 0.316
*/
