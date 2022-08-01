#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("ppfish.in", "w", stdout);
    cout << 200 << endl;
    for (int i = 1; i <= 200; i++, cout << endl)
        for (int j = 1; j <= 20; j++)
            cout << (char)('a' + rand() % 2);
    for (int i = 1; i <= 1000000; i++) cout << (char)('a' + rand() % 3);
    cout << endl;
    cout << 0.99999 << endl;
    cout << 1000 << endl;
    return 0;
}