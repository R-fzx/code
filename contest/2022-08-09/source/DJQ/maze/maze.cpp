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
const int maxn = 25;
int n, m, x;
int A[maxn][maxn];
map <int, int> f[maxn][maxn];
vector <int> Vec[maxn][maxn];
signed main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
	n = read(), m = read(), x = read();
	for(register int i = 1; i <= n; ++i)
		for(register int j = 1; j <= m; ++j) A[i][j] = read();
	f[1][1][A[1][1]] = 1, Vec[1][1].push_back(A[1][1]);
    for(register int i = 1; i <= n; ++i)
        for(register int j = 1; j <= m; ++j) {
            int Siz;
            if((i == 1 && j == 1) || !A[i][j]) continue;
            if(A[i - 1][j]) {
                Siz = Vec[i - 1][j].size();
                for(register int k = 0; k < Siz; ++k) {
                    if(!f[i][j][Vec[i - 1][j][k] ^ A[i][j]]) Vec[i][j].push_back(Vec[i - 1][j][k] ^ A[i][j]);
                    f[i][j][Vec[i - 1][j][k] ^ A[i][j]] += f[i - 1][j][Vec[i - 1][j][k]];
                }
            }
            if(A[i][j - 1]) {
                Siz = Vec[i][j - 1].size();
                for(register int k = 0; k < Siz; ++k) {
                    if(!f[i][j][Vec[i][j - 1][k] ^ A[i][j]]) Vec[i][j].push_back(Vec[i][j - 1][k] ^ A[i][j]);
                    f[i][j][Vec[i][j - 1][k] ^ A[i][j]] += f[i][j - 1][Vec[i][j - 1][k]];
                }
            }
        }
    printf("%lld\n", f[n][m][x]);
	return 0;
}