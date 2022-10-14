#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 400000 + 5;
const ll INF = 1e18;
int n;
struct node {
    ll x, y;
} a[MAX_N], b[MAX_N], tmp[MAX_N];

bool cmp(node n1, node n2)
{
    return n1.x < n2.x;
}

ll dis(node n1, node n2)
{
    return (n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y);
}

ll msort(int l, int r)
{
    if(l == r)
        return INF;
    int mid = (l + r) >> 1;
    ll val = a[mid].x;
    ll d = min(msort(l, mid), msort(mid + 1, r));
    int i = l, j = mid + 1;
    for(int k = l; k <= r; k++) {
        if(j > r || (i <= mid && a[i].y < a[j].y))
            b[k] = a[i++];
        else
            b[k] = a[j++];
    }
    for(int k = l; k <= r; k++)
        a[k] = b[k];
    int t = 0;
    for(int k = l; k <= r; k++)
        if((a[k].x - val) * (a[k].x - val) < d)
            tmp[++t] = a[k];
    for(int i = 1; i <= t; i++)
        for(int j = i + 1; j <= t && (tmp[i].y - tmp[j].y) * (tmp[i].y - tmp[j].y) < d; j++)
            d = min(d, dis(tmp[i], tmp[j]));
    return d;
}

int main()
{
//	freopen("codes.in","r",stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld%lld", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1, cmp);
    printf("%.3lf\n", sqrt(msort(1, n))/2.0);
    return 0;
}
