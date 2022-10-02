#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n;
int a[maxn];
int x[maxn];
stack<int> st;
int k[maxn];
double ans;
int main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) x[i] = i;
    do {
        for (int i = 1; i <= n; i++) k[i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i - 1; j >= 1; j--)
                if (a[x[j]] >= a[x[i]]) {k[i] = j; break;}
        for (int i = 1; i <= n; i++) ans += i - k[i];
    } while (next_permutation(x + 1, x + 1 + n));
    for (int i = 1; i <= n; i++) ans /= i;
    printf("%.2lf\n", ans);
    return 0;
}