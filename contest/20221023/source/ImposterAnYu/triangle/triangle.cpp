#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 100005
#define M 100005
#define MAXT 2005
#define mod 10086
#define int1 long long
using namespace std;
int1 n,m,i,j,a[N],b[N],q,l,r;
//priority_queue<pair<int1,int1> > q;
int1 read(){
    int1 x = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(int1 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9){
        print(x / 10);
    }
    putchar(x % 10 + 48);
    return ;
}
/*
void add(int1 x,int1 y,int1 l){
	la[++bs] = ta[x],ta[x] = bs,no[bs] = x,go[bs] = y,w[bs] = l;
	return ;
}

int1 dijkstra_max(int1 x){
	for(int1 i = 1; i <= n; i++){
		dis[i] = 1145141919,b[i] = 0;
	}
	int1 maxn = 0;
	dis[x] = 0;
	q.push({0,x});
	while(!q.empty()){
		int1 r = q.top().second;
		q.pop();
		if(!b[r]){
			b[r] = 1;
			for(int1 i = ta[r]; i; i = la[i]){
				int1 v = go[i],d = dis[r] + w[i];
				if(dis[v] > d){
					dis[v] = d;
					q.push({-dis[v],v});
				}
			}
		}
	}
	for(int1 i = 1; i <= n; i++){
		if(dis[i] != 1145141919){
			maxn = max(maxn,dis[i]);
		}
	}
	return maxn;
}

int1 _id(int1 a,int1 n){
	return (a + n - 1) % n + 1;
}
*/
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	n = read(),q = read();
	for(i = 1; i <= n; i++){
		a[i] = read();
	}
	while(q--){
		l = read(),r = read(),m = r - l + 1;
		if(m < 3){
			printf("No\n");
			continue;
		}
		for(i = 1,j = l; i <= m; i++,j++){
			b[i] = a[j];
		}
		sort(b + 1,b + m + 1);
		for(i = 2; i < m; i++){
			if(b[i - 1] + b[i] > b[i + 1]){
				printf("Yes\n");
				break;
			}
		}
		if(i == m){
			printf("No\n");
		}
	}
	return 0;
}
