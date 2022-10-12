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

int xp, yp, xq, yq;
double ans;

int pd(double id) {
	if (fabs(id) < 1e-12)
		return 0;
	if (id < 0)
		return -1;
	return 1;
}

void read() {
	scanf("%d%d%d%d", &xp, &yp, &xq, &yq);
}

double dfs(int times, double len, double x1, double y1, double x2, double y2) {
	if (pd(y2) <= 0 || pd(y1 - len) >= 0 || pd(x2 * 3 + len) <= 0 || pd(x1 * 3 - len) >= 0)
		return 0;
	if (pd(y1) <= 0 && pd(y2 - len) >= 0)
		if (pd(x1 * 3 + len) <= 0 && pd(x2 * 3 - len) >= 0)
			return len + (times - 1) * len * 2.0 / 3.0;
		else if ((pd(x1 * 3 + len) <= 0 && pd(x2) == 0) || (pd(x2 * 3 - len) >= 0 && pd(x1) == 0))
			return len + (times - 1) * len / 3.0;
	double ans = 0.;
	if (pd(x1) <= 0 && pd(x2) >= 0 && pd(min(len * 2.0 / 3.0, y2) - max(0.0, y1)) >= 0)
		ans += min(len * 2.0 / 3.0, y2) - max(0.0, y1);
	ans += dfs(times - 1, len / 3, y1 - len * 2 / 3, -x2, y2 - len * 2 / 3, -x1);
	ans += dfs(times - 1, len / 3, x1, y1 - len * 2 / 3, x2, y2 - len * 2 / 3);
	ans += dfs(times - 1, len / 3, len * 2 / 3 - y2, x1, len * 2 / 3 - y1, x2);
	return ans;
}

void work() {
	ans = dfs(500, 81, xp, yp, xq, yq);
}

void put() {
	printf("%.1lf\n", ans);
}

int main() {
	freopen("Metamorphosis.in", "r", stdin);	freopen("Metamorphosis.out", "w", stdout);
	read();
	work();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
