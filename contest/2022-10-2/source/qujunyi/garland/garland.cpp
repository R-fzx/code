#include <bits/stdc++.h>
using namespace std;
struct node {
    long long x, y, z;
    bool s;
} a[505][505];
bool cmp(node i,node j){
    return i.x > j.x;
}
vector<node> v;
int main() {
    freopen("garland.in","r",stdin);
    freopen("garland.out","w",stdout);
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            cin >> a[i][j].x;
        }
    }
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            cin >> a[i][j].y;
        }
    }
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            cin >> a[i][j].z;
        }
    }
    for(long long i = 1;i <= n;i++){
        for(long long j = 1;j <= i;j++){
            node p;
            if(i==j){
                p.x=a[i][j].x;
                p.y=a[i][j].y;
                p.z=a[i][j].z;
                p.s = 0;
            }else{
                p.x = a[i][j].x+a[j][i].x;
                p.y = max(a[i][j].y,a[j][i].y);
                p.z = min(a[i][j].z,a[j][i].z);
                p.s = 1;
            }
            v.push_back(p);
        }
    }
    sort(v.begin(),v.end(),cmp);
    long long sum = 0;
    long long ans = 0;
    for(long long i = 0;i < v.size();i++){
        if(v[i].s == 1){
        sum+=v[i].y*2;
        ans+=v[i].y*v[i].x;

        }else{
            
        sum+=v[i].y;
        ans+=v[i].y*v[i].x;
        };
    }
    sum=abs(sum);
    for(long long i = 0;i < v.size();i++){
        if(v[i].s==1){
            

        if((v[i].z-v[i].y)*2>=sum){
                ans += (sum/2)*v[i].x;
            if(sum%2==1){
                sum = 1;
            }
        }else{
            ans+=(v[i].z-v[i].y)*v[i].x;
            sum -= (v[i].z-v[i].y)*2;
        }

        }else{
            

        if(v[i].z-v[i].y>=sum){
            ans+=sum*v[i].x;
            sum = 0;
        }else{
            ans+=(v[i].z-v[i].y)*v[i].x;
            sum -= (v[i].z-v[i].y);
        }
        }
    }
    cout << ans;
}