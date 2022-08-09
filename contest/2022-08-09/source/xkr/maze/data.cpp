#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("maze.in", "w", stdout);
    srand(time(0));
    cout << 20 << ' ' << 20 << ' ' << 5000 << endl;
    for (int i = 1; i <= 20; i++, cout << endl)
        for (int j = 1; j <= 20; j++)
            cout << abs(rand() * rand()) % 10000 + 1 << ' ';
    return 0;
}