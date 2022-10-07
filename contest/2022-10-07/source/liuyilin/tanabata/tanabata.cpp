#include<bits/stdc++.h>
using namespace std;
int l1[100005],l2[100005];
int x1,x2,n,m,t;
//int row(){
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		if(l1[i]>x1)
//			for(int j=1)
//	}
//}
int main(){
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=t;i++){
		int a,b;
		cin>>a>>b;
		l1[a]++;l2[b]++;
	}
//	if(t%n==0&&t%m==0){
//		x1=t/n;x2=t/m;
//		cout<<"both"<<endl;
//		cout<<row()+column()<<endl;
//	}
//	else if(t%n==0){
//		x1=t/n;
//		cout<<"row"<<endl;
//		cout<<row()<<endl;
//	}
//	else if(t%m==0){
//		x2=t/m;
//		cout<<"column"<<endl;
//		cout<<column()<<endl;
//	}
//	else{
		cout<<"impossible"<<endl;
//	}
	return 0;
}
