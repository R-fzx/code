#include<bits/stdc++.h>
#define int long long
using namespace std;
int n(1),m(1),cnt,ans(1),tail,prime[1000009],rnk[1000009],c[1000009];
bool nprime[1000009];
const int Q=(1000000007);
/*
xy=km
k=x+y
x(k-x)=km
xk-x*x=km
k(x-m)=x*x
k=x*x/(x-m)=x + xm/(x-m)=x+m + m*m/(x-m)

f[m]:m*m所有非负因数个数
m^2 * (n+1)^2
f[n+1]=f[n]
*/
inline void work(int i){
    int j(1);
    for(int j(1);i>1&&j<=tail;j++){
        if(!nprime[i]){
            c[rnk[i]]++;
            return;
        }
        while((i>1) && (i%prime[j]==0))c[j]=c[j]+1,i/=prime[j];
    }
}
signed main(){
    freopen("sakura.in","r",stdin),freopen("sakura.out","w",stdout);
    cin>>n;
    for(int i(2);i<=1e6;i++){
        if(!nprime[i])prime[++tail]=i,rnk[i]=tail;//,cout<<i<<'\n';
        for(int j(1);i*prime[j]<=1e6&&j<=tail;j++)nprime[i*prime[j]]=true;
    }
    for(int i(1);i<=n;i++){
        work(i);
    }
    for(int i(1);i<=tail;i++){
        ans=(ans*((c[i]*2+1)))%Q;
    }
    cout<<ans;
    return 0;
}
