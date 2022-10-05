#include<bits/stdc++.h>
using namespace std;
long long a[805],b[805];
long long cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("scalar.in","r",stdin);
    freopen("scalar.out","w",stdout);
    long long n;
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(long long i = 1;i <= n;i++){
        cin >> b[i];
    }
    long long sum = 0;
    sort(a+1,a+1+n);
    sort(b+1,b+1+n,cmp);
    for(long long i = 1;i <= n;i++){
        sum+=a[i]*b[i];
    }
    cout << sum;
}
/* 证明：若ai不变，将bi与bj交换，设 i < j;
答案+=(b[j]-b[i])*a[i]+(b[i]-b[j])*a[j]=(b[j]-b[i])*a[i]-(b[j]-b[i])*a[j]
因为i < j,所以a[i]<=a[j],(b[j]-b[i])*a[i]-(b[j]-b[i])*a[j]一定不为正数，所以答案不可能变大
*/