#include<bits/stdc++.h>
using namespace std;
int a[1000005],s;
int main()
{ 
    freopen("sillyz.in","r",stdin);
    freopen("sillyz.out","w",stdout);
    int l,r;
    cin>>l>>r;
    for(int i=0;i<=r;i++)
    {
        int x=i,t=1;
        while(x)
        {
            t*=x%10;
            x/=10;
        }
        if(l<=t*i&&t*i<=r)
            ++s;
    }
    cout<<s;
    return 0;
}