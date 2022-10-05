#include<bits/stdc++.h>
//#define int long long
//#define double long double
#define gt getchar
using namespace std;
int read(){
	int x=0,f=1;
	char ch=gt();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gt();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gt();
	return x*f;
}
const int N=805;
int a[N];
signed main(){
	freopen("scalar.in","w",stdout);
	int n=read();
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		bool b=rand()%2;
		int x=rand()%100000;
		if(b==1)cout<<x<<' ';
		else cout<<-x<<' ';
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		bool b=rand()%2;
		int x=rand()%100000;
		if(b==1)cout<<x<<' ';
		else cout<<-x<<' ';
	}
	return 0;
}

