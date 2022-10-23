#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000005;
int si[Maxn], ls[Maxn], rs[Maxn], f[Maxn], v[Maxn], maxn[Maxn], sum[Maxn], root = 1, n, ch[Maxn] = {0};
int i, x, m, q, y, ans;
void lx(int x){
    int y = f[x], z = f[y];
    if(z){
    	if(ls[z] == y)ls[z] = x;
        else rs[z] = x;
	}
    rs[y] = ls[x], f[rs[y]] = y;
    f[x] = z, f[y] = x, ls[x] = y;
    si[x] = si[y], si[y] = si[ls[y]] + si[rs[y]] + 1;
    maxn[x] = maxn[y];
    maxn[y] = max(max(maxn[ls[y]], maxn[rs[y]]), v[y]);
    sum[x] = sum[y], sum[y] = sum[ls[y]] + sum[rs[y]] + v[y];
}
void rx(int x){
    int y = f[x], z = f[y];
    if(z){
    	if(ls[z] == y)ls[z] = x;
        else rs[z] = x;
	}
    ls[y] = rs[x], f[ls[y]] = y, f[x] = z;
    f[y] = x, rs[x] = y, si[x] = si[y];
    si[y] = si[ls[y]] + si[rs[y]] + 1;
    maxn[x] = maxn[y];
    maxn[y] = max(max(maxn[ls[y]], maxn[rs[y]]), v[y]);
    sum[x] = sum[y], sum[y] = sum[ls[y]] + sum[rs[y]] + v[y];
}
void pd(int x){
    swap(ls[x], rs[x]);
    if(ls[x])ch[ls[x]] ^= 1;
    if(rs[x])ch[rs[x]] ^= 1;
    ch[x] = 0;
}
void splay(int x,int goal){
    while(f[x] != goal && f[x] != 0){
        if(ch[x])pd(x);
        int y = f[x], z = f[y];
        if(z != 0 && z != goal){
            if(ch[z])pd(z);
            if(ch[y])pd(y);
            if(ls[z] == y){
            	if(ls[y] == x)rx(y), rx(x);
                else lx(x), rx(x);
			}
            else {
            	if(rs[y] == x)lx(y), lx(x);
                else rx(x), lx(x);
			}
        }
        else{
            if(ch[y])pd(y);
            if(ls[y] == x)rx(x);
            else lx(x);
        }
    }
    if(f[x] == 0)root = x;
}
int gk(int k){
    if(k == 0)return 0;
    si[0] = 0;
    int p = root;
    while(p){
        if(ch[p])pd(p);
        if(si[ls[p]] + 1 == k)break;
        if(si[ls[p]]<k)k -= si[ls[p]] + 1, p = rs[p];
        else p = ls[p];
    }
    return p;
}
int main(){
	freopen("section.in", "r", stdin);
	freopen("section.out", "w", stdout);
	cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    f[1] = 0;
    for(i = 1; i <= n + 1; i++){
        if(i != n + 1){
        	cin >> v[i];
		}
        si[i] = 1, maxn[i] = sum[i] = v[i];
        if(i == 1)continue;
        x = root;
        while(x){
            si[x]++;
            sum[x ]+= v[i];
            maxn[x] = max(maxn[x], v[i]);
            if(i > x){
            	if(rs[x])x = rs[x];
                else {
					rs[x] = i; 
					break;
				}
			}else {
				if(ls[x])x = ls[x];
                else {
					ls[x] = i; 
					break;
				}
			}
        }
        f[i] = x;
        splay(i, 0);
    }
    while(q--){
        cin >> i;
        if(i == 2){
        	cin >> x;
        	ans ^= v[gk(x)];
		}
        else{
        	cin >> x;
        	y = x + m - 1;
            x = gk(x - 1), y = gk(y + 1);
            if(x)splay(x, 0);
            splay(y, x);
            ch[ls[y]] ^= 1;
        }
    }
    cout << ans;
    return 0;
}

