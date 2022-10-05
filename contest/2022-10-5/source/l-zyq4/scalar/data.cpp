#include<bits/stdc++.h>

using namespace std;
int n;
int main(){
    freopen("scalar.in","w",stdout);

    srand(time(0));
    n=rand()%2+10;
    cout<<n<<'\n';
    for(int i(0);i<n;i++){
        cout<<rand()%10+10-(rand()%10+10)<<' ';
    }
    puts("");
    for(int i(0);i<n;i++){
        cout<<rand()%10+10-(rand()%10+10)<<' ';
    }
    puts("");
    return 0;
}