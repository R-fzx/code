/*����һ����n�ʣ����⣩����n�ķ�������+0��ɵ����У���n֮ǰ���ж��ٸ���
�ȼ��ڽ�n�ķ�������+ָ����0���룬Ȼ������ж��ٸ�<n,Ȼ����λ�ƾ����ˡ�
*/
//ac srm162
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
const int maxn=55;

struct PermutationCounter{
	LL count(string n);
};

LL c[maxn][maxn],ans;
int s[10],lim;
string st,n;
void dfs(int dep){
	if(dep==lim)return;
	int x=st.c_str()[dep]-'0';
	for(int i=0;i<x;i++)
	if(s[i]){
		s[i]--;
		int y=lim-dep-1;
		LL tmp=1;
		for(int j=0;j<10;j++)
		if(s[j]){
			tmp*=c[y][s[j]];
			y-=s[j];
		}
		s[i]++;
		ans+=tmp;
	}
	s[x]--;
	dfs(dep+1);
	s[x]++;
}

int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	cin>>n;
	int i,j;
	c[0][0]=1;
	for(i=1;i<maxn;i++){
		c[i][0]=1;
		for(j=1;j<maxn;j++)
		c[i][j]=c[i-1][j]+c[i-1][j-1];
	}

	ans=0;
	lim=n.size();
	st=n;
	for(i=0;i<lim;i++)
	s[n.c_str()[i]-'0']++;
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
