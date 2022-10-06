#include<bits/stdc++.h>
using namespace std;
long long fa[200005];
long long find(long long x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
const long long mod = 1e9+9;
int main(){
   freopen("magician.in","r",stdin);
   freopen("magician.out","w",stdout);
    long long n,m;
    cin>> n >> m;
    for(long long i = 1;i <= n;i++){
        fa[i]=i;
    }
    long long sum = 0;
    while(m--){
        long long x,y;
        cin>> x >> y;
        long long fx = find(x),fy = find(y);
        if(fx==fy){
            sum*=2;
            sum++;
            sum%=mod;
        }else{
            fa[fx]=fy;
        }
        cout << sum << endl;
    }
}