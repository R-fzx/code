#include<bits/stdc++.h>
using namespace std;
#define int long long
int C[55][55],bk[105],n; 
signed main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    C[0][0]=1;
    for(int i=1;i<=50;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
        if(a[i]!='0')
            ++bk[a[i]-'0'],++n;
        else
            ++bk[0];
    int p=1,sm=0;
    for(int i=1;i<=9;sm+=bk[i],i++)
        p*=C[n-sm][bk[i]];
    int s=0;
    for(int i=n;i<a.size();i++)
        s+=p*C[i-1][n-1];
    int qwq=0;
    // --bk[a[0]-'0'];
    qwq=1;
    // cout<<s<<endl;
    // bk[0]=INT_MAX;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')
        {
            --bk[0];
            continue;
        }
        int x=a[i]-'0';
        int p=1;
        for(int j=(i==0?1:0);j<x;j++)
            if(bk[j])
            {   
                // cout<<i<<' '<<j<<endl;
                --bk[j];
                // ++qwq;
                p=1;
                sm=0;
                int m=a.size()-i-1;
                for(int i=0;i<=9;sm+=bk[i],i++)
                    p*=C[m-sm][bk[i]];
                // --qwq;
                ++bk[j];
                s+=p;
            }
        --bk[a[i]-'0'];
        // ++qwq;
    }
    cout<<s;
    return 0;
}