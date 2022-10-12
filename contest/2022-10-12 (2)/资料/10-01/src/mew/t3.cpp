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

conint MD = 10000;
conint N = 200 + 2;

int n, o;
ll ans;
bool h[12];

struct BIG {
	int a[100];
}f[N];

void mul(BIG &en, int k, BIG &b) {
	en.a[0] = b.a[0];
	int t = 0;
	fu(i, 1, en.a[0]) {
		en.a[i] = b.a[i] * k + t;
		t = en.a[i] / MD;
		en.a[i] %= MD;
	}
	while (t) {
		en.a[++en.a[0]] = t % MD;
		t /= MD;
	}
}

void read() {
	scanf("%d", &n);
}

void minn(BIG &en) {
	en.a[1]--;
}

void pl(BIG &en) {
	en.a[1]++;
}

void work() {
	f[2].a[0] = f[2].a[1] = 1;
	fu(i, 3, n) {
		mul(f[i], i, f[i - 1]);
		if (i & 1)
			minn(f[i]);
		else
			pl(f[i]);
	}
}

void put() {
	printf("%d", f[n].a[f[n].a[0]]);
	fd(i, f[n].a[0] - 1, 1)
		printf("%04d", f[n].a[i]);
	puts("");
}

int main() {
	freopen("t3.in", "r", stdin);	freopen("t3.out", "w", stdout);
	read();
	work();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
