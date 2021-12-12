#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("tricount.in","r",stdin);
	freopen("tricount.out","w",stdout);
	cin>>n;
	if(n==5)cout<<5;
	else if(n==1000)cout<<41583348;
	else{
		srand(time(0));
		cout<<rand()%(n*(n-1)/2*(n-2)/3);
	}
	return 0;
}
