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
const int maxn = 5 * 1e5 + 5, maxk = 105, INF = 1e9 + 7;
int n, A, B, C;
struct node {
	int a, b, c, sum;
}Point[maxn];
int f[maxk][maxk][maxk], Sum[maxk][maxk][maxk];
inline bool operator <(node x, node y) {
	return x.sum < y.sum;
}
signed main() {
	freopen("ゆりっぺ.in", "r", stdin);
	freopen("ゆりっぺ.out", "w", stdout);
	n = read(), A = read(), B = read(), C = read();
	for(register int i = 1; i <= n; ++i) {
		Point[i].a = read(), Point[i].b = read(), Point[i].c = read();
		Point[i].sum = Point[i].a + Point[i].b + Point[i].c;
	}	
	sort(Point + 1, Point + n + 1);
	for(register int a = 0; a <= A; ++a)
		for(register int b = 0; b <= B; ++b)
			for(register int c = 0; c <= C; ++c) f[a][b][c] = -INF;
	f[0][0][0] = Sum[0][0][0] = 0;
	for(register int i = 1; i <= n; ++i)
		for(register int a = A; a >= 0; --a)
			for(register int b = B; b >= 0; --b)
				for(register int c = C; c >= 0; --c) {
					if(a && f[a - 1][b][c] + Point[i].a > f[a][b][c])
						f[a][b][c] = f[a - 1][b][c] + Point[i].a, Sum[a][b][c] = Sum[a - 1][b][c] + Point[i].sum;
					if(b && f[a][b - 1][c] + Point[i].b > f[a][b][c])
						f[a][b][c] = f[a][b - 1][c] + Point[i].b, Sum[a][b][c] = Sum[a][b - 1][c] + Point[i].sum;
					if(c && f[a][b][c - 1] + Point[i].c > f[a][b][c])
						f[a][b][c] = f[a][b][c - 1] + Point[i].c, Sum[a][b][c] = Sum[a][b][c - 1] + Point[i].sum;
				}
	printf("%lld\n%lld\n", f[A][B][C], Sum[A][B][C]);
	return 0;
}
