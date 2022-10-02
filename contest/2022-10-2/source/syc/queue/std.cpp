#include<bits/stdc++.h>
using namespace std;
int n,a[10005],b[11005],bk[10005],s=0;
void dfs(int x)
{
    if(x==n+1)
    { 
        for(int i=1;i<=n;i++)
        {
            // cout<<b[i]<<' ';
            int t;
            for(int j=i-1;j>=0;j--)
                if(b[j]>=b[i])
                {
                    t=i-j;
                    // cout<<i<<' '<<j<<endl;
                    break;
                }
            // cout<<t<<endl;
            // cout<<b[i]<<' '<<b[0]<<endl;
            s+=t;
        }
        // cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!bk[i])
        {
            bk[i]=1;
            b[x]=a[i];
            dfs(x+1);
            bk[i]=0;
            b[x]=0;
        }
}
int main()
{
    cin>>n;
    b[0]=INT_MAX;
    int qwq=1;
    for(int i=1;i<=n;qwq*=i,i++)
        cin>>a[i];
    dfs(1);
    // cout<<s<<' '<<qwq<<endl;
    cout<<double(s)/double(qwq);
    return 0;
}