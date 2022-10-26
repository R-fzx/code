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

inline void w(int x) {
	if (x > 9) w(x / 10);
	putchar(x % 10 + 48);
}


int main() {
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int n;
	rd(n);
	w(n);
	return 0;
}
