#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int main(){
    freopen("sillyz.in","r",stdin);
    freopen("sillyz.out","w",stdout);
    for(int i = 1;i <= 1000003;i++){
        dp[i]+=dp[i-1];
        long long s = i;
        int p = i;
        while(p>0){
            s*=(p%10);
            p/=10;
        }
        if(s < 1000005){
            dp[s]++;
        }
    }
    int l,r;
    cin >> l >> r;
    cout << dp[r]-dp[l-1];
}