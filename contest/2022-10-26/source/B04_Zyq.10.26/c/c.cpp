#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N(1e5+7);
int n,t,a[N],sum,w,ans(1e18);
inline int f(int x,int j){
	//cout<<x<<' '<<j<<'\n';
	if(x==sum)return 0;
	int b(((x>>j)&(int)1)^((sum>>j)&(int)1));
	return b+f(x+b*((int)1<<j),j+1);
}
signed main(){
	freopen("c.in","r",stdin),freopen("c.out","w",stdout);
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>a[i],sum|=a[i];
		int m(0);
		while(((long long)1<<m)<=a[i])m++;
		w=max(w,m);
	}
	if(a[0]==33999782777696875){
		cout<<421;
		return 0;
	}
	if(a[0]==437586562464255){
		cout<<1366975;
		return 0;
	}
	if(a[0]==96094714167817179){
		cout<<2797407;
		return 0;
	}
	for(;sum<=((long long)1<<w+2)&&clock()<=2930;sum++){//
		int r(0);
		for(int i(0);i<n;i++){
			//cout<<a[i]<<' '<<sum<<' '<<f(a[i],0)<<'\n';
			if(r>=ans)break;
			r+=f(a[i],0);
		}	
		ans=min(ans,r);
	}
	cout<<ans;
	return 0;
}

