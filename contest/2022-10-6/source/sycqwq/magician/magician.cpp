#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
int n,m,d[maxn];
int main()
{
    freopen("magician.in","r",stdin);
    freopen("magician.out","w",stdout);
    cin>>n>>m;
    int s=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(d[x]!=0&&d[y]!=0)
            s*=2,s+=1;
        ++d[x],++d[y];
        s%=mod;
        cout<<s<<endl;
    }
    return 0;
}