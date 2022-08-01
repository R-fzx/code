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
int n, m;
int a[maxn][maxn];
inline void Search(int x, int y) {
	if(!x || !y) return ; 
	int minn = min(x, y);
	int sx = n - x + 1, sy = m - y + 1;
	int tot = 1;
	if(a[sx - 1][sy] == tot || a[sx][sy - 1] == tot) tot++;
	if(a[sx - 1][sy] == tot || a[sx][sy - 1] == tot) tot++;
	for(register int i = sx; i <= sx + minn - 1; ++i)
		for(register int j = sy; j <= sy + minn - 1; ++j)
			a[i][j] = tot;
	if(minn == x) Search(x, y - minn);
	else Search(x - minn, y);
}
int main() {
	freopen("chongjg.in", "r", stdin);
	freopen("chongjg.out", "w", stdout);
	n = read(), m = read();
	Search(n, m);
	for(register int i = 1; i <= n; ++i) {
		for(register int j = 1; j <= m; ++j) printf("%c", a[i][j] - 1 + 'A');
		printf("\n");
	}
	return 0;
}