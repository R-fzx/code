#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,k;
long long ans;
int h[N],st[N+100010][20];
struct node{
	int x,y;
}a[N];
int _min(int x,int y){
	if(h[x]<h[y]) return x;
	else return y;
}
int q(int l,int r){
	int ans=0;
	while(l<=r){
		int x=log2(r-l+1);
//		cout<<x<<" "<<st[l][x]<<endl;
		ans=_min(ans,st[l][x]);
		l+=(1<<x);
	}
	return ans;
}
int get_dis(int x1,int y1,int x2,int y2){
	int ans=abs(x1-x2)+abs(y1-y2);
	int minn=q(min(x1,x2),max(x1,x2));
	return ans+2*(min(y1,y2)-h[minn]);
}
int main(){
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	cin>>n>>k;
	h[0]=1e9;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		st[i][0]=i;
	}
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
//			cout<<i+(1<<((j-1)))<<endl;
			st[i][j]=_min(st[i][j-1],st[i+(1<<((j-1)))][j-1]);
		}
	}
//	int x,y;
//	while(cin>>x>>y){
//		cout<<q(x,y)<<endl;
//	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(get_dis(a[i].x,a[i].y,a[j].x,a[j].y)<=k){
				ans++;
			}
		}
	}
	cout<<ans;



	return 0;
}
/*
10 1
1 2 3 4 1 5 6 3 7 8 
*/
