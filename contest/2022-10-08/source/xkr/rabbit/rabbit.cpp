#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int main() {
    freopen("rabbit.in", "r", stdin);
    freopen("rabbit.out", "w", stdout);
    cin >> n;
    ans = n * (n - 1) / 2;
    cout << ans << endl;
    return 0;
}