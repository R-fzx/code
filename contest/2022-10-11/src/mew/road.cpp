#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#define conint const int
#define condou const double
#define conll const ll
#define clear(a, b)	memset(a, b, sizeof a)
#define fu(i, a, b)	for (int i = a; i <= b; i++)
#define fd(i, a, b)	for (int i = a; i >= b; i--)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

conint M = 50000 + 2;
conint N = 200 + 2;

int n, m, t, tot = 1;
ll p, q, mp, mq, ans = 999999999999999999LL;
int fa[N], cnt[N];
int start[N], to[M << 1], next[M << 1], l1[M << 1], l2[M << 1];
bool h[N]	;

struct st {
	int v, t;
	ll e1, e2;
}a[M];

int getfa(int id) {
	if (fa[id] == id)
		return id;
	else
		return fa[id] = getfa(fa[id]);
}

bool cmp(st t1, st t2) {
	return t1.e1 < t2.e1 || t1.e1 == t2.e1 && t1.e2 < t2.e2;
}

void graph(int x, int y, int z1, int z2) {
	next[++tot] = start[x];	to[start[x] = tot] = y;	l1[tot] = z1;	l2[tot] = z2;
	next[++tot] = start[y];	to[start[y] = tot] = x; l1[tot] = z1;	l2[tot] = z2;
}

void dfs(int id) {
	for (int i = start[id]; i; i = next[i])
		if (!h[to[i]]) {
			mp = max(mp, (ll)l1[i]);
			mq = max(mq, (ll)l2[i]);
			h[to[i]] = true;
			dfs(to[i]);
		}
}

void find(int id) {
	for (int i = start[id]; i; i = next[i])
		if (!cnt[to[i]]) {
			if (cnt[id] == -1)
				cnt[to[i]] = i;
			else if (l2[cnt[id]] > l2[i])
					cnt[to[i]] = cnt[id];
				else
					cnt[to[i]] = i;
			find(to[i]);
		}
}

void put() {
	if (ans < 999999999999999999LL)
		printf("%I64d\n", ans);
	else
		puts("-1");
}

void read() {
	scanf("%d%d%I64d%I64d", &n, &m, &p, &q);
	fu(i, 1, m)
		scanf("%d%d%I64d%I64d", &a[i].v, &a[i].t, &a[i].e1, &a[i].e2);
	fu(i, 1, n)
		fa[i] = i;
}

void delete_edge(int edge_id)
{
	for (int x = 1; x <= n; ++x) {
		if (start[x] == edge_id) {
			start[x] = next[start[x]]; return;
		}
		for (int e = start[x]; e; e = next[e])
			if (next[e] == edge_id) {
				next[e] = next[next[e]]; return;
			}
	}
}

void work() {
	sort(a + 1, a + m + 1, cmp);
	t = 1;
	fu(i, 1, m) {
		if (getfa(a[i].v) != getfa(a[i].t)) {
			t++;
			graph(a[i].v, a[i].t, a[i].e1, a[i].e2);
			fa[fa[a[i].v]] = fa[a[i].t];
		}
		else {
			clear(cnt, 0);
			cnt[a[i].v] = -1;
			find(a[i].v);
			int e = cnt[a[i].t];
			if (l2[e] > a[i].e2) {
				delete_edge(e);
				delete_edge(e ^ 1);
				graph(a[i].v, a[i].t, a[i].e1, a[i].e2);
			}
		}
		if (t == n) {
			clear(h, 0);
			mp = mq = 0;
			dfs(1);
			if (mp * p + mq * q < ans)
				ans = mp * p + mq * q;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);	freopen("road.out", "w", stdout);
	read();
	work();
	put();
	fclose(stdin);	fclose(stdout);	return 0;
}
