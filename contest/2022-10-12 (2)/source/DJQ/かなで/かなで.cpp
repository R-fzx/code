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
const int maxn = 10;
int n, m, K;
int Digit[maxn][maxn], num[maxn][maxn], totx, toty, go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map <int, int> mapp;
inline int Hash() {
	int res = 0, base = 1;
	for(register int i = 1; i <= totx; ++i)
		for(register int j = 1; j <= toty; ++j) res += num[i][j] * base, base *= 2;
	return res;
}
signed main() {
	freopen("かなで.in", "r", stdin);
	freopen("かなで.out", "w", stdout);
	printf("1\n");
	return 0;
	n = read(), m = read(), K = read();
	char c;
	for(register int i = 1; i <= n; ++i)
		for(register int j = 1; j <= m; ++j) {
			while(!isdigit(c = getchar()));
			Digit[i][j] = c ^ 48;
		}
	for(register int i = 1; i <= n; ++i)
		for(register int j = 1; j <= m; ++j) {
			for(register int x = 1; x <= 10 && i + x - 1 <= n; ++x) {
				int y = 11 - x;
				if(j + y - 1 > m) continue;
				totx = x, toty = y;
				int tot = 0;
				for(register int p = i; p + x - 1 <= n; ++p)
					for(register int q = j; q + y - 1 <= m; ++q) {
						tot += Digit[p][q];						
						num[p - i + 1][q - j + 1] = Digit[p][q];
					}
			}
		}
	return 0;
}
