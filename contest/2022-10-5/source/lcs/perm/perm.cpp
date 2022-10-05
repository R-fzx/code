#include<bits/stdc++.h>
#define int long long
using namespace std;
string S;
int num[15],num2[15];
int sum,s=1,ans;
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>S;
	for(int i=0;i<S.size();++i){
		++num[S[i]-'0'];
	}
	for(int i=1;i<=9;++i)sum+=num[i];
	for(int i=1;i<=sum;++i)s*=i;
	for(int i=1;i<=9;++i){
		for(int j=1;j<=num[i];++j)s/=j;
	}
	for(int i=0;i<=num[0];++i){
		int qaq=1;
		for(int j=1;j<sum;++j)qaq*=(i+1);
		ans+=s*qaq;
	}
	for(int i=0;i<S.size();++i){
		int ansx=1;
		for(int j=1;j<=S.size()-i-1;++j)ansx*=j;
		for(int j=(S[i]-'0')+1;j<=9;++j){
			if(num[j]-num2[j]>0){
				++num2[j];
				for(int k=0;k<=9;++k){
					for(int l=1;l<=num[k]-num2[k];++l)ansx/=l;
				}
				ans-=ansx;
				--num2[j];
			}
		}
		++num2[(S[i]-'0')];
	}
	printf("%lld",ans-1);
	return 0;
}
