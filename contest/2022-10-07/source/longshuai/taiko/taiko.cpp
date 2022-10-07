#include<bits/stdc++.h>
using namespace std;
int k;
bool vis[1<<12],f;
long long len;
string ans;
void getans(string str){
	memset(vis,false,sizeof(vis));
	string t=str+str;
	int leg=str.size();
	for(int i=0;i<leg;i++){
		int tmp=0;
		for(int j=i;j<i+k;j++)
			tmp=(tmp<<1)+t[j]-'0';
		if(vis[tmp])return;
		vis[tmp]=1;
	}
	ans=str;f=1;
}
void buildstr(int n,string str){
//	cout<<n<<' '<<str<<endl;
	if(n<=0){
		getans(str);
		return;
	}
	buildstr(n-1,str+"0");
	buildstr(n-1,str+"1");
}
bool check(int sum){
	f=0;
	buildstr(sum,"");
	return f;
}
int main(){
	freopen("taiko.in","r",stdin);
	freopen("taiko.out","w",stdout);
	scanf("%d",&k);
	for(int i=1<<k;i>0;i--)
		if(check(i)){
			cout<<i<<' '<<ans<<endl;
			return 0;
		}
	return 0;
}
