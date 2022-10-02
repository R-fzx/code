#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("dandelion.in","w", stdout);
    srand(114514);
    int n = 40000;
    cout << n << ' ' << 50000 << endl;
    for (int i = 1; i <= n; i++) cout << rand() % 1000 + 1 << ' ';
    cout << endl;
    for (int i = 1; i <= 50000; i++) {
        int l = rand() % n + 1, r = rand() % n + 1;
        cout << l << ' ' << r << endl;
    }
    return 0;
}