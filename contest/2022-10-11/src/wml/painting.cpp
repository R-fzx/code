#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mod 1000000007

using namespace std;

int n,m,k;

int main()
{
    freopen("painting.in","r",stdin);
    freopen("painting.out","w",stdout);

    cin>>n>>m>>k;

    cout<<(((n*m)%mod)*k)%mod<<endl;

    return 0;
}
