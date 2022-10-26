#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_; ++i)
#define drep(i, a, b) for(int i = (a), i##_end_ = (b); i >= i##_end_; --i)
#define clar(a, b) memset((a), (b), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
typedef long long LL;
typedef long double LD;
LL read() {
    char ch = getchar();
    LL x = 0, flag = 1;
    for (;!isdigit(ch); ch = getchar()) if (ch == '-') flag *= -1;
    for (;isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    return x * flag;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar(x % 10 + 48);
}

const int Maxn = 200009;
const int MaxSize = 1e6 + 7;
struct BIT {
	LL c[MaxSize];
#define lowbit(x) ((x) & -(x))
	void modify(int pos, LL val) {
		pos += MaxSize / 2;
		for (; pos < MaxSize; pos += lowbit(pos)) c[pos] += val;
	}
	LL query(int pos) {
		LL r = 0; pos += MaxSize / 2;
		for (; pos; pos -= lowbit(pos)) r += c[pos];
		return r;
	}
#undef lowbit
}lef, rig;

int n, k, h[Maxn], m;
vector <int> s[Maxn];
inline void Init() {
	n = read(), k = read();
	rep (i, 1, n) h[i] = read();
	m = read();
	rep (i, 1, m) {
		int l = read(), a = read();
		s[l].push_back(a);
	}
}

LL ans = 0;

struct node {
	int x, y, mask;
};
void calc(int l, int r) {
	if (l > r) return ;
	if (l == r) {
		sort(s[l].begin(), s[l].end());
		int p1 = -1;
		rep (i, 0, s[l].size() - 1) {
			while (s[l][i] - (~p1 ? s[l][p1] : 0) > k) ++p1;
			ans += i - (~p1 ? p1 : 0);
		}
		return ;
	}
	int mid = (l + r) >> 1;
	calc(l, mid); calc(mid + 1, r);
	int Mn = 0x3f3f3f3f;
	vector <node> zqc;
	drep (i, mid, l) {
		Mn = min(Mn, h[i]);
		for (auto y : s[i]) zqc.push_back((node){i, y, min(Mn, y)});
	}
	Mn = 0x3f3f3f3f;
	rep (i, mid + 1, r) {
		Mn = min(Mn, h[i]);
		for (auto y : s[i]) zqc.push_back((node){i, y, min(Mn, y)});
	}
	sort(zqc.begin(), zqc.end(), [&](const node &a, const node &b) -> bool {return a.mask < b.mask;});
	rep (i, 0, zqc.size() - 1) {
		node v = zqc[i];
		if (v.x <= mid) {
			lef.modify(v.y - v.x - 2 * v.mask, 1);
			ans += rig.query(k + v.x - v.y);
		} else {
			rig.modify(v.y + v.x - 2 * v.mask, 1);
			ans += lef.query(k - v.x - v.y);
		}
	}
	rep (i, 0, zqc.size() - 1) {
		node v = zqc[i];
		if (v.x <= mid) lef.modify(v.y - v.x - 2 * v.mask, -1); else rig.modify(v.y + v.x - 2 * v.mask, -1);
	}
}

void Solve() {
	calc(1, n);
	printf("%lld\n", ans);
}

int main() {
//	freopen("20.in", "r", stdin);
//	freopen("20.out", "w", stdout);

	Init(); 
	Solve();

#ifdef Qrsikno
    debug("\nRunning time: %.3Lf(s)\n", clock() * 1.0L / CLOCKS_PER_SEC);
#endif
    return 0;
}
