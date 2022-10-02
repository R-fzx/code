#include<bits/stdc++.h>
using namespace std;
const int maxn = 40005, maxb = 205;
int n, m, block, t;
int a[maxn], ind[maxn];
int st[maxb], ed[maxb], pos[maxn];
int s[maxb][maxn];
int f[maxb][maxb];
int cnt[maxn];
int k[maxn];
int lst;
void discrete() {
    memcpy(ind, a, sizeof(a)); sort(ind + 1, ind + 1 + n);
    int len = unique(ind + 1, ind + 1 + n) - ind - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(ind + 1, ind + 1 + len, a[i]) - ind;
}
void init() {
    block = sqrt(n); t = ceil(n * 1. / block);
    for (int i = 1; i <= t; i++) {
        st[i] = (i - 1) * block + 1; ed[i] = min(i * block, n);
        for (int j = st[i]; j <= ed[i]; j++) pos[j] = i;
    }
    for (int i = 1; i <= t; i++) {
        memset(cnt, 0, sizeof(cnt));
        int x = 0;
        for (int j = i; j <= t; j++) {
            for (int k = st[j]; k <= ed[j]; k++) {
                cnt[a[k]]++;
                if (cnt[a[k]] > cnt[x]) x = a[k];
                else if (cnt[a[k]] == cnt[x]) x = min(x, a[k]);
            }
            f[i][j] = x;
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= t; i++) {
        for (int j = st[i]; j <= ed[i]; j++) cnt[a[j]]++;
        for (int j = 1; j <= n; j++) s[i][j] = cnt[j];
    }
}
int query(int l, int r) {
    int p = pos[l], q = pos[r];
    if (p + 1 >= q) {
        int x = 0;
        for (int i = l; i <= r; i++) {
            k[a[i]]++;
            if (k[a[i]] > k[x]) x = a[i];
            else if (k[a[i]] == k[x]) x = min(x, a[i]);
        }
        for (int i = l; i <= r; i++) k[a[i]]--;
        return x;
    }
    for (int i = l; i <= ed[p]; i++) k[a[i]]++;
    for (int i = st[q]; i <= r; i++) k[a[i]]++;
    int x = f[p + 1][q - 1];
    int res = k[x] + s[q - 1][x] - s[p][x];
    for (int i = l; i <= ed[p]; i++) {
        int sum = k[a[i]] + s[q - 1][a[i]] - s[p][a[i]];
        if (res < sum) x = a[i], res = sum;
        else if (res == sum) x = min(x, a[i]);
    }
    for (int i = st[q]; i <= r; i++) {
        int sum = k[a[i]] + s[q - 1][a[i]] - s[p][a[i]];
        if (res < sum) x = a[i], res = sum;
        else if (res == sum) x = min(x, a[i]);
    }
    for (int i = l; i <= ed[p]; i++) k[a[i]]--;
    for (int i = st[q]; i <= r; i++) k[a[i]]--;
    return x;
}
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
    return x * f;
}
int main() {
    freopen("dandelion.in", "r", stdin);
    freopen("dandelion.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = read();
    discrete();
    init();
    for (int i = 1; i <= m; i++) {
        int l, r; l = read(); r = read();
        l = (l + lst - 1) % n + 1; r = (r + lst - 1) % n + 1;
        if (l > r) swap(l, r);
        printf("%d\n", lst = ind[query(l, r)]);
    }
    return 0;
}