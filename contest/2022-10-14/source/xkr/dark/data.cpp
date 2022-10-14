#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("dark.in", "w", stdout);
    srand(time(0));
    int n = 200000;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int x = llabs(rand() * rand()) % 1000000 + 1;
        int y = llabs(rand() * rand()) % 1000000 + 1;
        cout << x << ' ' << y << endl;
    }
    return 0;
}