#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
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

conll MD = 1000000007;

ll n, m, k, p, ans, a, aaa;
int map[13][14];

void mi(int id) {
	if (id == 1) {
		a = p;
		return;
	}
	mi(id >> 1);
	a = a * a % MD;
	if (id & 1)
		a = a * p % MD; 
} 

bool check() {
	bool h[26];
	int s[14], p;
	clear(h, 0);
	s[0] = 0;
	fu(i, 1, n)
		fu(j, 1, m)
			h[map[i][j]] = true;
	fu(i, 1, m) {
		clear(h, 0);
		p = 0;
		fu(j, 1, n)
			if (!h[map[j][i]])
				h[map[j][i]] = true,	p++;
		s[i] = s[i - 1] + p;
	}
	fu(i, 1, m - 1)
		if (s[i] != s[m] - s[i])
			return false;
	return true;
}

void dfs(int x, int y) {
	if (x == n && y > m) {
		if (check()) {
/*			fu(i, 1, n)
				fu(j, 1, m)
					printf("%d ", map[i][j]);
			putchar('\n');*/
			aaa++;
		}
		return; 
	} 
	fu(i, 1, k) {
		map[x][y] = i;
		if (y == m && x != n)
			dfs(x + 1, 1);
		else
			dfs(x, y + 1);
	} 
}

void read() {
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	if (n <= 10 && m <= 10)
		dfs(1, 1);
	else
		aaa = n * m % MD * k % MD; 
}

void work() {
/*	int lim = min(n, k);
	fu(i, 1, lim) {
		p = i;
		mi(n);
		ans = a;
		p = i - 1;
		mi(n);
		ans = ans - a - 1;
		if (ans < 0)
			ans += MD; 
		p = ans;
		mi(m);
		aaa = (aaa + a) % MD; 
	}*/
}

void put() {
	printf("%I64d\n", aaa);
}

int main() {
	freopen("painting.in", "r", stdin);	freopen("painting.out", "w", stdout);
	read();
	work();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
