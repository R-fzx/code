#include<bits/stdc++.h>
#include<fstream>
using namespace std;
ifstream fin("section.in");
ofstream fout("section.out");
const int maxn=1000010;
int n,m,q,a[maxn],ans;
int main(){
    fin>>n>>m>>q;
    for(int i=1;i<=n;i++)fin>>a[i];
    while(q--){
        int o,l;fin>>o>>l;l--;
        if(o==1)for(int i=1;i<=m/2;i++){
            swap(a[i+l],a[m-i+1+l]);
        }else ans^=a[l+1];
    }
    fout<<ans;
    return 0;
}