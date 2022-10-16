#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 2005;
const int maxt = 2000;

int n, s, m, w;
int f[N][N][M][2];

struct D {
    int x, v, t;
} a[N];

bool Cmp (D a, D b) {
    return a.x < b.x;
}

int V (int x, int t) {
    if (t <= a[x].t) {
        return a[x].v;
    }
    return 0;
}

int D (int l, int r, int o, int x) {
    int y = a[l].x;
    if (o == 1) {
        y = a[r].x;
    }
    return abs(x - y);
}

void U (int l, int r, int t, int o, int x) {
    if (l >= 1 && r <= m && t <= maxt) {
        f[l][r][t][o] = max(f[l][r][t][o], x);
    }
}

int main () {
    freopen("go.in", "r", stdin);
    freopen("go.out", "w", stdout);
    memset(f, 0xc0, sizeof(f));
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].v >> a[i].t;
        a[i].t--;
    }
    sort(a + 1, a + m + 1, Cmp);
    for (int i = 1; i <= m; i++) {
        if (s >= a[i].x) {
            w = i;
        }
    }
    int t1 = abs(s - a[w].x), t2 = abs(s - a[w + 1].x);
    f[w][w][t1][0] = V(w, t1), f[w + 1][w + 1][t2][0] = V(w + 1, t2);
    for (int k = 1; k < m; k++) {
        for (int i = 1, j = k; j <= m; i++, j++) {
            for (int t = 0; t <= maxt; t++) {
                for (int p = 0; p < 2; p++) {
                    int Nt = t + D(i, j, p, a[i - 1].x);
                    U(i - 1, j, Nt, 0, f[i][j][t][p] + V(i - 1, Nt));
                    Nt = t + D(i, j, p, a[j + 1].x);
                    U(i, j + 1, Nt, 1, f[i][j][t][p] + V(j + 1, Nt));
                }
            }
        }
    }
    int ans = 0;
    for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {
            for (int t = 0; t <= maxt; t++) {
                for (int o = 0; o < 2; o++) {
                    ans = max(ans, f[l][r][t][o]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}