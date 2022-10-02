#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int N = 4e3 + 5;

int n, m, a[N], b[N], c[N];
int id[N], res[N][];
map<int, int> f;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b + 1, b + n + 1);

	int j = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] > b[i - 1]) {
			id[++j] = b[i];
			f[b[i]] = j;
		}
	}

	for (int i = 1; i <= n; ++i) {
		c[i] = f[a[i]];
		
	}

	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
	}
}