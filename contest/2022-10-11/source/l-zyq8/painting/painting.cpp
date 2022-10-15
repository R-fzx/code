#include<bits/stdc++.h>
#define int long long
using namespace std;
const int q(1000000007);
inline int _pow(int a,int b){
	if(!b)return a;
	int cur(pow(a,b/2));
	if(b&1)return cur*cur%q*a%q;
	return cur*cur%q;
}
int n,m,k,C[809][809],ans;
unordered_map<int,int>r[809][809];
int f(int i,int j,int k,int cnt){
	if(cnt==0&&r[i][j][k])return r[i][j][k]%q;
	if(j*k<i)return 0;
	if(j==1)return (i==k?_pow(cnt+1,q-2):k>i)%q;
	if(i==0)return 1;
	return (i>=k?f(i-k,j-1,k,cnt+1)%q*j%q*_pow(cnt+1,q-2)%q+(r[i][j][k-1]=f(i,j,k-1,0)%q)%q:f(i,j,i,0))%q;
}
int cc(int i,int j){
	if(i==0)return 0;
	if(i==j)return 1;
	if(C[i][j])return C[i][j];
	return C[i][j]=cc(i-1,j)+cc(i-1,j-1);
}
signed main(){
	freopen("painting.in","r",stdin),freopen("painting.out","w",stdout);
	cin>>n>>m>>k;
	for(int i(1);i<=n;i++){
		ans=(ans+cc(i,k)%q*_pow(f(n,i,n,0),2)%q*_pow(i,n*(m-2)))%q;
	}
	cout<<ans;
	return 0;
}
