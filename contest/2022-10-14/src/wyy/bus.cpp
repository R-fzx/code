#include <stdio.h>

long n;

long x, min = 2147483647;
long long ans = 0;

int main() {
freopen("bus.in","rt",stdin);freopen("bus.out","wt",stdout);
	for (scanf("%ld", &n); n; --n, ans += min) {
		scanf("%ld", &x);
		if (min > x) min = x;
	}

	printf("%I64d", ans);
	return 0;
}