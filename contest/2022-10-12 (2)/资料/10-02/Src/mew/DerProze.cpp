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

int d, m, y, a;
char *name[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

void read() {
	scanf("%d%d%d", &y, &m, &d);
}

void work() {
	if (m == 1 || m == 2)
		m += 12,	y--;
	if ((y < 1752) || (y == 1752 && m < 9) ||
		(y == 1752 && m == 9 && d < 3))
			a = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + 5) % 7;
	else
		a = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

void put() {
	puts(name[a]);
}

int main() {
	freopen("DerProze.in", "r", stdin);	freopen("DerProze.out", "w", stdout);
	read();
	work();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
