#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kMaxN = 1e6 + 3;

int n, q, T;

ll x[kMaxN], y[kMaxN], s_x[kMaxN], s_y[kMaxN];

void Multi() {
	cin >> n >> q;
	for (int i = 1, _x, _y; i <= n; i++) {
		cin >> _x >> _y;
		x[i] = _x + _y;
		y[i] = _x - _y;
	}
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 1; i <= n; i++) {
		s_x[i] = s_x[i - 1] + x[i];
		s_y[i] = s_y[i - 1] + y[i];
	}
	for (int i = 1, _x, _y; i <= q; i++) {
		ll ans = 0;
		cin >> _x >> _y;
		ll fx = upper_bound(x + 1, x + 1 + n, _x + _y) - x - 1, fy = upper_bound(y + 1, y + 1 + n, _x - _y) - y - 1;
		ans = ((((fx * (_x + _y)) - s_x[fx]) + (s_x[n] - s_x[fx]) - ((n - fx) * (_x + _y))) + (((fy * (_x - _y)) - s_y[fy]) + (s_y[n] - s_y[fy]) - ((n - fy) * (_x - _y)))) / 2;
		cout << ans << endl;
	}
}

signed main() {
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	cin >> T;
	while (T--) {
		Multi();
	}
	return 0;
}
