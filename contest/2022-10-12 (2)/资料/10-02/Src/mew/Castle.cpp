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

conll MD = 2147483647;
conint N = 1000 + 3;
conint M = 499500 + 10;
conint L = 1023;

int n, m, top;
int x, y, z, op, cl;
int v[N], q[L + 1];
int start[N], to[M << 1], next[M << 1], l[M << 1];
bool b[N], sig[N][N];
ll ans, cnt[N];

void graph(int x, int y, int z) {
	next[++top] = start[x];	to[start[x] = top] = y;	l[top] = z;
	next[++top] = start[y];	to[start[y] = top] = x;	l[top] = z;
}

void read() {
	scanf("%d%d", &n, &m);
	fu(i, 1, m) {
		scanf("%d%d%d", &x, &y, &z);
		if (!sig[x][y] && x != y) {
			graph(x, y, z);
			sig[x][y] = sig[y][x] = true;
		}
	}
}

void work() {
	clear(v, 0x3F);
	for (v[q[b[1] = cl = 1] = 1] = op = 0; x = q[++op & L], op <= cl; b[x] = 0)
		for (int i = start[x]; y = to[i], i; i = next[i])
			if (v[x] + l[i] < v[y]) {
				v[y] = v[x] + l[i];
				cnt[y] = 1;
				if (!b[y])
					b[q[++cl & L] = y] = 1;
				}
			else if (v[x] + l[i] == v[y])
				cnt[y]++;
	ans = 1;
	fu(i, 2, n)
		ans = ans * (cnt[i] % MD) % MD;
}

void put() {
	printf("%I64d\n", ans);
}

int main() {
	freopen("Castle.in", "r", stdin);	freopen("Castle.out", "w", stdout);
	read();
	work();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
