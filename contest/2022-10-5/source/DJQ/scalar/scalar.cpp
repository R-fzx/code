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
const int maxn = 805;
int n;
int a[maxn], b[maxn], Answer;
inline bool cmp(int x, int y) { return x > y; }
signed main() {
	freopen("scalar.in", "r", stdin);
	freopen("scalar.out", "w", stdout);
	n = read();
	for(register int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + n + 1);
	for(register int i = 1; i <= n; ++i) b[i] = read();
	sort(b + 1, b + n + 1, cmp);
	for(register int i = 1; i <= n; ++i) Answer += a[i] * b[i];
	printf("%lld\n", Answer);
	return 0;
}
