#include <bits/stdc++.h>
using namespace std;
int a[40005];
map<int,int> mm;
vector<int> v[205];
vector<int> vv;
int t[100005];
int main(){
    freopen("dandelion.in","r",stdin);
    freopen("dandelion.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int w = 0;
    while(m--){
        int l,r;
        cin>> l >> r;
        l+=w-1,r+=w-1;
        l%=(n+1);
        r%=(n+1);
        l++,r++;
        if(l>r){
            swap(l,r);
        }
        for(int i = l;i <= r;i++){
            t[a[i]]++;
        }
        int maxn = 0;
        for(int i = 1;i <= n;i++){
            maxn= max(maxn,t[i]);
        }
        for(int i = 1;i <= n;i++){
            if(t[i]==maxn){
                cout << i << endl;
                w=i;
                break;
            }
        }
    }
}