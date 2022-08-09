#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,a[maxn];
bool check(int x){
	int s=0;
	for(int i=1;i<=n-2*x+1;i++)
		for(int j=i+x;j+x-1<=n;j++){
			bool f=1;
			int tmp=a[j]-a[i];
			for(int l=1;l<x;l++)
				if(a[j+l]-a[i+l]!=tmp){
					f=0;
					break;
				}
			if(f)return 1;
		}
	return 0;
}
int main(){
	freopen("snowman.in","r",stdin);
	freopen("snowman.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=0,r=n/2,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

