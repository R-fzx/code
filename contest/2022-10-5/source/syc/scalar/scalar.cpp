#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,x[maxn],y[maxn];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("scalar.in","r",stdin);
    freopen("scalar.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=n;i++)
        cin>>y[i];
    sort(x+1,x+n+1);
    sort(y+1,y+n+1,cmp);
    int s=0;
    for(int i=1;i<=n;i++)
        s+=x[i]*y[i];
    cout<<s;
    return 0;
}