#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m, q, o, l, ans, a[N];

int main() {
	freopen("section.in", "r", stdin);
	freopen("section.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> o >> l;
		if (o == 1) {
			reverse(a + l, a + l + m);
		} else {
			ans ^= a[l];
		}
	}
	cout << ans << '\n';
	return 0;
}
