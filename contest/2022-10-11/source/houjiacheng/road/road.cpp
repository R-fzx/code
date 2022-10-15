# include <bits/stdc++.h>
# define ll  long long
# define inf 1000000001ll
# define N 50050

using namespace std;

int n, m;
ll p, q;
int f[220], cnt;

struct Edge {
  int u, v;
  ll a, b;
} e[N];

vector<Edge> et;

void initf() {
  cnt = n;
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
}

int fi(int x) {
  return f[x] == x ? x : f[x] = fi(f[x]);
}

ll ji(int x, int y, ll v) {
  int fx = fi(x), fy = fi(y);
  if (fx != fy) {
    f[fx] = fy;
    cnt--;
    return v;
  }
  return -1;
}

ll mst(int m) {
  ll re = 0, v;
  initf();
  for (int i = 0; i <  et.size(); i++) {
    v = ji(et[i].u, et[i].v, et[i].b);
    if (v == -1) {
      et[i].b = inf;
    } else {
      re = max(v, re);
    }
  }
  if (cnt == 1) {
    return re;
  }
  return -1;
}

bool cmp(Edge a, Edge b) {
  return a.a < b.a;
}

bool cmpb(Edge a, Edge b) {
  return a.b < b.b;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  scanf("%d%d%lld%lld", &n, &m, &p, &q);
  ll ans = -1;
  for (int i = 1, u, v, a, b; i <= m; i++) {
    scanf("%d%d%d%d", &u, &v, &a, &b);
    // printf(" %d %d %d %d\n", u, v, a, b);
    e[i].u = u, e[i].v = v, e[i].a = a, e[i].b = b;
    // printf(" %d %d %d %d\n", e[i].u, e[i].v, e[i].a, e[i].b);
  }
  sort(e + 1, e + 1 + m, cmp);
  ll A, ms;
  for (int i = 1; i <= m; i++) {
    A = e[i].a;
    et.push_back(e[i]);
    // for (int j = i; j > 1; j--) {
    //   if (e[j].b < e[j - 1].b) {
    //     swap(e[j].b,e[j - 1].b);
    //   } else {
    //     break;
    //   }
    // }
    sort(et.begin(), et.end(), cmpb);
    while (et.size() && et[et.size() - 1].b == inf) {
      et.pop_back();
    }
    ms = mst(i);
    if (ans == -1 && ms != -1) {
      ans = ms * q + A * p;
    } else {
      ans = min(ans, ms * q + A * p);
    }
  }
  printf("%lld", ans);
}
/*

5 6
5 10
1 3 10 15
2 4 6 4
1 5 2 3
1 4 3 2
1 4 2 3
2 4 2 1

*/