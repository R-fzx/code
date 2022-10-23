#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+10;
int n,q,m,a[maxn];
LL sum=0;
int main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("section.in","r",stdin);
	freopen("section.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--){
		int o,l;
		cin>>o>>l;
		if(o==2) sum=(sum xor a[l]);
		else{
			for(int i=l,j=l+m-1;i<j;i++,j--) swap(a[i],a[j]);
		}
	}
	cout<<sum<<endl;
	return 0;
}
