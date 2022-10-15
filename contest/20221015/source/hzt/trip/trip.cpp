#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using pr = pair<int, int>;

const int N = 5e4 + 5;
const int inf = 0x3f3f3f3f;

int n, m, k, l;
int dis[N], v[N], p[N];
int s, t;
bool f[N];

vector<pr> e[N];
queue<int> q;

void SPFA (int x) {
    fill(dis, dis + n + 1, -inf);
    dis[x] = inf;
    q.push(x);
    f[x] = 1;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        f[a] = 0;
        for (auto i : e[a]) {
            int y = i.first;
            int w = min(dis[a], (int)floor(i.second / 200.0 * (v[p[a]] + v[p[y]])));
            if (w > dis[y]) {
                dis[y] = w;
                if (f[y] == 0) {
                    f[y] = 1;
                    q.push(y);
                }
            }
        }
    }
}

void SPFA2 (int x) {
    fill(dis, dis + n + 1, inf);
    dis[x] = 0;
    q.push(x);
    f[x] = 1;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        f[a] = 0;
        for (auto i : e[a]) {
            int y = i.first;
            double w = i.second / 200.0 * (v[p[a]] + v[p[y]]);
            int r = max((int)ceil(w), dis[a]);
            if (w > l && r < dis[y]) {
                dis[y] = r;
                if (f[y] == 0) {
                    f[y] = 1;
                    q.push(y);
                }
            }
        }
    }
}

int main () {
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    for (int i = 1; i <= k; i++) {
        int l;
        cin >> l;
        n += l;
        for (int j = 1; j <= l; j++) {
            int x;
            cin >> x;
            p[x] = i;
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> v[i];
    }
    cin >> s >> t;
    SPFA(s);
    l = dis[t];
    SPFA2(s);
    cout << l << ' ' << dis[t];
    return 0; 
}