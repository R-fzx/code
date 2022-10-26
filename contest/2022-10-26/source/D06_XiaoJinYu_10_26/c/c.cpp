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

inline void rdl(long long& s) {
	s = 0;
	int c(getchar());
	while (c < 48 || c > 57) c = getchar();
	while (c > 47 && c < 58) s = (s << 1) + (s << 3) + (c ^ 48), c = getchar();
}

inline void w(int x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 1e5 + 5;

long long a[MAXN];

int fuck(long long x) {
	int cnt = 0;
	for (;x; x >>= 1) {
		if (x & 1) ++cnt;
	}
	return cnt;
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int n;
	long long m = 0, maxx = -114514;
	rd(n);
	if (n == 1) {
		w(0);
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		rdl(a[i]);
		if (a[i] > maxx) maxx = a[i];
	}
//	sort(a[i]);
//	for (int i = 1; i < n; ++i) {
//		a[i] -= a[0];
//	}
//	a[0] = 0;
	m = maxx << 1;
	long long ans = 1145141919810114514;
	for (long long i = maxx; clock() < 900 && i < m; ++i) {
		long long sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += fuck(i - a[j]);
		}
		if (sum < ans) ans = sum;
	}
	w(ans);
	return 0;
}
