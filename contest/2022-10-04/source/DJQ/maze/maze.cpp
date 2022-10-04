#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

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
const int maxn = 105, INF = 1e9 + 7;
const double eps = 1e-7;
int T;
double X, Dist[maxn][maxn];
int n, m;
int a[maxn][maxn], sx, sy, ex, ey;
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, Vst[maxn][maxn];
inline double Dijstra(double V) {
	priority_queue < pair<int, pair<int, int> > > Q;
	Q.push(make_pair(0, make_pair(sx, sy))), Dist[sx][sy] = 0.0;
	while(!Q.empty()) {
		int x = Q.top().second.first, y = Q.top().second.second;
		Q.pop();
		if(Vst[x][y]) continue;
		Vst[x][y] = 1;
		if(x == ex && y == ey) { return Dist[x][y]; }
		for(register int i = 0; i < 4; ++i) {
			int nx = x + go[i][0], ny = y + go[i][1];
			if(x < 1 || y < 1 || x > n || y > m || Vst[nx][ny] || !a[nx][ny]) continue;
			if(Dist[nx][ny] > Dist[x][y] + (i < 2 ? V : 1)) {
				Dist[nx][ny] = Dist[x][y] + (i < 2 ? V : 1);
				Q.push(make_pair(-Dist[nx][ny], make_pair(nx, ny)));
			}
		}
	}
	return INF;
}
inline bool Check(double V) {
	for(register int i = 1; i <= n; ++i)
		for(register int j = 1; j <= m; ++j) Vst[i][j] = 0, Dist[i][j] = INF;
	return Dijstra(V) <= X; 
}
inline void Erfen() {
	double L = 0.0, R = 10.0;
	while(L + eps < R) {
		double mid = (L + R) / 2.0;
		if(Check(mid)) L = mid + eps;
		else R = mid - eps;
	}
	printf("%0.5lf\n", L);
}
int main() {
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	T = read();
	while(T--) {
		scanf("%lf", &X), n = read(), m = read();
		memset(a, 0, sizeof(a));
		for(register int i = 1; i <= n; ++i)
			for(register int j = 1; j <= m; ++j) {
				char c;
				while(!isalpha(c = getchar()) && c != ' ' && c != '#');
				if(c == 'S') sx = i, sy = j;
				if(c == 'E') ex = i, ey = j;
				if(c == '#') a[i][j] = 0;
				else a[i][j] = 1;
			}	
		Erfen();
	}
	return 0;
}
