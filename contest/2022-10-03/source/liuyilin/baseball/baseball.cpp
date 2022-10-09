#include<bits/stdc++.h>
using namespace std;
double p10(int n){
	double d=1;
	for(int i=0;i<n;i++)
		d*=10;
	return d;
}
int main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	int n;double r;
	while(~scanf("%d%lf",&n,&r)){
		double pw=p10(n);
		for(int i=1;;i++){
			double d=r*i;
			int p=(int)(d+0.5);
			d=p*pw/i;
			p=(int)(d+0.5);
			if(fabs(p/pw-r)<1e-16){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
} 
