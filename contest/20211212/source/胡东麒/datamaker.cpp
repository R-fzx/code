#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("cowjump.in","w",stdout);
	srand(time(0));
	int n=100000;
	cout<<n<<'\n';
	for(int i=1;i<=n;++i){
		cout<<1ll*rand()*rand()%(1000000001)<<' '<<1ll*rand()*rand()%(1000000001)<<' '<<1ll*rand()*rand()%(1000000001)<<' '<<1ll*rand()*rand()%(1000000001)<<'\n';
	}
}
