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
const int maxn = 55;
int n, m;
char S[maxn];
int C[maxn][maxn], num[maxn], Answer;
inline void Ready() {
	for(register int i = 0; i <= n; ++i) C[i][0] = 1;
	for(register int i = 1; i <= n; ++i)
		for(register int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	int P = 1, Sum = 0;
	for(register int i = 1; i < 10; Sum += num[i], ++i) P *= C[m - Sum][num[i]];
	for(register int i = m; i < n; ++i) Answer += P * C[i - 1][m - 1];
}
inline void Calc() {
	for(register int i = 1; i <= n; ++i) {
		int x = S[i] ^ 48, P, Sum, len = n - i;
		if(!x) { num[x]--; continue; }
		for(register int j = (i == 1 ? 1 : 0); j < x; ++j)
			if(num[j]) {
				num[j]--, P = 1, Sum = 0;
				for(register int k = 0; k < 10; Sum += num[k], ++k) P *= C[len - Sum][num[k]];
				num[j]++, Answer += P;
			}
		num[x]--; 
	}
}
signed main() {
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
	scanf("%s", S + 1);
	n = strlen(S + 1);
	for(register int i = 1; i <= n; ++i) num[S[i] ^ 48]++, m += (S[i] != 48);
	Ready(), Calc();
	printf("%lld\n", Answer);
	return 0;
}

