#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 1005
#define M 1000005
#define mod 10007
#define int1 int
using namespace std;
int1 n,i,j,a[N],ans;
bool edge[N][N],b[N];
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

void dijkstra(int1 x){
	for(int1 i = 1; i <= n; i++){
		dis[i] = 1145141919,b[i] = 0;
	}
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
	return ;
}
*/
bool cmp(int1 x,int1 y){
	return x > y;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n = read();
	for(i = 1; i <= n; i++){
		a[i] = read();
	}
	sort(a + 1,a + n + 1,cmp);
	for(i = 1; i < n; i++){
		for(j = i; j <= n; j++){
			if(!(a[i] & a[j])){
				edge[i][j] = edge[j][i] = 1;
			}
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j < i; j++){
			if(edge[i][j]){
				break;
			}
		}
		if(j < i){
			ans += a[j];
		}
	}
	print(ans);
	return 0;
}
