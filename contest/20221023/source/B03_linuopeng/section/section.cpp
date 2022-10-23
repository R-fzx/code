#include<bits/stdc++.h>
#include<fstream>
using namespace std;
const int N=1000010;
int n,m,ans;
int a[N];
int main(){
	freopen("section.in","r",stdin);
	freopen("section.out","w",stdout);
	int T;
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	while(T--){
		int o,l;
		scanf("%d%d",&o,&l);
		if(o==1){
			for(int i=l,j=l+m-1;i<j;i++,j--){
				swap(a[i],a[j]);
			}
		}else{
			ans^=a[l];
		}
	}
	cout<<ans;



	return 0;
}

