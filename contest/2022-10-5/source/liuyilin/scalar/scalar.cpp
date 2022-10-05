#include<bits/stdc++.h>
using namespace std;
long long v1[805],v2[805];
int main(){
	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>v1[i];
	for(int i=0;i<n;i++)
		cin>>v2[i];
	sort(v1,v1+n);
	sort(v2,v2+n,greater<int>());
	long long s=0;
	for(int i=0;i<n;i++)
		s+=v1[i]*v2[i];
	cout<<s<<endl;
	return 0;
}
