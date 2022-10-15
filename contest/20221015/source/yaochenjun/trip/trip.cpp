#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 5e4 + 3;

struct Node {
	int x, y;
	double w;
} a[kMaxN * 2];

int n, m, s, t;
int c[kMaxN], b[kMaxN];

int fa[kMaxN];
int cnt, ans1, ans2 = 1e9;

int Find(int u) {
	if (fa[u] == u) {
		return u;
	}
	return fa[u] = Find(fa[u]);
}

signed main() {
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lf", &a[i].x, &a[i].y, &a[i].w);
	}
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		cnt += x;
		for (int j = 1, y; j <= x; j++) {
			scanf("%d", &y);
			b[y] = i;
		}
	}
	for (int i = 1;  i<= n; i++) {
		scanf("%d", &c[i]);
	}
	scanf("%d%d", &s, &t);
	for (int i = 1; i <= m; i++) {
		if (b[a[i].x] == b[a[i].y]) {
			a[i].w = (double) a[i].w * c[b[a[i].x]] / 100.0;
		} else {
			a[i].w = (double) a[i].w * double(c[b[a[i].x]] + c[b[a[i].y]]) / 200.0;
		}
	}
	sort(a + 1, a + m + 1, [](Node x, Node y) {
		return x.w < y.w;
	});
	int l = 1, r = m;
	while (l < r) {
		int mid = (l + r) >> 1;
		for (int i = 1; i <= cnt; i++) {
			fa[i] = i;
		}
		int i = mid;
		for (; i <= m; i++) {
			int fx = Find(a[i].x), fy = Find(a[i].y);
			if (fx != fy) {
				fa[fx] = fy;
				if (Find(s) == Find(t)) {
					break;
				}
			}
		}
		if (Find(s) != Find(t)) {
			r = mid;
		} else {
			l = mid + 1;
			int _x = floor(a[mid].w), _y = ceil(a[i].w);
			if (_x > ans1) {
				ans1 = _x, ans2 = _y;
			}
			if (_x == ans1) {
				ans2 = min(ans2, _y);
			}
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}

/*3 7
1 2 3
5 2 8
1 3 7
5 4 5
2 4 9
3 5 10
3 4 2
2 1 2
1 3
2 4 5
30 50 60
1 5*/
