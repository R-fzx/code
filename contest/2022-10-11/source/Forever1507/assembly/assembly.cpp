#include<bits/stdc++.h>
using namespace std;
int n,k,A;
double ans=0.0,maxn=0.0;
struct node{
	int b,l;
}a[15];
bool vis[10];
double calc(int cnt){
//	for(int i=1;i<=n;++i)cout<<vis[i]<<' ';
//	cout<<'\n';
//	for(int i=1;i<=n;++i)cout<<a[i].l<<' ';
//	cout<<'\n';
	double ans=1.0,_ans=1.0;
	int num=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
//			if(_ans==0)_ans=1;
			num+=a[i].b,_ans*=1.0*(100-a[i].l)/100;
		}
		else{
//			if(ans==0)ans=1;
			ans*=1.0*a[i].l/100;
		}
	}
	double _num=0.0;
	_num+=1.0*A/(A+num)*ans*_ans;
//	cout<<_num<<' '<<num<<"f\n";
	if(cnt>n/2)_num+=1.0*num/(A+num)*ans*_ans;
	return _num;
}
void get_ans(int x,int cnt){
	if(x==n+1){
		ans+=calc(cnt);
		return;
	}
//	if(cnt+n-x+1<=n/2)return;
	vis[x]=0;
	get_ans(x+1,cnt);
	vis[x]=1;
	get_ans(x+1,cnt+1);
}
void dfs(int x,int num){//要第x个人， 已送出num份礼 
	if(x==n+1){
		memset(vis,0,sizeof(vis));
		ans=0;
		get_ans(1,0);
//		cout<<"ans= "<<ans<<'\n';
		maxn=max(maxn,ans);
		return;
	}
	if(x==n){
		int base=a[x].l;
		a[x].l=min(100,a[x].l+10*(k-num));
		dfs(x+1,k);
		a[x].l=base;
		return;
	}
	for(int i=0;i<=k-num;++i){
		int base=a[x].l;
		a[x].l=min(100,a[x].l+10*i);
		dfs(x+1,num+i);
		a[x].l=base;
	}
	return;
}
int main(){
	freopen("assembly.in","r",stdin);
	freopen("assembly.out","w",stdout); 
//	ios::sync_with_stdio(0);
	cin>>n>>k>>A;
	for(int i=1;i<=n;++i){
		cin>>a[i].b>>a[i].l;
	}
	dfs(1,0);
	printf("%.6lf",maxn);
	return 0;
}
