#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int a[100005];
long long ans;
int main()
{
    freopen("dt.in","r",stdin);
    freopen("dt.out","w",stdout);
    int n,m,A,B,i;
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);
    while (m--)
    {
        scanf("%d%d",&A,&B);
        ans+=min(a[A],a[B]);
    }
    cout<<ans;
    return 0;
}
