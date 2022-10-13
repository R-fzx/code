#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const G = 1000, N = G * G;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 }, n, m, gr[G][G];
vector<pair<int, int> > g[N];
char s[G][G + 1];
bool vis[G][G], visg[N];

inline bool basec(char c){
	if (c == '.')return true;
	if (c >= '0' && c <= '9')return true;
	return false;
}

int l, r, up, dn;
void base(int x, int y){
	vis[y][x] = true;
	l = min(l, x);
	r = max(r, x);
	up = min(up, y);
	dn = max(dn, y);
	f(i, 0, 4){
		int a = x + dx[i], b = y + dy[i];
		if (a == -1 || a == m || b == -1 || b == n || !basec(s[b][a]) || vis[b][a])continue;
		base(a, b);
	}
}

inline void rs() { l = up = 1e9, r = dn = -1e9; }

struct B{
	int l, r, up, dn;
	B(){}
	void bld(int id){
		l = ::l;
		r = ::r;
		up = ::up;
		dn = ::dn;
		f(j, up - 1, dn + 2)f(i, l - 1, r + 2)gr[j][i] = id;
	}
}bs[N];

inline int intln(int x){
	int an = 0;
	while (x){
		++an;
		x /= 10;
	}
	return an;
}

pair<int, int> go(int x, int y, int d = 2){
	int a = x + dx[d], b = y + dy[d];
	if (!(d & 2) && s[b][a] == '|')return make_pair(y, gr[y][a]);
	if (s[b][a] == '+'){
		x = a, y = b;
		d ^= 2;
		a = x + dx[d], b = y + dy[d];
		if (b >= 0 && b < n && a >= 0 && a < n && s[b][a] != '.')return go(a, b, d);
		else {
			d ^= 1;
			a = x + dx[d], b = y + dy[d];
			return go(a, b, d);
		}
	}
	return go(a, b, d);
}

void fn(int v = 1){
	if (visg[v])return;
	visg[v] = true;
	sort(g[v].begin(), g[v].end());
	reverse(g[v].begin(), g[v].end());
	f(i, 0, g[v].size()){
		int u = g[v][i].second;
		fn(u);
	}
	printf("%d\n", v);
}

int main(){
	freopen("clickbait.in","r",stdin);
	freopen("clickbait.out","w",stdout); 
	
	scanf("%d%d", &n, &m);
	f(i, 0, n)scanf("%s", s[i]);
	int k = 0;
	f(i, 0, n)f(j, 0, m){
		if (s[i][j] >= '0' && s[i][j] <= '9'){
			int t;
			sscanf(s[i] + j, "%d", &t);
			rs();
			base(j, i);
			bs[t].bld(t);
			j += intln(t) - 1;
			k = max(k, t);
		}
	}
	f(i, 2, k + 1){
		f(j, bs[i].l, bs[i].r + 1)if (s[bs[i].up - 2][j] == '|'){
			pair<int, int> t = go(j, bs[i].up - 2);
			g[t.second].push_back(make_pair(t.first, i));
		}
	}
	fn();
}
