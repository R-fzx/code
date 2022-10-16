#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cassert>
#define rr int
using namespace std;
typedef long long ll;
inline ll read() {
	char i=getchar();
	ll f=1,res=0;
	while(i<'0'||i>'9') {
		if(i=='-')f=-1;
		i=getchar();
	}
	while(i>='0'&&i<='9') {
		res=res*10+i-'0';
		i=getchar();
	}
	return f*res;
}
const int N = 105;
int dp[N][N][2005][2]/*0��1��*/, n, k, m/*mֻ����*/;
struct zk {
	int pos, bonus, time;
	bool operator < (const zk &A) const {
		if (pos != A.pos) return pos < A.pos;
		return time < A.time;
	}
} a[N];
int maxt;
//by LRL
inline int dis(int i, int j) {
	return abs(a[i].pos - a[j].pos);
}
int main() {
	freopen("go.in", "r", stdin);
	freopen("go.out","w", stdout);
	memset(dp, -0x3f, sizeof dp);
	n = read(), k = read(), m = read() + 1;
	for (rr i = 1; i < m; ++i) {
		a[i].pos = read();
		a[i].bonus = read();
		a[i].time = read();
		maxt = max(maxt, a[i].time);
	}
	a[m].pos = k;
	a[m].bonus = 0;
	a[m].time = 1;
	sort(a + 1, a + m + 1);
	for (rr i = 1; i <= m; ++i) if (a[i].bonus == 0) {
			dp[i][i][1][0] = dp[i][i][1][1] = 0;
			break;//������
		}
	int ans = -0x3f3f3f3f;
	for (rr len = 2; len <= m; ++len) {
		for (rr i = 1; i <= m; ++i) {
			int j = i + len - 1;
			if (j > m) break;
			for (rr t = maxt; t >= 1; --t) {
				int bonus = (t <= a[i].time) ? a[i].bonus : 0;
				if (t - dis(i, i + 1) > 0) {
					dp[i][j][t][0] = max(dp[i][j][t][0], dp[i + 1][j][t - dis(i, i + 1)][0] + bonus);
					ans = max(ans, dp[i][j][t][0]);
				}
				if (t - dis(i, j) > 0) {
					dp[i][j][t][0] = max(dp[i][j][t][0], dp[i + 1][j][t - dis(i, j)][1] + bonus);
					ans = max(ans, dp[i][j][t][0]);
				}
				bonus = (t <= a[j].time) ? a[j].bonus : 0;
				if (t - dis(j, j - 1) > 0) {
					dp[i][j][t][1] = max(dp[i][j][t][1], dp[i][j - 1][t - dis(j, j - 1)][1] + bonus);
					ans = max(ans, dp[i][j][t][1]);
				}
				if (t - dis(i, j) > 0) {
					dp[i][j][t][1] = max(dp[i][j][t][1], dp[i][j - 1][t - dis(i, j)][0] + bonus);
					ans = max(ans, dp[i][j][t][1]);;
				}
			}
		}
	}
	cout << ans;
}
