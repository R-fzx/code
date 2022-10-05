#include<bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 1; i <= 1000; i++) {
        system("data.exe"); system("crop.exe"); system("bf.exe");
        if (system("fc crop.out bf.out")) return 0;
        cout << "Accepted on #" << i << endl;
    }
    return 0;
}