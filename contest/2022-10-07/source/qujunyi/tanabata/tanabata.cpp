#include<bits/stdc++.h>
using namespace std;
int sum[100005],summ[100005];
int main(){
    freopen("tanabata.in","r",stdin);
    freopen("tanabata.out","w",stdout);
    int n,m,t;
    cin>> n >> m >> t;
    for(int i = 1;i <= t;i++){
        int x,y;
        cin >> x >> y;
        sum[x]++,summ[y]++;
    }
    if(t%n==0&&t%m==0){
        cout << "both ";
        int s = t/m;
        int ans = 0;
        for(int i = 2;i <= m;i++){
            ans+=abs(summ[i]-s);
            summ[i]+=summ[i-1]-s;
            summ[i-1]=s;
        }
        s = t/n;
        for(int i = 2;i <= n;i++){
            ans+=abs(sum[i]-s);
            sum[i]+=sum[i-1]-s;
            sum[i-1]=s;
        }
        cout << ans;
    }else if(t%n==0){
        cout << "row ";
        int s = t/n;
        int ans = 0;
        for(int i = 2;i <= n;i++){
            ans+=abs(sum[i]-s);
            sum[i]+=sum[i-1]-s;
            sum[i-1]=s;
        }
        cout << ans;
    }else if(t%m==0){
        cout << "column ";
        int s = t/m;
        int ans = 0;
        for(int i = 2;i <= m;i++){
            ans+=abs(summ[i]-s);
            summ[i]+=summ[i-1]-s;
            summ[i-1]=s;
        }
        cout << ans;
    }else{
        cout << "impossible";
    }
}