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
const int maxn = 2 * 1e5 + 5;
int n, m, k;
int h[maxn], Answer;
struct node {
	int x, y;
}Point[maxn];
int num, flag = 1;
inline bool operator <(node A, node B) {
	return A.x != B.x ? A.x < B.x : A.y > B.y;
}
namespace Sub1 {
	const int maxS = 1e7 + 5, maxx = 1e7;
	int C[maxS];
	inline int lowbit(int x) { return x & (-x); }
	inline void Update(int x, int y) { while(x <= maxx) C[x] += y, x += lowbit(x); }
	inline int Query(int x) {
		int res = 0;
		while(x) res += C[x], x -= lowbit(x);
		return res;
	}
	inline void Work() {
		for(register int i = 1; i <= m; ++i) {
			Answer += Query(maxx) - Query(Point[i].y + Point[i].x - 1);
			Update(k - (Point[i].y - Point[i].x) + (num << 1), 1);
		}
		printf("%lld\n", Answer);
	}
}
signed main() {
	freopen("h.in", "r", stdin);
	freopen("h.out", "w", stdout);
	n = read(), k = read();
	for(register int i = 1; i <= n; ++i) {
		h[i] = read();
		if(i == 1) num = h[i];
		else if(num != h[i]) flag = 0;
	}
	m = read();
	for(register int i = 1; i <= m; ++i) Point[i].x = read(), Point[i].y = read();
	sort(Point + 1, Point + m + 1);
	if(flag) {
		Sub1::Work();
 		return 0;
	}
	for(register int i = 1; i <= m; ++i) {
		int minn = h[Point[i].x];
		for(register int j = i + 1; j <= m; ++j) {
			if(Point[j].x != Point[j - 1].x) minn = min(minn, h[Point[j].x]);
			if(Point[i].y + Point[j].y + Point[j].x - Point[i].x - (minn << 1) <= k) Answer++;
		}
 	}
	printf("%lld\n", Answer);
	return 0;
}
 
