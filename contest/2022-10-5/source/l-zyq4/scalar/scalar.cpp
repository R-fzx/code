#include<bits/stdc++.h>

using namespace std;
long long n,ans,a[809],b[809];
/* cd "d:\l-zyq4\scalar\" ; if ($?) { g++ data.cpp -o data } ; if ($?) { .\data }
cd "d:\l-zyq4\scalar\" ; if ($?) { g++ scalar.cpp -o scalar } ; if ($?) { .\scalar }
cd "d:\l-zyq4\scalar\" ; if ($?) { g++ std.cpp -o std } ; if ($?) { .\std }
*/
int main(){              
    freopen("scalar.in","r",stdin),freopen("scalar.out","w",stdout);       
    cin>>n;
    for(int i(0);i<n;i++){
        cin>>a[i];
    }
    for(int i(0);i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n),sort(b,b+n);
    for(int i(0);i<n;i++){
        ans+=a[i]*b[n-i-1];
    }
    cout<<ans;
    return 0;
}