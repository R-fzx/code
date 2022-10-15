#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 3;

int n, m;
int a[kMaxN];

long long ans;

signed main() {
	freopen("dt.in","r",stdin);
	freopen("dt.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1, _u, _v; i <= m; i++) {
		scanf("%d%d", &_u, &_v);
		ans += min(a[_u], a[_v]);
	}
	cout << ans;
	return 0;
}
