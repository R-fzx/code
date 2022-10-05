#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

const int maxn=1000;

int tt,tst,n;
long long ans,x[maxn],y[maxn];
bool cmp(int i,int j){
	return(i<j);
}
bool cmp2(int i,int j){
	return(i>j);
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i];
	for(int i=0;i<n;i++)cin>>y[i];
	sort(x+0,x+n,cmp);
	sort(y+0,y+n,cmp2);
	ans=0;
	for(int i=0;i<n;i++)ans+=x[i]*y[i];
	cout<<ans<<endl;
}
int main(){
	freopen("scalar.in","r",stdin);
	freopen("scalar.out","w",stdout);
	solve();
	return 0;
}
