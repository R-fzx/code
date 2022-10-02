#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
int n,m;
int a[maxn],lsh[maxn],cnt;
int color[maxn],ans;
int main(){
	freopen("dandelion.in","r",stdin);
	freopen("dandelion.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=cnt;j>0;j--)
			if(lsh[j]==a[i]){
				a[i]=j;
				flag=1;
				break;
			}
		if(!flag){
			cnt++;
			lsh[cnt]=a[i];
			a[i]=cnt;
		}
	}
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		l=(l+ans-1)%n+1,r=(r+ans-1)%n+1;
		if(l>r)swap(l,r);
		memset(color,0,sizeof(color));ans=0;
		for(int i=l;i<=r;i++)
			color[a[i]]++;
		int maxm=0;
		for(int i=1;i<=cnt;i++)
			if(color[i]>maxm){
				maxm=color[i];
				ans=lsh[i];
			}
		printf("%d\n",ans);
	}
	return 0;
}

