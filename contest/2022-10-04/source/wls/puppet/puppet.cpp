#include <bits/stdc++.h>
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 1e2 + 10, M = 1e3 + 10;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int n, a[N];
int cnt[M];
signed main() {
    freopen("puppet.in", "r", stdin);
    freopen("puppet.out", "w", stdout);
    int seed = 0;
    mt19937 rnd(seed = 1664855793);
    srand(seed);
    println(seed);
    int cc = 0;
    while (~scanf("%d", &n)) {
        int sum = 0;
        ++cc;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) a[i] = read(), cnt[a[i]]++;//, sum += cnt[a[i]];
        int maxn = 0;
        while (clock() <= 50 * cc) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 1; i <= n; i++) cnt[a[i]]++;
            shuffle(a + 1, a + n + 1, rnd);
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt[a[i] - 1] || cnt[a[i]] || cnt[a[i] + 1]) {
                    int m1 = (n - cnt[a[i] - 1] + 1) + (n - cnt[a[i]] + 1) + (n - cnt[a[i] + 1] + 1);
                    // println(m1);
                    int num = rand() % m1 + 1;
                    num -= (n - cnt[a[i] - 1] + 1);
                    if (num <= 0) { cnt[a[i] - 1]--; continue; }
                    num -= (n - cnt[a[i]] + 1);
                    if (num <= 0) { cnt[a[i]]--; continue; }
                    num -= (n - cnt[a[i] + 1] + 1);
                    if (num <= 0) { cnt[a[i] + 1]--; continue; }
                } else ans++;
            }
            // for (int i = 1; i <= n; i++) {
            //     if (cnt[a[i] - 1] || cnt[a[i]] || cnt[a[i] + 1]) {
            //         int m1 = (bool)(cnt[a[i] - 1]) + (bool)(cnt[a[i]]) + (bool)(cnt[a[i] + 1]);
            //         int num = rand() % m1 + 1;
            //         num -= (bool)(cnt[a[i] - 1]);
            //         if (num <= 0) { cnt[a[i] - 1]--; continue; }
            //         num -= (bool)(cnt[a[i]]);
            //         if (num <= 0) { cnt[a[i]]--; continue; }
            //         num -= (bool)(cnt[a[i] + 1]);
            //         if (num <= 0) { cnt[a[i] + 1]--; continue; }
            //     } else ans++;
            // }
            maxn = max(maxn, ans);
        }
        printf("%d\n", maxn);
    }
    return 0;
}