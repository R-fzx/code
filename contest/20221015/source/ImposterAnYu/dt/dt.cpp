#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 100005
#define M 100005
#define K 15
#define mod 1000000007
#define int1 int
using namespace std;
int1 n,m,i,a[N],ans;
/*
struct Edge{
	int1 la,no,go,w1,w2;
} a[M << 1];
bool cmp(Edge x,Edge y){
	return x.w2 < y.w2;
}
*/
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
int main(){
	freopen("dt.in","r",stdin);
	freopen("dt.out","w",stdout);
	n = read(),m = read();
	for(i = 1; i <= n; i++){
		a[i] = read();
	}
	while(m--){
		ans += min(a[read()],a[read()]);
	}
	print(ans);
	return 0;
}
