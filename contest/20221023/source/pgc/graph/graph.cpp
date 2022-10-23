#include<bits/stdc++.h>
using namespace std;
long long n, a[2005], ans, l, b[2005];
bool f[2005][2005], x[2005];
void dfs(int now){
	if(x[now] == 0){
		return;
	}
	b[++l] = now;
	for(int i = 1; i <= n; i++){
		if(now != i && f[now][i] && x[i]){
			dfs(i);
		}
	}
}
int main(){
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		x[i] = 1;
	}
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i] & a[j] == 0){
				f[i][j] = 1, f[j][i] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		l = 0;
		if(x[i]){
			dfs(i);
		}
		long long minx = 100000000000;
		for(int j = 1; j <= l; j++){
			minx = min(minx, a[b[j]]);
			ans += a[b[j]];
		}
		ans -= minx;
	}
	cout << ans;
	return 0;
}
