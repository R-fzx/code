#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("scalar.in", "w", stdout);
    int n = 10;
    cout << n << endl;
    for (int i = 1; i <= 10; i++) cout << llabs(rand() * rand()) % 200000 - 100000 << ' ';
    cout << endl;
    for (int i = 1; i <= 10; i++) cout << llabs(rand() * rand()) % 200000 - 100000 << ' ';
    cout << endl;
    return 0;
}