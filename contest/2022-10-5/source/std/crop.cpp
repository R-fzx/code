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

typedef long long LL;

LL s[10],ret,n,a,b,c,d,tt,xo,yo,m;
int tst;

void init(){
	cin>>n>>a>>b>>c>>d>>xo>>yo>>m;
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++){
		s[(xo%3)*3+(yo%3)]++;
		xo=(a*xo+b)%m;
		yo=(c*yo+d)%m;
	}
}
void solve(){
	ret=0;
	for(int i=0;i<9;i++)
	ret+=s[i]*(s[i]-1)*(s[i]-2)/(LL)6;

	for(int i=0;i<9;i++)
	for(int j=i+1;j<9;j++)
	for(int k=j+1;k<9;k++)
	if(( ((i/3)+(j/3)+(k/3))%3==0 )
	&&( ((i%3)+(j%3)+(k%3))%3==0 ))
	ret+=s[i]*s[j]*s[k];
	cout<<ret<<endl;
}
int main(){
	freopen("crop.in","r",stdin);
	freopen("crop.out","w",stdout);
		init();
		solve();
	return 0;
}
