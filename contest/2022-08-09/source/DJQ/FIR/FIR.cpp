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
int Chess[maxn][maxn], tot, Vst[maxn][maxn], go[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
pair <int, int> Way[maxn * maxn];
inline bool Search(int sx, int sy) {
	queue < pair<int, int> > Q;
	for(register int i = 1; i <= tot; ++i) Vst[Way[i].first][Way[i].second] = 0;
	int flag = 0; tot = 0;
	Q.push(make_pair(sx, sy)), Vst[sx][sy] = 1, Way[++tot] = make_pair(sx, sy);
	while(!Q.empty()) {
		int x = Q.front().first, y = Q.front().second; Q.pop();
		for(register int i = 0; i < 4; ++i) {
			int nx = x + go[i][0], ny = y + go[i][1];
			if(Vst[nx][ny]) continue;
			if(!Chess[nx][ny]) { flag = 1; break; }
			if(Chess[nx][ny] == Chess[sx][sy]) Q.push(make_pair(nx, ny)), Way[++tot] = make_pair(nx, ny), Vst[nx][ny] = 1;
		}
		if(flag) break;
	}
	return flag;
}
inline bool Check_Point(int x, int y, int op) {
	if(Chess[x][y]) return 0;
	Chess[x][y] = op + 1;
	if((Chess[x - 1][y] - 1) == ((Chess[x][y] - 1) ^ 1)) {
		if(!Search(x - 1, y)) 
			for(register int i = 1; i <= tot; ++i) Chess[Way[i].first][Way[i].second] = 0;
	}
	if((Chess[x][y - 1] - 1) == ((Chess[x][y] - 1) ^ 1)) {
		if(!Search(x, y - 1))
			for(register int i = 1; i <= tot; ++i) Chess[Way[i].first][Way[i].second] = 0;
	}
	if((Chess[x + 1][y] - 1) == ((Chess[x][y] - 1) ^ 1)) {
		if(!Search(x + 1, y))
			for(register int i = 1; i <= tot; ++i) Chess[Way[i].first][Way[i].second] = 0;
	}
	if((Chess[x][y + 1] - 1) == ((Chess[x][y] - 1) ^ 1)) {
		if(!Search(x, y + 1))
			for(register int i = 1; i <= tot; ++i) Chess[Way[i].first][Way[i].second] = 0;
	}
	if(!Search(x, y)) return 0;
	return 1;
}
inline bool Check_Ans(int x, int y) {
	int nx = max(1, x - m + 1), ny = max(1, y - m + 1);
	int Cntx = x - nx, Cnty = y - ny, Cnt = min(Cntx, Cnty);

	for(register int i = nx; i <= x; ++i) {
		int flag = 1;
		for(register int j = 1; j <= m; ++j)
			if(Chess[i + j - 1][y] != Chess[x][y]) { flag = 0; break; }
		if(flag) return 1; 
	}
	for(register int i = ny; i <= y; ++i) {
		int flag = 1;
		for(register int j = 1; j <= m; ++j)
			if(Chess[x][i + j - 1] != Chess[x][y]) { flag = 0; break; }
		if(flag) return 1;
	}
	for(register int i = Cnt; i >= 0; --i) {
		int flag = 1;
		for(register int j = 1; j <= m; ++j)
			if(Chess[x - i + j - 1][y - i + j - 1] != Chess[x][y]) { flag = 0; break; }
		if(flag) return 1; 
	}
	Cnt = Cntx;
	for(register int i = Cnt; i >= 0; --i) {
		int flag = 1;
		for(register int j = 1; j <= m; ++j)
			if(y + i - j + 1 < 1 || Chess[x - i + j - 1][y + i - j + 1] != Chess[x][y]) { flag = 0; break; }
		if(flag) return 1; 
	}
	return 0;
}
int main() {
	freopen("FIR.in", "r", stdin);
	freopen("FIR.out", "w", stdout);
	n = read(), m = read();
	for(register int i = 1; i <= n; ++i) {
		int x = read(), y = read();
		if(!Check_Point(x, y, i & 1)) { printf("illegal\n"); return 0; }
		if(Check_Ans(x, y)) { 
			if(i & 1) printf("ITer ");
			else printf("Kitty ");
			printf("%d\n", i); return 0;
		}
	}
	printf("draw\n");
	return 0;
}