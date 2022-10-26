#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("h.in", "w", stdout);
    mt19937 rnd(time(0));
    int n = 200000;
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << n - i << ' ';
    cout << endl;
    return 0;
}