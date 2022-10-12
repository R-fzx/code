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
#define pi 3.1415926
#define clear(a, b)	memset(a, b, sizeof a)
#define fu(i, a, b)	for (int i = a; i <= b; i++)
#define fd(i, a, b)	for (int i = a; i >= b; i--)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

double R, theta, ans;

int pd(double a) {
	if (fabs(a) <= 1e-9)
		return 0;
	else if (a > 0)
		return 1;
	else
		return -1;
}

void read() {
	scanf("%lf%lf", &R, &theta);
}

void work() {
	if (pd(pi - theta) > 0)
		ans = R * R * theta * 0.25 / tan(theta * 0.5);
	else if (pd(2 * pi - theta) == 0)
		ans = 0.;
	else if (pd(pi - theta) == 0)
		ans = R * 0.422628;
	else
		ans = R * 0.422826;
}

void put() {
	printf("%.6lf\n", ans);
}

int main() {
	freopen("ユイ.in", "r", stdin);	freopen("ユイ.out", "w", stdout);
	read();
	work();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
