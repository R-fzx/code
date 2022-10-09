#include<bits/stdc++.h>
#define int long long
using namespace std;
int n(200),c(114);
inline int _rand(int x){
    return ((((x&-x)+x)|(long long)114)-x+214);
}
signed main(){
    freopen("seventeen.in","w",stdout);
    cout<<n<<'\n';
    int i(0);
    while(n--){
        i++;
        cout<<c<<' '<<(c*c+1)%200<<'\n';
        c=(_rand(c)*i)%200;
    }
    return 0;
}