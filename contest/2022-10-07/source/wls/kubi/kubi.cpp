#include <bits/stdc++.h>
#define int long long
#define println(x) print(x), putchar('\n')
#define printsp(x) print(x), putchar(' ')
#define printpa(x, y) printsp(x), println(y)
using namespace std;
const int N = 1e5 + 10;
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
int T;
int a, b, k;
unordered_map<int, int> mp;
signed main() {
    freopen("kubi.in", "r", stdin);
    freopen("kubi.out", "w", stdout);
    T = read();
    while (T--) {
        mp.clear();
        a = read(), b = read(), k = read();
        int ans1 = 0, ans2 = 0;
        int cnt = 0;
        bool flag = 0;
        while (a) {
            if (mp.count(a)) {
                ans1 = mp[a] - 1;
                ans2 = cnt - mp[a] + 1;
                flag = 1;
                break;
            }
            mp[a] = ++cnt;
            int p = (k * a / b);
            a = k * a - p * b;
        }
        if (flag) printpa(ans1, ans2);
        else printpa(cnt, 0);
    }
    return 0;
}
/*
-1
26357 95473 10
*/