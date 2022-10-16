#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 250005
#define M 1000005
#define int1 int
using namespace std;
int1 n,m,i,j,k,dx[4] = {1,-1},dy[4] = {0,0,1,-1},ta[N],la[M << 1],go[M << 1],w[M << 1],dis[N],bs,x,y,s,t,d;
bool a[505][505],b[N];
char ch;
priority_queue<pair<int1,int1> > q;
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
int1 find(int1 x){
	if(f[x] == x){
		return x;
	}
	return f[x] = find(f[x]);
}
*/
void dijkstra(int1 x){
	for(int1 i = 1,nm = n * m; i <= nm; i++){
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
void add(int1 n,int1 g,int1 d){
	la[++bs] = ta[n],ta[n] = bs,go[bs] = g,w[bs] = d;
	return ;
}
int1 cha(int1 i,int1 j){
	return (i - 1) * m + j;
}
int main(){
	freopen("portal.in","r",stdin);
	freopen("portal.out","w",stdout);
	n = read(),m = read();
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			ch = getchar();
			while(ch != 'C' && ch != 'F' && ch != '.' && ch != '#'){
				ch = getchar();
			}
			if(ch == 'C'){
				s = cha(i,j);
			}else if(ch == 'F'){
				t = cha(i,j);
			}
			if(ch != '#'){
				a[i][j] = 1;
			}
		}
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(a[i][j]){
				for(k = 0; k <= 3; k++){
					x = i + dx[k],y = j + dy[k];
					if(a[x][y]){
						int1 u = cha(i,j),v = cha(x,y);
						add(u,v,1);
					}
				}
				d = 1145141919;
				for(k = 0; k <= 3; k++){
					x = i + dx[k],y = j + dy[k];
					while(a[x][y]){
						x += dx[k],y += dy[k];
					}
					x -= dx[k],y -= dy[k],d = min(d,abs(i - x) + abs(j - y));
				}
				for(k = 0; k <= 3; k++){
					x = i + dx[k],y = j + dy[k];
					while(a[x][y]){
						x += dx[k],y += dy[k];
					}
					x -= dx[k],y -= dy[k];
					int1 u = cha(i,j),v = cha(x,y);
					add(u,v,d + 1);
				}
			}
		}
	}
	dijkstra(s);
	if(dis[t] == 1145141919){
		printf("nemoguce");
	}else{
		print(dis[t]);
	}
	return 0;
}
