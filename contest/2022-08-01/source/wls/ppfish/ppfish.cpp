#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 5e3 + 10, L = 1e6 + 10, b = 137;
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, m;
char s[N][N];
char t[L];
ull Hash[N], pw[N];
ull getHash(int l, int r) {
    return Hash[r] - Hash[l - 1] * pw[r - l + 1];
}
unordered_map<ull, int> hashmp;

int cnt[N];
struct node {
    int cnt, i;
    bool operator < (node rhs) const {
        return cnt < rhs.cnt;
    }
} sc[N];
double p = 0.0; int k;
double dp[N][N][2]; // dp[i][j] str[i] in j forget
double ans[N];
double pp[N];
signed main() {
    freopen("ppfish.in", "r", stdin);
    freopen("ppfish.out", "w", stdout);
    n = read();
    pw[0] = 1;
    for (int i = 1; i <= n + 10; i++) pw[i] = pw[i - 1] * b;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        int x = strlen(s[i] + 1);
        ull sh = 0;
        for (int j = 1; j <= x; j++) sh = sh * b + s[i][j];
        hashmp[sh] = i;
    }
    scanf("%s", t + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= m; i++) Hash[i] = Hash[i - 1] * b + t[i];
    for (int l = 1; l <= m; l++) {
        for (int j = 1; j <= 20; j++) {
            int r = l + j - 1;
            int num = hashmp[getHash(l, r)];
            if (num) cnt[num]++;
        }
    }
    
    for (int i = 1; i <= n; i++) sc[i].cnt = cnt[i], sc[i].i = i;
    sort(sc + 1, sc + n + 1);
    int nn = 0, now = -1;
    for (int i = 1; i <= n; i++) {
        if (now != sc[i].cnt) {
            now = sc[i].cnt;
            nn++;
        }
    }
    scanf("%lf%d", &p, &k);
    pp[0] = 1.0;
    for (int i = 1; i <= n; i++) pp[i] = pp[i - 1] * p;
    // for (int j = 1; j <= k; j++) dp[1][j][0] = 1 - pow(p, j);
    // dp[1][1][0] = dp[1][1][1] = 1 - p;
    for (int i = 0; i <= nn; i++) dp[i][0][0] = 1, dp[i][0][1] = 0;
    for (int j = 0; j <= k; j++) dp[0][j][0] = dp[0][j][1] = pow(p, j);
    for (int i = 1; i <= nn; i++) {
        double res = 0.0;
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = 1.0 - ((1.0 - dp[i][j - 1][0]) + dp[i - 1][j - 1][1] * (1 - p));
            // dp[i][j][0] = dp[i][j - 1][0] + dp[i - 1][j - 1][1] * (1 - p);
            if (j >= i) res = res * p + dp[i - 1][j - 1][1] * (1.0 - p);
            dp[i][j][1] = res;
            // for (int l = i; l <= j; l++) dp[i][j][1] += dp[i - 1][l - 1][1] * (1.0 - p) * pp[j - l];
            // dp[i][j][1] = pow(p, j - 1) * (1 - p) * j;
        }
    }
    now = -1;
    int op = 0;
    for (int i = 1; i <= n; i++) {
        if (now != sc[i].cnt) {
            now = sc[i].cnt;
            ++op;
        }
        ans[sc[i].i] = dp[op][k][0];
    }
    // for (int i = 1; i <= n; i++) printf("%d ", sc[i].i);
    for (int i = 1; i <= n; i++) printf("%.3lf ", ans[i]);
    return 0;
}
