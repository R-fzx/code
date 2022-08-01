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
const int maxn = 205, maxl = 1e6 + 5, maxm = 1005;
int n, k;
double p, f[maxn][maxm], Answer[maxn];
char s[maxn][25], T[maxl];
struct node {
	int link, len;
	int Ch[26];
}SAM[maxl * 3];
struct Point {
	int Val, Id;
}Count[maxn];
struct Map {
	int v, nex;
}edge[maxl * 3];
int head[maxl * 3], len;
int tot = 0, Last, Siz[maxn];
inline bool operator <(Point x, Point y) {
	return x.Val < y.Val;
}
inline void make_map(int u, int v) {
	len++;
	edge[len].nex = head[u];
	edge[len].v = v;
	head[u]=  len;
}
inline void Init() { SAM[1].len = SAM[1].link = 0, tot++, Last = 1; }
inline void Insert(int c) {
	int q = ++tot, p = Last; SAM[q].len = SAM[p].len + 1, Siz[q] = 1, Last = q;
	while(p && !SAM[p].Ch[c]) SAM[p].Ch[c] = q, p = SAM[p].link;
	if(!p) SAM[q].link = 1;
	else {
		int x = SAM[p].Ch[c];
		if(SAM[x].len == SAM[p].len + 1) SAM[q].link = x;
		else {
			int y = ++tot; 
			SAM[y].len = SAM[p].len + 1, SAM[y].link = SAM[x].link, SAM[x].link = SAM[q].link = y;
			memcpy(SAM[y].Ch, SAM[x].Ch, sizeof(SAM[x].Ch));
			while(p && SAM[p].Ch[c] == x) SAM[p].Ch[c] = y, p = SAM[p].link;
		}
	}
}
inline void Ready(int x) {
	for(register int i = head[x]; i; i = edge[i].nex) {
		int y = edge[i].v;
		Ready(y);
		Siz[x] += Siz[y];
	}
}
inline int Search(int Id) {
	int x = 1, Len = strlen(s[Id]);
	for(register int i = 0; i < Len; ++i)
		if(SAM[x].Ch[s[Id][i] - 'a']) x = SAM[x].Ch[s[Id][i] - 'a'];
		else return 0;
	return Siz[x];
}
int main() {
	freopen("ppfish.in", "r", stdin);
	freopen("ppfish.out", "w", stdout);
	n = read();
	for(register int i = 1; i <= n; ++i) scanf("%s", s[i]);
	scanf("%s", T);
	scanf("%lf", &p), p = 1.0 - p, k = read();
	int L = strlen(T); Init();
	for(register int i = 0; i < L; ++i) Insert(T[i] - 'a');
	for(register int i = 2; i <= tot; ++i) make_map(SAM[i].link, i);
	Ready(1);
	for(register int i = 1; i <= n; ++i) Count[i].Val = Search(i), Count[i].Id = i;
	sort(Count + 1, Count + n + 1);
	Count[0].Val = -1;
	f[0][0] = 1;
	for(register int i = 1; i <= n; ++i) {
		if(Count[i].Val == Count[i - 1].Val) { memcpy(f[i], f[i - 1], sizeof(f[i - 1])); continue; }
		for(register int j = 1; j <= k; ++j)
			f[i][j] = f[i][j - 1] * (1.0 - p) + f[i - 1][j - 1] * p;
	}
	for(register int i = 1; i <= n; ++i) {
		double Sum = 0;
		for(register int j = 1; j <= k; ++j) Sum += f[i][j];
		Answer[Count[i].Id] = 1.0 - Sum;
	}
	for(register int i = 1; i <= n; ++i) printf("%0.3lf ", Answer[i]);
	return 0;
}
