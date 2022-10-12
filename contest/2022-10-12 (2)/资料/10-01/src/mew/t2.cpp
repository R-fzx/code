#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#define conint const int
#define condou const double
#define conll const ll
#define clear(a, b)	memset(a, b, sizeof a)
#define fu(i, a, b)	for (int i = a; i <= b; i++)
#define fd(i, a, b)	for (int i = a; i >= b; i--)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

conint LIM = 1000000000;

ll n, m;
ll cnt[120];

ll calc(ll mi, ll p) {
	ll l = 1, r = p;
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		ll o = p;
		for (ll i = 1; i <= mi; i++)
			o /= mid;
		if (!o)
			r = mid - 1;
		else
			l = mid;
	}
	return l;
}

ll deal(ll id) {
	clear(cnt, 0);
	ll ans = 0;
	for (ll i = 61; i; i--) {
		cnt[i] = calc(i, id);
		for (ll j = 2; i * j <= 61; j++)
			cnt[i] -= cnt[i * j];
		ans += cnt[i] * i;
	}
	return ans;
}

void work() {
	ll ans1 = deal(n - 1);
	ll ans2 = deal(m);
	ll ans = ans2 - ans1;
	printf("%I64d\n", ans);
}

int main() {
	freopen("t2.in", "r", stdin);	freopen("t2.out", "w", stdout);
	for (scanf("%I64d%I64d", &n, &m); n && m; scanf("%I64d%I64d", &n, &m))
		work();
	fclose(stdin);	fclose(stdout);	return 0;
}
