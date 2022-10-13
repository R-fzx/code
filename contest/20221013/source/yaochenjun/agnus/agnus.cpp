#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kMaxLen = 3e4 + 3;

string st;

int cnt, ans;
bool f[kMaxLen];

signed main() {
	freopen("agnus.in","r",stdin);
	freopen("agnus.out","w",stdout);
	cin >> st;
	for (int i = 0; i < st.size() - 4; i++) {
		if (st[i] == 'a' && st[i + 1] == 'g' && st[i + 2] == 'n' && st[i + 3] == 'u' && st[i + 4] == 's') {
			f[i] = f[i + 1] = f[i + 2] = f[i + 3] = f[i + 4] = 1;
		}
	}
	for (int i = 0; i <= st.size(); i++) {
		if (f[i]) {
			i += 4, ans += (st.size() - i) * (cnt + 1);
			cnt = 4;
		} else {
			cnt++;
		}
	}
	cout << ans;
	return 0;
}
