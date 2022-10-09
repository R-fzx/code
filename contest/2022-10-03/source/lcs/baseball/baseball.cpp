#include<bits/stdc++.h>
using namespace std;
long long n;
double m;
signed main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	while(scanf("%lld",&n)!=EOF){
		cin>>m;
		int x=1,y;
		double z=1;
		for(int i=1;i<=n;++i)x*=10,z/=10;
		z/=10;
		y=int(m*x);
		int l=0,r=y;
		while(l+1<r){
			int mid=l+r>>1;
			int fm=(int)((double)(mid)/(double)(y)*(double)(x));
			if(((double)(double(mid)/double(fm))-m<z*5.0&&(double)(double(mid)/double(fm)))||(double(double(mid)/double(fm+1))-m<z*5.0&&(double)(double(mid)/double(fm+1))-m>=z*(-5.0)))r=mid;
			else l=mid;
		}
		cout<<(int)((double)(r)/(double)(y)*(double)(x))<<endl;
	}
	return 0;
}
