#include<bits/stdc++.h>
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
int n;
struct node {
	int l, r;
}Point[maxn];
int ls[maxn << 1], tot, f[maxn], C[maxn << 1];
inline bool operator <(node x, node y) { return x.r < y.r; }
inline int lowbit(int x) { return x & (-x); }
inline void Update(int x, int num) { while(x <= tot) C[x] = max(C[x], num), x += lowbit(x); return ; }
inline int Query(int x) {
	int res = 0;
	while(x) res = max(res, C[x]), x -= lowbit(x);
	return res;
}
int main() {
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	n = read();
	for(register int i = 1; i <= n; ++i) {
		int x = read(), y = read();
		Point[i].l = x - y, Point[i].r = x + y;
		ls[++tot] = Point[i].l, ls[++tot] = Point[i].r;
	}
	sort(ls + 1, ls + tot + 1), tot = unique(ls + 1, ls + tot + 1) - ls - 1;
	for(register int i = 1; i <= n; ++i) {
		Point[i].l = lower_bound(ls + 1, ls + tot + 1, Point[i].l) - ls;
		Point[i].r = lower_bound(ls + 1, ls + tot + 1, Point[i].r) - ls;
	}
	sort(Point + 1, Point + n + 1);
	int Answer = 0;
	for(register int i = 1; i <= n; ++i) {
		f[i] = Query(Point[i].l - 1) + 1, Update(Point[i].r, f[i]);
		Answer = max(Answer, f[i]);
	}
	printf("%d\n", Answer);
	return 0;
}
 
