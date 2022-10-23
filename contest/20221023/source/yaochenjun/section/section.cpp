#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin("section.in");
ofstream fout("section.out");

const int kMaxN = 1e6 + 3;

int n, m, q;
int a[kMaxN];

int ans;

signed main() {
	fin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		fin >> a[i];
	}
	bool first = 0;
	for (int i = 1, o, l; i <= q; i++) {
		fin >> o >> l;
		if (o == 1) {
			reverse(a + l, a + l + m);
		} else if (o == 2) {
			if (!first) {
				ans = a[l], first = 1;
			} else {
				ans = ans ^ a[l];
			}
		}
	}
	fout << ans;
	return 0;
}

/*
7 3 5 2 16 8 2 16 16 2 1 2 1 3 2 1 2 5 2 6
*/
