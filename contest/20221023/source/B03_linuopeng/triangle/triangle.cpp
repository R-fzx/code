#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=1010;
int n,cnt;
long long a[N];
bool vis[M][M],book[N];
bool check(int i,int j,int k){
	if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i]){
		return true;
	}else{
		return false;
	}
}
bool pd(int l,int r){
	for(int i=l;i<r-1;i++){
		for(int j=i+1;j<r;j++){
			for(int k=j+1;k<=r;k++){
				if(check(i,j,k)){
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	int T;
	cin>>n>>T;
	cnt=(n/10)+((n%10)!=0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=cnt;i++){
		int l=(i-1)*10+1,r=min(i*10,n);
		bool flag=false;
		if(pd(l,r)){
			vis[l][r]=true;
			book[i]=true;
		}
	}
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		bool flag=false;
		for(int i=(l/10)+((l%10)!=0)+1;i<=(r/10);i++){
			if(book[i]){
				flag=true;
				break;
			}
		}
		if(flag){
			vis[l][r]=true;
			cout<<"Yes"<<endl;
			continue;
		}
		for(int i=l;i<=r;i++){
			for(int j=l;j<=r;j++){
				if(vis[i][j]){
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag){
			vis[l][r]=true;
			cout<<"Yes"<<endl;
			continue;
		}
		if(pd(l,r)){
			vis[l][r]=true;
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}



	return 0;
}

