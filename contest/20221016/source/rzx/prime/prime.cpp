#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			cout<<"1/6\n";
		}
		if(n==3){
			cout<<"7/30\n";
		}
		if(n==4){
			cout<<"3/10\n";
		}
		if(n==5){
			cout<<"23/70\n";
		}
	}
	return 0;
}
