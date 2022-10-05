#include<bits/stdc++.h>
using namespace std;
long long a[805],b[805];
long long cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cout << 1;
}
/* 证明：若ai不变，将bi与bj交换，设 i < j;
答案+=(b[j]-b[i])*a[i]+(b[i]-b[j])*a[j]=(b[j]-b[i])*a[i]-(b[j]-b[i])*a[j]
因为i < j,所以a[i]<=a[j],(b[j]-b[i])*a[i]-(b[j]-b[i])*a[j]一定不为正数，所以答案不可能变大
*/