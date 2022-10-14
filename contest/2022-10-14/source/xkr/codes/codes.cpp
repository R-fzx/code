#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    long long ans = 0;
    for (int i = 0; i < (1 << 20); i++) {
        int res = 0;
        for (int j = 0; j < 20; j++)
            if ((i >> j) & 1) res++;
        ans += (1ll << res);
    }
    cout << ans << endl;
    cout << (1ll << 40) << endl;
    return 0;
}