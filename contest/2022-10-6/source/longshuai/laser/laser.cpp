#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5;
int n,k;
ll l[maxn],r[maxn];
int gro[15];
int main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout); 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&l[i],&r[i]);
	ll tmp=1,t=k;
	while(t--)tmp*=10;
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n;i++)
			l[i]%=tmp,r[i]%=tmp;
		tmp/=10;
		for(int i=1;i<=n;i++){
			gro[l[i]/tmp-1]=1,gro[r[i]/tmp]=1;
			if(r[i]%tmp>0&&l[i]<=r[i]-10)gro[r[i]/tmp-1]=1;
		} 
	}
	for(int i=1;i<10;i++){
		printf("%d",i);
		if(gro[i])printf("\n");
	}
//	if(k==1){
//		for(int i=1;i<=n;i++)
//			l[i]%=10,r[i]%=10;
//		for(int i=1;i<=n;i++)
//			gro[l[i]-1]=1,gro[r[i]]=1;
//		for(int i=1;i<10;i++){
//			printf("%d",i);
//			if(gro[i])printf("\n");
//		}
//		return 0;
//	}
//	if(n==1){
//		
//	}
	return 0;
}
