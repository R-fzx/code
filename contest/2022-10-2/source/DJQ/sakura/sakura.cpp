#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
const int maxn = 1e6 + 5, mod = 1e9 + 7;
int n;
int Prime[maxn], Vst[maxn], tot, Cnt[maxn], Answer;
inline void Get_Prime() {
	for(register int i = 2; i <= n; ++i) {
		if(!Vst[i]) Prime[++tot] = i;
		for(register int j = 1; j <= tot && i * Prime[j] <= n; ++j) {
			Vst[i * Prime[j]] = 1;
			if(i % Prime[j] == 0) break;
		}
	}
}
inline void Work() {
	for(register int i = 1; i <= tot; ++i) {
		int x = n;
		while(x) Cnt[i] += (x / Prime[i]), x /= Prime[i];
	}
	Answer = 1;
	for(register int i = 1; i <= tot; ++i) Answer = Answer * ((Cnt[i] << 1) + 1) % mod;
}
signed main() {
	freopen("sakura.in", "r", stdin);
	freopen("sakura.out", "w", stdout);
	n = read();
	Get_Prime(), Work();
	printf("%lld\n", Answer); 
	return 0;
}
