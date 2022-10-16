#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
char dit[maxn][maxn];
int x11, y11, x22, y22, ds[maxn * maxn], n, m;
struct E{
    int next, to, wz;
}e[maxn * maxn * 10];
int hd[maxn * maxn], l;
void add(int u, int v, int w) {
    l++;
    e[l].next = hd[u], e[l].to = v, e[l].wz = w, hd[u] = l;
}
struct _Wall{
    int x,y;
} Wall[10];
struct kkk{
    int x, w;
    bool operator < (const kkk & a) const {
        return w > a.w;
    }
};
int Loss[7][7] = {{1,0},{-1,0},{0,1},{0,-1}};
int Vis[maxn * maxn];
void dij() {
    priority_queue<kkk> que;
    memset(ds, 0x3f, sizeof(ds));
    ds[(x11 - 1) * n + y11] = 0;
    que.push((kkk){(x11 - 1) * n + y11, 0});
    while(!que.empty()) {
        int x = que.top().x;
        que.pop();
        if(Vis[x]) continue;
        Vis[x] = 1;
        for(int i = hd[x]; i; i = e[i].next) {
            int y = e[i].to;
            if(ds[x] + e[i].wz < ds[y]) {
                ds[y] = ds[x] + e[i].wz;
                if(!Vis[y])que.push((kkk) {y, ds[y]});
            }
        }
    }
}
int main() {
    freopen("portal.in","r",stdin);
    freopen("portal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
        	cin >> dit[i][j];
            if(dit[i][j] == 'C') {
                x11 = i, y11 = j;
            }
            if(dit[i][j] == 'F') {
                x22 = i, y22 = j;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int From = (i - 1) * n + j;
            if(dit[i][j] != '#') {
                int x = i, y = j;
                int tx = x, ty = y, d = 10000;
                while(dit[tx][ty] != '#') tx--;
                Wall[1].x = tx, Wall[1].y = ty;
                d = min(d, x - tx);
                tx = x,ty = y;
                while(dit[tx][ty] != '#') tx++;
                Wall[2].x = tx, Wall[2].y = ty;
                d = min(d, tx - x);
                tx = x, ty = y;
                while(dit[tx][ty] != '#') ty--;
                Wall[3].x = tx, Wall[3].y = ty;
                d = min(d, y - ty);
                tx = x, ty = y;
                while(dit[tx][ty] != '#') ty++;
                Wall[4].x = tx, Wall[4].y = ty;
                d = min(d, ty - y);
                for(int k = 1; k <= 4; k++) {
                    int to = (Wall[k].x - 1 + Loss[k - 1][0]) * n + Wall[k].y + Loss[k - 1][1];
                    add(From,to,d);
                }
                for(int k = 0; k < 4; k++) {
                    int tx = i + Loss[k][0],ty = j + Loss[k][1];
                    if(tx < 1 || tx > n || ty < 1 || ty > m || dit[tx][ty] == '#') continue;
                    int to = (tx - 1) * n + ty;
                    add(From, to, 1);
                }
            }
        }
    }
    dij();
    if(ds[(x22 - 1) * n + y22] != 0x3f3f3f3f)
    cout << ds[(x22 - 1) * n + y22];
    else cout << "nemoguce";
    return 0;
}
