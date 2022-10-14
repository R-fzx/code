#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const long long INF = 1LL << 62;

struct Point {
	long x, y;
} *A, *B;

Point a[234567];
long n;

long i;

inline int cmp_point(const void *a, const void *b) {
	A = (Point *)a, B = (Point *)b;
	if (A->x > B->x) return 1;
	if (A->x < B->x) return -1;
	return A->y > B->y ? 1 : -1;
}

inline long long squ(const long x) {
	return (long long)x * x;
}

long long calc(long l, long r) {
	long long min, tmp;
	if (r - l <= 2) {
		for (min = INF; l < r; ++l)
			for (i = l + 1; i <= r; ++i)
				if ( min > (tmp = squ(a[l].x - a[i].x) + squ(a[l].y - a[i].y)) ) min = tmp;
		return min;
	}
	long j = (l + r) >> 1;
	if ( (min = calc(l, j)) > (tmp = calc(j, r)) ) min = tmp;
	while (a[j].x - a[l].x >= min) ++l;
	while (a[r].x - a[j].x >= min) --r;
	for (; l <= r; ++l)
		for (i = 1; i <= 8; ++i)
			if ( (j = l + i) <= r && min > (tmp = squ(a[l].x - a[j].x) + squ(a[l].y - a[j].y)) ) min = tmp;
	return min;
}

int main() {
freopen("dark.in","rt",stdin);freopen("dark.out","wt",stdout);
	scanf("%ld", &n);
	for (i = 0; i < n; ++i) scanf("%ld%ld", &a[i].x, &a[i].y);

	qsort(a, n, sizeof(Point), cmp_point);

	printf("%.2lf", sqrt(calc(0, n - 1)));
	return 0;
}