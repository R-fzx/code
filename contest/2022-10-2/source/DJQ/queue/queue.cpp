#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x; 
}
const int maxn = 1005;
int n;
int ls[maxn], h[maxn], num[maxn], S;
double Frac[maxn], Cnt, Answer;
inline void Ready() {
	Frac[0] = 1.0;
	for(register int i = 1; i <= n; ++i) Frac[i] = Frac[i - 1] * i;
}
inline int A(int x, int y) { return Frac[x] / Frac[x - y]; }
signed main() {
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	n = read();
	Ready();
	for(register int i = 1; i <= n; ++i) h[i] = read();
	for(register int i = 1; i <= n; ++i) num[h[i]]++;
	for(register int i = 0; i <= 1000; ++i) Answer += 1.0 * num[i] * (n + 1) / (n - S + 1), S += num[i]; 
	printf("%0.2lf\n", Answer);
	return 0;
}
