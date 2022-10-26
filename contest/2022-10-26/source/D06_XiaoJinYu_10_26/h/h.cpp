#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

inline void rd(int& s) {
	s = 0;
	int c(getchar());
	while (c < 48 || c > 57) c = getchar();
	while (c > 47 && c < 58) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
}

inline void w(long long x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 2e5 + 5;

struct Node {
	int x, y, mh;
} a[MAXN];

int h[MAXN];

bool cmp(Node x, Node y) {
	return x.x < y.x;
}

int main() {
	freopen("h.in", "r", stdin);
	freopen("h.out", "w", stdout);
	int n, k, m;
	long long ans = 0;
	rd(n), rd(k);
	for (int i = 0; i < n; ++i) {
		rd(h[i]);
	}
	rd(m); 
	for (int i = 0; i < m; ++i) {
		rd(a[i].x), rd(a[i].y);
	}
	sort(a, a + m, cmp);
	for (int i = 0, minh = 1145141919, j = 0; i < n; ++i) {
	if (h[i] < minh) minh = h[i];
		if (i == a[j].x) {
			if (j) {
				a[j].mh = minh;
			}
			minh = h[i];
			++j;
		}
	}
	int lj = 0;
	for (int i = 0; i < m; ++i) {
		int minh = 1145141919, cnt = 0, j = i + 1;
		if (lj && lj - 900 > i + 1) {
			j = lj - 900;
			ans += lj - 900 - (i + 1);
		}
		for (; j < m && cnt < 900; ++j) {
			if (a[j].mh < minh) minh = a[j].mh;
			if (a[i].y < minh && a[j].y < minh) {
				if (a[j].x - a[i].x <= k) ++ans;
				else ++cnt;
			} else if(abs(a[i].y - minh) + abs(a[j].y - minh) + a[j].x - a[i].x <= k) {
				++ans;
			} else {
				++cnt;
			}
		}
		lj = j;
	}
	w(ans);
	return 0;
}
