#include<bits/stdc++.h>
using namespace std;
void work() {
    cout << 10 << endl;
    for (int i = 1; i <= 10; i++) cout << rand() % 10 + 1 << ' ';
    cout << endl;
}
int main() {
    freopen("puppet.in", "w", stdout);
    srand(114514);
    for (int i = 1; i <= 50; i++) work();
    return 0;
}