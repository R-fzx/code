#include<bits/stdc++.h>
using namespace std;
int random() {return (1ll * rand() * rand() * rand() + 1000000000) % 1000000000;}
int main() {
    freopen("data.in", "w", stdout);
    srand(time(0));
    cout << 10000 << endl;
    for (int i = 1; i <= 10000; i++)
        cout << random() << ' ' << random() << ' ' << random() << ' ' << random() << endl;
    return 0;
}