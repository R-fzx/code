#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int n;
int a[maxn],t[1005];
int p[maxn];
double ans;
double cj(int x){
	double tmp=1;
	for(int i=2;i<=x;i++)
		tmp*=i;
	return tmp;
}
int main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t[a[i]]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<a[i];j++)
			p[i]+=t[j];
	for(int i=1;i<=n;i++){
//		ans+=((p[i]+1)*cj(p[i])*(double)(n-p[i]-1==0?1:cj(n-p[i]-1)))/cj(n);
//		cout<<ans<<' '<<i<<' '<<p[i]<<endl;
		for(int j=p[i];j>0;j--){
			ans+=((j+1)*cj(p[i])*(cj(n-j-2)*(n-p[i]-1)*(n-j-1)+cj(n-j-1)))/cj(n);
//			cout<<ans<<' '<<i<<' '<<j<<' '<<((j+1)*cj(p[i])*(cj(n-j-2)*(n-p[i]-1)*(n-j-1)+cj(n-j-1)))/cj(n)<<"********"<<endl;
		}
		ans+=(cj(n-2)*(n-p[i]-1)*(n-1)+cj(n-1))/cj(n);
//		cout<<ans<<' '<<i<<' '<<(cj(n-2)*(n-p[i]-1)*(n-1)+cj(n-1))/cj(n)<<"********"<<endl;
	}
	printf("%.2lf\n",ans);
	return 0;
}
