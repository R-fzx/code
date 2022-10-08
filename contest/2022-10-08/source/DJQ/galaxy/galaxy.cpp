#include<bits/stdc++.h>
#define int long long
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
const int maxn = 5;
int K, n, m, Ex, Ey;
map <int, int> Mapp;
int num[maxn][maxn], Maxx[maxn][maxn];
int go[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
inline int Hash() {
	int tot = 0;
	for(register int i = 0; i < 3; ++i)
		for(register int j = 0; j < 3; ++j) tot = tot * 10 + num[i][j];
	return tot;
}
inline int Search(int now) {
	if(now == 1) { return num[Ex][Ey] ? 1 : -1; }
	int State = Hash();
	if(Mapp[State]) return Mapp[State];
	for(register int x = 0; x < 3; ++x)
		for(register int y = 0; y < 3; ++y) {
			if(!num[x][y]) continue;
			for(register int i = 0; i < 8; ++i) {
				int nx = (x + go[i][0] + 3) % 3, ny = (y + go[i][1] + 3) % 3;
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || !num[nx][ny]) continue;
				int Nex_nx = (nx + go[i][0] + 3) % 3, Nex_ny = (ny + go[i][1] + 3) % 3;
				if(Nex_nx < 0 || Nex_ny < 0 || Nex_nx > n || Nex_ny > m || num[Nex_nx][Nex_ny] == Maxx[Nex_nx][Nex_ny]) continue;
				num[Nex_nx][Nex_ny]++, num[nx][ny]--, num[x][y]--;
				int tot = Search(now - 1);
				num[Nex_nx][Nex_ny]--, num[nx][ny]++, num[x][y]++;
				if(tot == 1) return Mapp[State] = 1;
			}
		}
	return Mapp[State] = -1;
}
signed main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	while(~(K = read())) {
		n = read(), m = read(), Ex = (read() - 1) % 3, Ey = (read() - 1) % 3;
		Mapp.clear();
		memset(num, 0, sizeof(num)), memset(Maxx, 0, sizeof(Maxx));
		for(register int i = 0; i < n; ++i)
			for(register int j = 0; j < m; ++j) Maxx[i % 3][j % 3]++;
		for(register int i = 1; i <= K; ++i) {
			int x = (read() - 1) % 3, y = (read() - 1) % 3;
			num[x][y]++;
		}
		if(Search(K) == 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
