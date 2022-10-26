#include<btis/stdc++.h>
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
const int maxn = 25, maxS = (1 << 21), maxm = 65;
int n, maxx;
int a[maxn], f[maxm][maxS][2], num[maxm][maxn], Cnt[maxn];
int main() {
	n = read();
	for(register int i = 1; i <= n; ++i) {
		a[i] = read();
		int tot = 0, x = a[i];
		while(x) {
			num[++tot] = (x & 1);
			x >>= 1;
		}
		maxx = max(maxx, tot);
	}
	for(register int i = 1; i <= maxx; ++i)
		for(register int j = 0; j < (1 << n); ++j) {
			int Cnt0 = 0;
			for(register int k = 1; k <= n; ++k) {
				Cnt[k] = (num[i][k] + (j & (1 << (k - 1)))) & 1;
				Cnt0 += (Cnt[k] ^ 1);
			}
			f[i + 1][k] = (f[i + 1])
		} 
	return 0;
} 
 
