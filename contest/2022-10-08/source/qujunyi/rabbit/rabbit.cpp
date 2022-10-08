#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("rabbit.in","r",stdin);
    freopen("rabbit.out","w",stdout);
    int n;
    cin>> n;
    cout << (n)*(n-1)/2<< endl;
    for(int i = 1;i <= (n>>1);i++){
        for(int j = 1;j <= n;j++){
            cout << j << " "<<(j+i-1)%n+1<< " "<<(j+2*i-1)%n+1<< endl;
        }
    }
}