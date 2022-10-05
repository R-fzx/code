#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
const int maxn = 1e5 + 5;
int tot, n, A, B, C, D, x, y, mod;
struct node {
	int x, y;
}Point[maxn];
int f[maxn][5][5][5], Answer;
map < pair<int, int>, int> mapp;
signed main() {
	freopen("crop.in", "r", stdin);
	freopen("crop.out", "w", stdout);
	n = read(), A = read(), B = read(), C = read(), D = read(), x = read(), y = read(), mod = read();
	Point[1].x = x, Point[1].y = y;
	mapp[make_pair(x, y)] = 1;
	for(register int i = 2; i <= n; ++i) {
		x = (A * x + B) % mod;
		y = (C * y + D) % mod;
		if(!mapp[make_pair(x, y)]) Point[i].x = x, Point[i].y = y;
		mapp[make_pair(x, y)] = 1;
	}
	for(register int i = 0; i <= n; ++i) f[i][0][0][0] = 1;
	for(register int i = 1; i <= n; ++i) {
		for(register int j = 1; j <= min(i, 3ll); ++j)
			for(register int k = 0; k < 3; ++k)
				for(register int p = 0; p < 3; ++p)
					f[i][j][k][p] = f[i - 1][j][k][p] + f[i - 1][j - 1][(k + 3 - (Point[i].x % 3)) %3][(p + 3 - (Point[i].y % 3)) % 3];
	}
	printf("%lld\n", f[n][3][0][0]);
	return 0;
}
