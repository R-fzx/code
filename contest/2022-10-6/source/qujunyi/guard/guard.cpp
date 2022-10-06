#include <bits/stdc++.h>
using namespace std;
double dp[205][205][405];
double a[205];
int b[205];
int main()
{
   freopen("guard.in","r",stdin);
   freopen("guard.out","w",stdout);
        int n, l, m;
    cin >> n >> l >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i]/=100;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if(200+m>400){
        dp[0][0][400] = 1;
    }else{
        dp[0][0][200+m] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            for (int k = 0; k <=400; k++){
                    dp[i][j][k] += (1-a[i])*dp[i-1][j][k];
                if (k + b[i] >= 0&&j>0){
                    if(k+b[i]>=400){
                        dp[i][j][400] += a[i]*dp[i-1][j-1][k];
                    }else{
                        dp[i][j][k+b[i]] += a[i]*dp[i-1][j-1][k];
                    }
                }
            }
        }
    }
    //for (int i = 1; i <= n; i++){
    //    for (int j = 0; j <= i; j++){
    //        for (int k = 198; k <= 202; k++){
    //            cout << i << " "<< j << " "<< k << " "<< dp[i][j][k]<< endl;
    //        }
    //    }
    //}
    double sum = 0;
    for(int j = l;j <= n;j++){
        for(int k = 200;k <= 400;k++){
            sum+=dp[n][j][k];
        }
    }
    printf("%.6lf",sum);
}