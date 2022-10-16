#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
typedef long long ll;

int cnt, prime[N], flag[N];

void init () {
    cnt = 0;
    memset(flag, 0, sizeof(flag));
    for (int i = 2; i < N; i++) if (!flag[i]) {
        prime[cnt++] = i;
        for (int j = i*2; j < N; j += i) flag[j] = 1;
    }
}

bool isPrime (int k) {
    if (k < N) return !flag[k];
    for (int i = 0; i < cnt && prime[i] <= k; i++)
        if (k%prime[i] == 0) return false;
    return true;
}

ll under (int n) {
    for (int i = n; i >= 2; i--)
        if (isPrime(i)) return i;
    return 0;
}

ll up (int n) {
    for (int i = n + 1; i; i++)
        if (isPrime(i)) return i;
    return 0;
}

int gcd(ll p, ll q) {
    if (!q) return p;
    else return gcd(q, p%q);
}

int main () {
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout); 
    
    init();
    int cas, n;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        ll v = under(n);
        ll u = up(n);
        ll p = u*v + 2*(n-v-u+1);
        ll q = 2*u*v;
        ll d = gcd(p, q);
        cout << p/d << "/" << q/d << endl;
    }
    return 0;
}
