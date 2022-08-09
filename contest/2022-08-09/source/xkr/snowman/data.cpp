#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("snowman.in", "w", stdout);
    srand(114514);
    cout << 500000 << endl;
    for (int i = 1; i <= 500000; i++)
        cout << abs(rand() * rand()) % 100000000 + 1 << endl;
    return 0;
}