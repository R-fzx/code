#include <bits/stdc++.h>
#define in(x, y) ((2 <= (x)) && ((x) <= (n - 1)) && (2 <= (y)) && ((y) <= (m - 1)))
using namespace std;
const int N = 100 + 10;
int T = 10;
int n = 100, m = 100;
char mp[N][N];

int main() {
    freopen("maze2.in", "w", stdout);
    srand(time(NULL));
    printf("%d\n", T);
    while (T--) {
        printf("%d %d %d\n", rand() % (8 * n) + n + m, n, m);
        // memset(mp, '#', sizeof(mp));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) mp[i][j] = '#';
        }
        
        // for (int i = 1; i <= 100; i++) {
        //     int x = rand() % 100 + 1, y = rand() % 100 + 1;
        //     mp[x][y] = '#';
        // }

        mp[2][2] = 'S';
        mp[n - 1][m - 1] = 'E';

        for (int t = 1; t <= 10; t++) {
            int nx = 2, ny = 2;
            while ((nx < n - 1) || (ny < m - 1)) {
                bool k = (bool)(rand() % 3);
                if (T % 2) k = !k;
                if (nx == n - 1) ++ny;
                else if (ny == m - 1) ++nx;
                else if (k) ++nx;
                else ++ny;
                if (mp[nx][ny] == '#') mp[nx][ny] = ' ';
            }
        }

        for (int i = 1; i <= n; i++) {
            printf("%s\n", mp[i] + 1);
        }       
    }
    
}