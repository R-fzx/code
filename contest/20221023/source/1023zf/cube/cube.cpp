#include <bits/stdc++.h>

using namespace std;

struct pos{
	int x, y, z;
} ps, ps2;

int a[105][105][105], ans, mx = -1e9, my = -1e9, mz = -1e9, mnx = 1e9, mny = 1e9, mnz = 1e9, n;

int main() {
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ps.x >> ps.y >> ps.z >> ps2.x >> ps2.y >> ps2.z;
		ps.x += 50, ps.y += 50, ps.z += 50, ps2.x += 50, ps2.y += 50, ps2.z += 50;
		mx = max(ps2.x, mx), my = max(ps2.y, my), mz = max(ps2.z, mz);
		mnx = min(ps.x, mnx), mny = min(ps.y, mny), mnz = min(ps.z, mnz);
		for (int j = ps.x; j <= ps2.x; j++) {
			for (int k = ps.y; k <= ps2.y; k++) {
				for (int l = ps.z; l <= ps2.z; l++) {
					a[j][k][l]++;
				}
			}
		}
	}
	for (int i = mnx; i <= mx; i++) {
		for (int j = mny; j <= my; j++) {
			for (int k = mnz; k <= mz; k++) {
				ans += a[i][j][k] >= n - 1;
//				cout << a[i][j][k] << ' ';
			}
//			cout << '\n';
		}
//		cout << '\n';
	}
	cout << ans << '\n';
	return 0;
} 
