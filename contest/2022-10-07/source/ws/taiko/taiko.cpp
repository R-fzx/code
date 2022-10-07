#include<bits/stdc++.h>
using namespace std;

int n;
int k;

int vis[10005];

queue<int>q;
int vvs[(1<<11)+5];

bool check(int x){
	q.push(x);
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		vvs[u]=1;
		
		int lu=(u<<1)&k,
			ru=lu+1;
		
		if(!vvs[lu] && !vis[lu])
			q.push(lu);
		if(!vvs[ru] && !vis[ru])
			q.push(ru);
	}
	
	bool ret=1;
	
	for(int i=0;i<=k;i++){
		if(!vis[i] && !vvs[i])
			ret=0;
		vvs[i]=0;
	}
	return ret;
}

int main(){
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	
	cin>>n;
	
	k=(1<<n)-1;
	
	cout<<k+1<<' ';
	
	vector<int>ans;
	int p=0;
	
	while("By Ew_Cors"){
		vis[p]=1;
		ans.push_back(p);
		
		int lp=(p<<1)&k,
			rp=lp+1;
		
		if(vis[lp] && vis[rp])
			break;
		
		if(!vis[lp] && check(lp))
			p=lp;
		else
			p=rp;
	}
	
	for(int i=1;i<n;i++)
		cout<<'0';
	
	for(int i=0;i<ans.size()-n+1;i++)
		cout<<(ans[i]&1);
	
	return 0;
}
