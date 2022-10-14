#include<bits/stdc++.h>
using namespace std;

map<int,map<int,bool> >mp;
int main(){
	freopen("codes.in","w",stdout);
	int t=100;
	srand(time(0));
	int n=200000;
	cout<<n<<'\n';
	for(int i=1;i<=n;++i){
		cout<<1ll*rand()*rand()<<' '<<1ll*rand()*rand()<<'\n';
	}
	return 0;
}

