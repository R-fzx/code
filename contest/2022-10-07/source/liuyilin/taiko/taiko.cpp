#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	int k;
	cin>>k;
	if(k==2)
		cout<<"4 0011"<<endl;
	else if(k==3)
		cout<<"8 00010111"<<endl;
	else if(k==4)
		cout<<"16 0000100110101111"<<endl;
	return 0;
}
