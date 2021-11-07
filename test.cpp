#include <bits/stdc++.h>
using namespace std;
char buf[10];
int main() {
    fread(buf,1,sizeof(buf),stdin);
    cout << ferror(stdin) << endl;
    return 0;
}