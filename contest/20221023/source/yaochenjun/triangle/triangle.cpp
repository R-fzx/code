#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll = long long;

ifstream fin("triangle.in");
ofstream fout("triangle.out");

const int kMaxN = 1e5 + 3;

int n, q;
ll a[kMaxN];
int l, r;

void Multi() {
	if ((r - l) >= 2) {
		for (int x = l; x <= r; x++) {
			for (int y = l; y <= r; y++) {
				if (x == y)  continue;
				for (int z = l; z <= r; z++) {
					if (x == z || y == z)  continue;
					if (a[x] + a[y] > a[z] && a[x] + a[z] > a[y] && a[y] + a[z] > a[x]) {
						fout << "Yes\n";
						return;
					}
				}
			}
		}
	}
	fout << "No\n";
}

signed main() {
	fin >> n >> q;
	for (int i = 1; i <= n; i++) {
		fin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		fin >> l >> r;
		Multi();
	}
	return 0;
}
