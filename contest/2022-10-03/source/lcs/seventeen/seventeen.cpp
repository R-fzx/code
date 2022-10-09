#include<bits/stdc++.h> 
using namespace std;
long long n,lx,ly;
double ans;
int main(){
	freopen("seventeen.in","r",stdin);
	freopen("seventeen.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		ans+=double(abs(lx*x)+abs(ly*y));
		if(lx!=0){lx*=x;ly*=y;}
		else lx=x,ly=y;
	}
	printf("%.2lf",ans*(-1));
	return 0;
}
