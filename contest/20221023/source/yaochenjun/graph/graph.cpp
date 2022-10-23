#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1003;

int n, a[kMaxN];

bool f[kMaxN];
vector<int> e[kMaxN];

int ans;

signed main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, [](int x, int y) {
		return x > y;
	});
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!(a[i] & a[j])) {
				e[i].push_back(j), e[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			int mx = -1, p = -1;
			for (int j : e[i]) {
				if (f[j]) {
					if (a[j] > mx) {
						mx = a[j], p = j;
					}
				}
			}
			f[i] = 1;
			if (p != -1) {
				ans += a[p];
				//cout << "操作2. 由点 " << a[p] << " 加入点 " << a[i] << "，分数为 " << a[p] << endl; 
			} else {
				//cout << "操作1. 加入点 " << a[i] << "，分数为 0\n";
			}
		}
	}
	cout << ans;
	return 0;
}
