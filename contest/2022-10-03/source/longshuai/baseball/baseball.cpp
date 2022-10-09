#include<bits/stdc++.h>
using namespace std;
int n;
double r;
int main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	while(scanf("%d%lf",&n,&r)){
//	scanf("%d%lf",&n,&r);
		double f=1,i=1;
		while(i<=n)f/=10,i++;
		long long t=0,step;
		while(r<0.1)t++,r*=10,f*=10;
		step=2;
		while(1){
			double tmp=r*step*1.0;
			int b=max((int)(tmp+0.5),1);
//			getchar();
//			cout<<b<<endl<<tmp<<endl<<t<<endl;
			if(abs(b-tmp)<=f*step*1.0){
				while(t--)step*=10;
				printf("%lld\n",step);
				break;
			}
			step++;
		}
	}
//	double f=6.9004;
//	cout<<(int)(f+0.5)<<endl;
	return 0;
}
