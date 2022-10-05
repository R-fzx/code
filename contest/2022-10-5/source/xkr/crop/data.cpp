#include<bits/stdc++.h>
using namespace std;
int random() {return llabs(rand() * rand()) % 1000000000 + 1;}
int main() {
    freopen("crop.in", "w", stdout);
    srand(time(0));
    int n = 400;
    cout << n << endl;
    for (int i = 1; i <= 7; i++) cout << random() << endl;
    return 0;
}