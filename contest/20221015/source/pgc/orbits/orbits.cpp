#include<bits/stdc++.h>
using namespace std;
long long ans, n, m, k;
void dfs(long long i, long long sum){
	if(i == n){
		if(sum % k == 0 && __gcd(sum / k, k) == 1)ans++;
		return;
	}
	for(int j = 1; j <= m; j++){
		dfs(i + 1, sum * j);
	}
}
int main(){
    freopen("orbits.in","r",stdin);
    freopen("orbits.out","w",stdout);
    cin >> n >> m >> k;
    dfs(0, 1);
    cout << ans % 10007;
    return 0;
}
