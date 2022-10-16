#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e6 + 15, M = 1e6 + 15;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

struct Frac{
	ll son, mat;
} q[N];

ll t, n, prime[M], k = 1e6 + 10;
bool isprime[N];

void getprime() {
	fill(isprime + 2, isprime + k + 1, 1);
	for (int i = 2; i <= k; i++) {
		if (isprime[i]) {
			prime[++prime[0]] = i;
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= k; j++) {
			isprime[i * prime[j]] = 0;
			if (i % prime[j] == 0) {
				break;
			}
		}
	} 
}

int main() {
	freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	getprime();
	q[2].son = 1, q[2].mat = 6;
	Frac f = {1, 15};
	for (ll i = 3, j = 3; i <= k - 10; i++) {
		if (i == prime[j]) {
			f.mat = f.mat / prime[j - 1] * prime[j + 1];
			j++;
		}
		ll g = gcd(f.mat, q[i - 1].mat);
		q[i].mat = q[i - 1].mat / g * f.mat;
		q[i].son = q[i].mat / f.mat + q[i].mat / q[i - 1].mat * q[i - 1].son;
		ll g2 = gcd(q[i].mat, q[i].son);
		q[i].mat /= g2, q[i].son /= g2;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << q[n].son << '/' << q[n].mat << '\n';
	}
	return 0;
} 
