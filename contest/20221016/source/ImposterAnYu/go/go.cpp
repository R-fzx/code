#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 1005
#define M 105
#define K 15
#define mod 1000000007
#define int1 int
using namespace std;
int1 n,k,m,i,ans,lo;
bool b[M];

struct owo{
	int1 x,b,t;
} a[M];
bool cmp(owo x,owo y){
	return x.x < y.x;
}

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
void add(int1 n,int1 g,int1 d1,int1 d2){
	la[++bs] = ta[n],ta[n] = bs,go[bs] = g,w1[bs] = d1,w2[bs] = d2;
	return ;
}

int1 quick_pow(int1 a,int1 b,int1 p){
	int1 s = 1;
	while(b){
		if(b & 1){
			s = s * a % p;
		}
		a = a * a % p,b >>= 1;
	}
	return s;
}
*/
void dfs(int1 x,int1 s,int1 t){
	for(int1 i = x; i >= 1; i--){
		int1 ti = a[x].x - a[i].x + t;
		if(ti <= a[i].t && !b[i]){
			b[i] = 1;
			dfs(i,s + a[i].b,ti);
			b[i] = 0;
		}
	}
	for(int1 i = x + 1; i <= m; i++){
		int1 ti = a[i].x - a[x].x + t;
		if(ti <= a[i].t && !b[i]){
			b[i] = 1;
			dfs(i,s + a[i].b,ti);
			b[i] = 0;
		}
	}
	ans = max(ans,s);
	return ;
}
int main(){
	freopen("go.in","r",stdin);
	freopen("go.out","w",stdout);
	n = read(),k = read(),m = read();
	for(i = 1; i <= m; i++){
		a[i].x = read(),a[i].b = read(),a[i].t = read();
	}
	sort(a + 1,a + m + 1,cmp);
	for(i = 1; i <= m; i++){
		if(a[i].x >= k){
			lo = i;
			break;
		}
	}
	if(!lo){
		dfs(m,0,k - a[m].x + 1);
	}else if(lo == 1){
		dfs(1,0,a[1].x - k + 1);
	}else{
		dfs(lo - 1,0,k - a[lo - 1].x + 1);
		dfs(lo,0,a[lo].x - k + 1);
	}
	print(ans);
	return 0;
}
