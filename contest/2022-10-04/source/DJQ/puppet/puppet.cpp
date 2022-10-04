#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) {
		if(c == EOF) return -1;
		f |= (c == '-'), c = getchar();
	}
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
const int maxn = 55;
int n, a[maxn], f[maxn], g[maxn][maxn];
int main() {
	freopen("puppet.in", "r", stdin);
	freopen("puppet.out", "w", stdout);
	while(~(n = read())) {
		for(register int i = 1; i <= n; ++i) a[i] = read();
		sort(a + 1, a + n + 1);
		memset(g, 0, sizeof(g));
		memset(f, 0, sizeof(f));
		for(register int i = 1; i <= n; ++i)
			for(register int j = i; j <= n; ++j) {
				for(register int k = 1; i + k - 1 <= j; ++k) {
					int flag = 1;
					for(register int p = 0; i + p + k <= j; ++p)
						if(a[i + k + p] - a[i + p] > 1) { flag = 0; break; }
					if(abs(a[j - k + 1] - a[i + k - 1]) <= 1) flag = 0;
					if(!flag) break;
					g[i][j] = k;
				}
			}
		for(register int i = 1; i <= n; ++i)
			for(register int j = 0; j < i; ++j) f[i] = max(f[i], f[j] + g[j + 1][i]);
		printf("%d\n", f[n]); 
	}
	return 0;
}
