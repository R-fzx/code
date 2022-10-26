#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=100010;
int n,cnt,ans=-1,tot;
int p[M];
struct node{
	int x,y;
}a[M];
bool vis[N][N];
map<int,bool> book;
void dfs(int x){
//	tot++;
	if(x==n+1){
		if(ans>=cnt){
			return;
		}
		for(int i=1;i<=cnt;i++){
			for(int j=i+1;j<=cnt;j++){
//				tot++;
				if(!vis[p[i]][p[j]]){
					return;
				}
			}
		}
		ans=cnt;
		return;
	}
	p[cnt+1]=0;
	if(n-x+cnt>ans) dfs(x+1);
	p[++cnt]=x;
	if(n-x+cnt>ans) dfs(x+1);
	p[cnt]=0;
	cnt--;
}
int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	cin>>n;
	bool flag=true;
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].y!=0){
			flag=false;
		}else{
			if(book[a[i].x]){
				ans--;
			}
			book[a[i].x]=true;
		}
	}
	if(flag){
		cout<<ans;
		return 0;
	}else{
		ans=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i].x-a[j].x)>abs(a[i].y+a[j].y)){
				vis[i][j]=vis[j][i]=true;
			}
		}
	}
	dfs(1);
//	cout<<tot<<endl;
	cout<<ans;
	



	return 0;
}

