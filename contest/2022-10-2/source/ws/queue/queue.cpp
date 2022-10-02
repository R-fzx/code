#include<bits/stdc++.h>
using namespace std;
int n,a[15],b[15],tmp[15];
int main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=i;
	long long sum=0,s=0;
	do{
		s++;
		for(int i=1;i<=n;i++)tmp[i]=a[b[i]];
		for(int i=1;i<=n;i++)for(int j=i-1;j>=0;j--){
			if(j==0 || tmp[j]>=tmp[i]){sum+=i-j;break;}
		}
	}while(next_permutation(b+1,b+n+1));
	cout<<fixed<<setprecision(2)<<sum*1.0/s;
	return 0;
}
