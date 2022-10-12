#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1005, mod = (1ll << 31) - 1;
int n, m;
int dis[maxn];
bool p[maxn];
int f[maxn];
int ans = 1;
struct edge {int y, w;};
vector<edge> a[maxn];
struct node {
    int id, dis;
    bool operator < (const node &a) const {return dis > a.dis;}
};
void add(int x, int y, int w) {a[x].push_back((edge){y, w});}
priority_queue<node> q;
void dijkstra(int x, int k) {
    memset(f, 0, sizeof(f)); memset(p, 0, sizeof(p));
    if (!k)
        for (int i = 1; i <= n; i++) dis[i] = 1e9;
    dis[x] = 0; f[x] = 1;
    while (!q.empty()) q.pop();
    q.push((node){x, 0});
    while (!q.empty()) {
        int u = q.top().id; q.pop();
        if(p[u]) continue; p[u] = 1;
        for(int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].y;
            if(dis[v] >= dis[u] + a[u][i].w) {
                dis[v] = dis[u] + a[u][i].w;
                q.push((node){v, dis[v]});
                if(k == 1) f[v]++;
            }
        }
    }
}
signed main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        a[x].push_back((edge){y, w}); a[y].push_back((edge){x, w});
    }
    dijkstra(1, 0); dijkstra(1, 1);
    for (int i = 1; i <= n; i++) ans = ans * f[i] % mod;
    cout << ans << endl;
    return 0;
}