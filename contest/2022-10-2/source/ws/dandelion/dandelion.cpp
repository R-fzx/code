#include<bits/stdc++.h>
using namespace std;
int n,m,a[40005],b[40005];
int tmp[40005];
unordered_map<int,int>mm;
int main(){
	freopen("dandelion.in","r",stdin);
	freopen("dandelion.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];b[i]=a[i];}
	sort(b+1,b+n+1);int cnt=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	for(int i=1,l,r,lst=0;i<=m;i++){
		cin>>l>>r;
		l=(l+lst-1)%n+1,r=(r+lst-1)%n+1;
		if(l>r)swap(l,r);
		int k=l*n+r;
		if(mm[k]){cout<<mm[k]<<endl;continue;}
		int id=0;
		for(int j=l;j<=r;j++){
			tmp[a[j]]++;
			if(tmp[a[j]]>tmp[id] || (tmp[a[j]]==tmp[id] && a[j]<id))id=a[j];
		}
		for(int j=l;j<=r;j++)tmp[a[j]]--;
		cout<<(mm[k]=lst=b[id])<<endl;
	}
	return 0;
}
