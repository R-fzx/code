#include<bits/stdc++.h>
using namespace std;
int n,m,a[400005];
map<int,int> bk;
int main()
{
    freopen("dandelion.in","r",stdin);
    freopen("dandelion.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int lstans=0;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        l=(l+lstans-1)%n+1,r=(r+lstans-1)%n+1;
        if(l>r)
            swap(l,r);
        bk.clear();
        int ma=0,maid;
        for(int j=l;j<=r;j++)
        {
            ++bk[a[j]];
            if(bk[a[j]]>ma)
                ma=bk[a[j]],maid=a[j];
            else if(bk[a[j]]==ma)
                maid=min(maid,a[j]);
        } 
        cout<<maid<<endl;
    }
    return 0;
}