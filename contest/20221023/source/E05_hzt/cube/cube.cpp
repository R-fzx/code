#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n;
bool fl = 1;
ll ans;

struct D {
    int x0, x1, y0, y1, z0, z1;
} a[N]; 

int main () {
    freopen("cube.in", "r", stdin);
    freopen("cube.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x0 >> a[i].y0 >> a[i].z0 >> a[i].x1 >> a[i].y1 >> a[i].z1;
    }
    for (int x = -50; x <= 50; x++) {
        for (int y = -50; y <= 50; y++) {
            for (int z = -50; z <= 50; z++) {
                int cnt = 0;
                for (int i = 1; i <= n; i++) {
                    if (x < a[i].x0 || x > a[i].x1 || y < a[i].y0 || y > a[i].y1 || z < a[i].z0 || z > a[i].z1) {
                        cnt++;
                    } 
                    if (cnt == 2) {
                        break;
                    }
                    if (i == n) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}