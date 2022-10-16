#include <bits/stdc++.h>
using namespace std;
int t, n, ans1, ans2;
long long s, x;
bool check(long long x) {
	for(long long i = 2; i * i <= x; i++){
		if(x % i == 0) return 0;
	}	
	return 1;
}
int main() {
	freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;	
		s = n, x = n + 1;
		while(!check(s)){
			s--;
		}
		while(!check(x)){
			x++;
		}
		long long x1 = s - 2, y1 = (s << 1), x2 = n - s + 1, y2 = s * x;
		long long ylcm = y1 * y2 / __gcd(y1, y2);
		ans1 = ylcm / y1 * x1 + ylcm / y2 * x2;
		ans2 = ylcm;
		long long d = __gcd(ans1, ans2);
		cout << ans1 / d << "/" << ans2 / d << endl;
	}
	return 0;
}

