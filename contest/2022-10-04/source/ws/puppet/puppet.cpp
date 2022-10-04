#include<bits/stdc++.h>
using namespace std;

int n,a[105],b[105],ans;

void work(){
	
}

int main(){
	freopen("puppet.in","r",stdin);
	freopen("puppet.out","w",stdout);
	
	while(cin>>n){
		for(int i=1,x;i<=n;i++){
			cin>>x;
			a[x]++,
			b[x]++;
		}
		for(int i=1;i<=n;i++)
			work();
		cout<<ans<<endl;
	}return 0;
}
