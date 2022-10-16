#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool Prime(ll x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
ll Gcd(ll x, ll y) {
	if (!y) {
		return x;
	}
	return Gcd(y, x % y);
}

int T, n;

void Multi() {
	cin >> n;
	if (n == 2) {
		cout << "1/6\n";
	} else {
		ll v = n, u = n + 1;
		while (!Prime(v)) {
			v--;
		}
		while (!Prime(u)) {
			u++;
		}
		ll top = v * u - u * 2 + (n - v + 1) * 2, bottom = v * u * 2;
		ll gcd = Gcd(top, bottom);
		top /= gcd, bottom /= gcd;
		cout << top << '/' << bottom << endl;
	}
}

signed main() {
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin >> T;
	while (T--) {
		Multi();
	}
	return 0;
}
