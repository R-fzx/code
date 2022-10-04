#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > p;
int main() {
    freopen("wireless.in", "w", stdout);
    srand(time(0));
    cout << 1500 << ' ' << 1500 << endl;
    for (int i = 1; i <= 1500; i++)
        for (int j = 1; j <= 1500; j++)
            if (rand() % 7 == 0) p.push_back(make_pair(i, j));
    cout << p.size() << endl;
    for (auto k : p) cout << k.first << ' ' << k.second << endl;
    return 0;
}