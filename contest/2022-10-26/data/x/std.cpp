#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a), i##_end_ = (b); i <= i##_end_; ++i)
#define drep(i, a, b) for(int i = (a), i##_end_ = (b); i >= i##_end_; --i)
#define clar(a, b) memset((a), (b), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
typedef long long LL;
typedef long double LD;
const double pi = acos(-1);
const int BUF_SIZE = (int)1e6 + 10;
template <typename T> inline bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
template <typename T> inline bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
struct fastIO {
	char buf[BUF_SIZE], buf1[BUF_SIZE];
	int cur, cur1; FILE *in, *out;
	fastIO() { cur = BUF_SIZE, in = stdin, out = stdout; cur1 = 0; }
	inline char getchar() { if(cur == BUF_SIZE) fread(buf, BUF_SIZE, 1, in), cur = 0; return *(buf + (cur++)); }
	inline void putchar(char ch) { *(buf1 + (cur1++)) = ch; if (cur1 == BUF_SIZE) fwrite(buf1, BUF_SIZE, 1, out), cur1 = 0; } inline int flush() { if (cur1 > 0) fwrite(buf1, cur1, 1, out); return cur1 = 0; }
}IO;
#define getchar IO.getchar
#define putchar IO.putchar
LL read() {
	char ch = getchar();
	LL x = 0, flag = 1;
	for (;!isdigit(ch); ch = getchar()) if (ch == '-') flag *= -1;
	for (;isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
	return x * flag;
}
void write(LL x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int Maxn = 200009;
struct segment {
	int l, r;
}a[Maxn];
int n;
void init() {
	n = read();
	rep (i, 1, n) {
		int x = read(), y = read();
		a[i] = (segment){x - y, x + y};
	}
}

void solve() {
	sort(a + 1, a + n + 1, [&](const segment u, const segment v) -> bool {return u.r < v.r;});
	int ans = 0, lef = INT_MIN;
	rep (i, 1, n)
		if (lef < a[i].l) lef = a[i].r, ++ans;
	cout << ans << endl;
}

int main() {

	init();
	solve();

#ifdef Qrsikno
	debug("\nRunning time: %.3lf(s)\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
	return IO.flush();
}

