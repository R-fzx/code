#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,ans;
int len;
void getlen(){
	int tmp=b;
	while(tmp){
		len++;
		tmp/=10;
	}
}
void getans(int siz,int num,int sum){
	if(sum*num>b||siz>len)return;
	if(sum*num>=a){
		ans++;
//		cout<<sum*num<<endl;
//		cout<<sum<<' '<<num<<endl;
	}
	for(int i=1;i<=9;i++){
		int s=num*10+i;
		if(s*sum>b)break;
		getans(siz+1,s,sum*i);
	}
}
signed main(){
	freopen("sillyz.in","r",stdin);
	freopen("sillyz.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	getlen();
	getans(1,0,1);
	printf("%lld\n",ans);
	return 0;
}
