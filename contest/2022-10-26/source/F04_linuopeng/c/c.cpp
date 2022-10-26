#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
long long maxn,ans=1e18,res,num,tot;
long long a[N];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	long long t=maxn;
	while(t<=maxn+500){
		res=0;
		for(int i=1;i<=n;++i){
//			cout<<t-a[i]<<endl;
			num=t-a[i];tot=0;
			while(num>0){
				++tot;
				num=num&(num-1);
			}
			res+=tot;
		}
		if(res<ans) ans=res;
		++t;
//		return 0;
	}
	cout<<ans;
	



	return 0;
}

