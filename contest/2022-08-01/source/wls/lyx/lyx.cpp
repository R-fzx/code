#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, m;
vector<int> G[N];
int ind[N], outd[N];
int cnt = 0;
// void dfs(int u) {
//     if (ind[u] == 0) {
//         cnt++;
//         return;
//     }
//     for (int i = 0; i < G[u].size(); i++) {
//         dfs(G[u][i]);
//     }
// }
void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (outd[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (ind[u] == 0) {
            if(outd[u]) cnt++;
            continue;
        }
        for (int i = 0; i < G[u].size(); i++) {
            q.push(G[u][i]);
        }
    }
}
signed main() {
    freopen("lyx.in", "r", stdin);
    freopen("lyx.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        G[v].push_back(u);
        ind[v]++, outd[u]++;
    }
    // for (int i = 1; i <= n; i++) {
    //     if (outd[i] == 0) {
    //         dfs(i);
    //     }
    // }
    bfs();
    printf("%d\n", cnt);
    return 0;
}
/*
10 16
1 2
1 4
1 10
2 3
2 5
4 3
4 5
4 8
6 5
7 6
7 9
8 5
9 8
10 6
10 7
10 9
*/
