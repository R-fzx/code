#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5, M = 1e4 + 5;

int n, q, l, r, a[N], b[N], dp[M][M];

bool istri(int x, int y, int z) {
	int mx = max(max(x, y), z), mn = min(min(x, y), z), mid = x + y + z - mx - mn;
	return mn + mid > mx;
}

bool find(int l, int r) {
	if (r - l + 1 < 3) {
		return 0;
	}
	for (int i = l; i <= r; i++) {
		b[i - l + 1] = a[i];
	}
	sort(b + 1, b + r - l + 2);
	for (int i = 1; i <= r - l + 1; i++) {
		for (int j = i + 1; j <= r - l + 1; j++) {
			for (int k = j + 1; k <= j + 2 && k <= r - l + 1; k++) {
				if (b[i] + b[j] > b[k]) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		cout << (find(l, r) ? "Yes" : "No") << '\n';
	}
	return 0;
}
