#include<cstdio>
#include<unordered_map>
#include<set>
#define _ long long
#define __ std::unordered_map<_,int>
#define ___ __::iterator
#define ____ std::set<_>
#define _____ ____::iterator
_ A,B,K,D,M,R,U,V,F;
__ mp;
___ mpdst;
____ fac;
_____ facdst;
_ stein(_ x,_ y){_ r=1;while((!(x&1))&&(!(y&1)))x>>=1,y>>=1,r<<=1;while(x&&y){while(!(x&1))x>>=1;while(!(y&1))y>>=1;if(x>y)x-=y;else y-=x;}return r*(x?x:y);}
_ mul(_ x,_ y,_ m){_ r=0;if(x<y)x^=y^=x^=y;while(y){if(y&1){r+=x;if(r>=m)r-=m;}x<<=1;y>>=1;if(x>=m)x-=m;}return r;}
_ pow(_ x,_ y,_ m){_ r=1;while(y){if(y&1)r=mul(x,r,m);x=mul(x,x,m);y>>=1;}return r;}
int main(){
	freopen("kubi.in","r",stdin);freopen("kubi.out","w",stdout);
	int T,c;scanf("%d",&T);while(T--){
		scanf("%lld%lld%lld",&A,&B,&K);
		D=stein(A,B);A/=D;B/=D;mp.clear();c=M=R=0;U=K;fac.clear();
		for(_ i=2;i*i<=U;++i)while(U%i==0)++mp[i],U/=i;
		if(U>1)++mp[U];mpdst=mp.end();
		for(___ i=mp.begin();i!=mpdst;++i,c=0){while(B%(i->first)==0)++c,B/=(i->first);c=(c-1)/(i->second)+1;if(c>M)M=c;}
		if(B==1){printf("%lld 0\n",M);continue;}F=U=B;
		for(_ i=2;i*i<=U;++i)if(U%i==0){F=F/i*(i-1);do{U/=i;}while(U%i==0);}
		if(U>1)F=F/U*(U-1);
		for(_ i=1;i*i<=F;++i)if(F%i==0)fac.insert(i),fac.insert(F/i);
		facdst=fac.end();U=1;V=0;K%=B;
		for(_____ i=fac.begin();i!=facdst;++i){
			U=mul(U,pow(K,*i-V,B),B);
			if(U==1){R=*i;break;}
			V=*i;
		}
		printf("%lld %lld\n",M,R);
	}
	return 0;
}
