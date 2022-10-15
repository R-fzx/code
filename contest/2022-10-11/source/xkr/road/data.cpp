#include<bits/stdc++.h>
using namespace std;
int random(int x) {return llabs(rand() * rand()) % x + 1;}
int main() {
    freopen("road.in", "w", stdout);
    srand(114514);
    int n = 5, m = 10, p = 1145140, q = 1919810;
    cout << n << ' ' << m << ' ' << p << ' ' << q << endl;
    for (int i = 1; i <= m; i++) {
        int l = rand() % n + 1, r = rand() % n + 1;
        int x = random(1000000000), y = random(1000000000);
        cout << l << ' ' << r << ' ' << x << ' ' << y << endl;
    }
    return 0;
}