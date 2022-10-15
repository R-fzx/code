#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5, N = 2e5 + 5;
struct edge{
    int to, next;
    double val;
}e[N];
int n, m, ls[N], x[N], y[N], t[N], kais, jies, tot, shit, tin = 10000007, l, r, dis[N], L, R, ans1, ans2;
double z[N], kkk[N];
bool v[N], b[N];
queue<int> q;
void add(int u, int v, double w){
    e[++tot].to = v, e[tot].next = ls[u], e[tot].val = w, ls[u] = tot;
    e[++tot].to = u, e[tot].next = ls[v], e[tot].val = w, ls[v] = tot;
} 
bool check(int judge1, int judge2){
    memset(v, 0, sizeof(v));
    for(int i = 1; i <= tot; i++){
    	if (e[i].val >= judge1 && e[i].val <= judge2) v[i] = 1;
	}
    memset(b, 0, sizeof(b));
    memset(dis, 0x7f7f7f7f, sizeof(dis));
    dis[kais] = 0, q.push(kais), b[kais] = 1;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = ls[now]; i; i = e[i].next){
            if (!v[i])continue;
            if (dis[now] + 1 >= dis[e[i].to])continue;
            dis[e[i].to] = dis[now] + 1;
            if (b[e[i].to])continue;
            q.push(e[i].to);
            b[e[i].to] = 1;
        }
        b[now] = 0;
    }
    if (dis[jies] != 0x7f7f7f7f)return 1;
    return 0;
}
int main(){
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
    	cin >> x[i] >> y[i] >> z[i];
	}
    for(int i = 1; i <= n; i++){
        int T, u;
        cin >> T;
        for(int j = 1; j <= T; j++){
        	cin >> u;
			t[u] = i;
		} 
    }
    for(int i = 1; i <= n; i++){
    	cin >> kkk[i];
    	kkk[i] /= 100;
	}
	cin >> kais >> jies;
    for(int i = 1; i <= m; i++){
        if (t[x[i]] != t[y[i]]){
            add(x[i], y[i], z[i] * ((kkk[t[x[i]]] + kkk[t[y[i]]]) / 2));
            tin = min(tin, (int)(z[i] * ((kkk[t[x[i]]] + kkk[t[y[i]]]) / 2)));
            shit = max(shit, (int)(z[i] * ((kkk[t[x[i]]] + kkk[t[y[i]]]) / 2)));
        }
        else{
            add(x[i], y[i], z[i] * kkk[t[x[i]]]);
            tin = min(tin, (int)(z[i] * ((kkk[t[x[i]]] + kkk[t[y[i]]]) / 2)));
            shit = max(shit, (int)(z[i] * ((kkk[t[x[i]]] + kkk[t[y[i]]]) / 2)));
        }
    }
    l = tin, r = shit + 1;
    while (l < r){
        int mid = (l + r + 1) / 2;
        if (check(mid, shit + 1))l = mid;
        else r = mid - 1;
    }
    L = l;
    l = tin, r = shit + 1;
    while (l < r){
        int mid = (l + r) / 2;
        if (check(L, mid))r = mid;
        else l = mid + 1;
    }
    R = l;
    cout << L << " " << R;
}
