#include<bits/stdc++.h>

using namespace std;
long long n,ans(LONG_LONG_MAX),a[809],b[809];
bool ed[809];
inline void f(long long i,long long cur){
    //cout<<i<<' '<<cur<<'\n';
    if(i==n){
        ans=min(ans,cur);
        return;
    }
    for(int j(0);j<n;j++){
        if(ed[j])continue;
        ed[j]=true;
        f(i+1,cur+a[j]*b[i]);
        ed[j]=false;
    }
}   
int main(){  
    freopen("scalar.in","r",stdin),freopen("std.out","w",stdout);                 
    cin>>n;
    for(int i(0);i<n;i++){
        cin>>a[i];
    }
    for(int i(0);i<n;i++){
        cin>>b[i];
    }
    f(0,0);
    cout<<ans;
    return 0;
}