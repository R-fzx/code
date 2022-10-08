#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
map<int,int> bk;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bk.clear();
        int f=0;
        for(int i=1;i<=n;b[i]=a[i],i++)
        {
            cin>>a[i];
            ++bk[a[i]];
            if(bk[a[i]]!=1)
                f=1;
        }
        sort(b+1,b+n+1);
        int t=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[n-i+1])
                t=1;
        }
        puts((t||f)?"YES":"NO");
    }
    return 0;
}