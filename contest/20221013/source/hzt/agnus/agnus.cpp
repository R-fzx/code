#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const string t = "agnus";
const int N = 3e4 + 5;

int l, ans, a[N];
int ls;
string s;

bool C (int x) {
    for (int i = x, j = 0; j <= 4; i++, j++) {
        if (i == l || s[i] != t[j]) {
            return 0;
        }
    }
    return 1;
}

int main () {
    freopen("agnus.in", "r", stdin);
    freopen("agnus.out", "w", stdout);
    cin >> s;
    l = s.size();
    for (int i = 0; i < l; i++) {
        a[i] = C(i);
    }
    ls = l;
    for (int i = l; i >= 0; i--) {
        if (a[i] == 0) {
            continue;
        }
        int a = i + 1, b = ls - i - 4;
        ans += a * b; 
        ls = i + 4;
    }
    cout << ans;
    return 0;
}