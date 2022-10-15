#include<bits/stdc++.h>
using namespace std;
long long n, m, ans, a[100005];
int main(){
	freopen("dt.in", "r", stdin);
	freopen("dt.out", "w", stdout);
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		ans += min(a[x], a[y]);
	}
	cout << ans;
	return 0;
}
