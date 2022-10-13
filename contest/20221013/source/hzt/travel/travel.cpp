#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, al, ar, lp[N];
int dis[N];
bool f[N];

struct E {
    int x, l, r;
};

vector<E> e[N];
queue<int> q;

void SPFA (int v) {
    memset(dis, -1, sizeof(dis));
    q.push(1);
    dis[1] = 0x3f3f3f3f;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        f[x] = 0;
        for (auto i : e[x]) {
            int y = i.x, l = i.l, r = i.r;
            if (l <= v && r >= v && min(dis[x], r) > dis[y]) {
                dis[y] = min(dis[x], r);
                if (f[y] == 0) {
                    f[y] = 1;
                    q.push(y);
                }
            } 
        }
    }    
}

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        lp[i] = l;
        e[x].push_back({y, l, r});
        e[y].push_back({x, l, r});
    }
    for (int i = 1; i <= m; i++) {
        SPFA(lp[i]);
        int l = lp[i], r = dis[n];
        if ((r - l) > (ar - al) || (r - l) == (ar - al) && l < al) {
            al = l, ar = r;
        }
    }
    cout << (ar - al + 1) << '\n';
    for (int i = al; i <= ar; i++) {
        cout << i << ' ';
    }
    return 0;
}