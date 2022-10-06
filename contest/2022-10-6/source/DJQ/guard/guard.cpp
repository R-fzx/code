#include<bits/stdc++.h>
#define f(i, j, k) f[i][min(j, n) + 201][k]
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
const int maxn = 205;
int n, L, K;
int Val[maxn];
double p[maxn], f[maxn][maxn << 1][maxn], Answer;
int main() {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	n = read(), L = read(), K = read();
	for(register int i = 1; i <= n; ++i) {
		int x = read();	
		p[i] = (double) x / 100.0; 
	}
	for(register int i = 1; i <= n; ++i) Val[i] = read();
	f(0, K, 0) = 1.0;
	for(register int i = 0; i <= n; ++i)
		for(register int j = -1 * i; j <= n; ++j)
			for(register int k = 0; k <= i; ++k) {
				f(i + 1, j + Val[i + 1], k + 1) += p[i + 1] * f(i, j, k);
				f(i + 1, j, k) += (1.0 - p[i + 1]) * f(i, j, k);
			}
	for(register int i = 0; i <= n; ++i)
		for(register int j = L; j <= n; ++j) Answer += f(n, i, j);
	printf("%0.6lf", Answer);
	return 0;
} 
