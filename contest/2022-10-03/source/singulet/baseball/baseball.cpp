#include<cstdio>
int n;
long long r,p10[17],a,b,c,d,p,q;
constexpr inline long long min(const long long& x,const long long& y){return x<y?x:y;}
void calc(long long a,long long b,long long c,long long d,long long& p,long long& q){
	long long k=d/c+1;
	if(k*a<b){p=a*k/b+1;q=k;return;}
	long long t=min(b/a,d/c);
	calc(d-t*c,c,b-t*a,a,q,p);
	q+=t*p;
}
int main(){
	p10[0]=1;for(int i=1;i<17;++i)p10[i]=10*p10[i-1];
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	while(~scanf("%d 0.%lld",&n,&r)){
		if(!r){puts("1");continue;}
		a=r*10-5;b=p10[n+1];c=r*10+5;d=p10[n+1];
		while(a%5==0&&b%5==0)a/=5,b/=5;
		while(c%5==0&&d%5==0)c/=5,d/=5;
		calc(a,b,c,d,p,q);
		printf("%lld\n",min(b,q));
	}
	return 0;
}
