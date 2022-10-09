#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sillyz.in","r",stdin);
	freopen("sillyz.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int s=0;
	for(int i=1;i<=b;i++){
		int x=1;
		for(int j=i;j;j/=10) x*=j%10;
		if(i*x>=a&&i*x<=b) s++;
	}
	cout<<s<<endl;
	return 0;
} 
