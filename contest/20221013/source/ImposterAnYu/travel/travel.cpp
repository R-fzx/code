#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 1005
#define M 3005
#define K 15
#define mod 1000000007
#define int1 int
using namespace std;
int1 n,m,i,j,ans[N],bs,x,y,ta[N],la[M << 1],go[M << 1],w1[M << 1],w2[M << 1],l1,l2,ans_l[N],ans_r[N];
bool b[N];
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
void dfs(int1 x,int1 l,int1 r){
	if(l > r || r - l + 1 < ans[x]){
		return ;
	}
	if(r - l + 1 == ans[x]){
		if(l < ans_l[x]){
			ans_l[x] = l,ans_r[x] = r;
		}else{
			return ;
		}
	}else{
		ans[x] = r - l + 1,ans_l[x] = l,ans_r[x] = r;
	}
	if(x == n){
		return ;
	}
	b[x] = 1;
	for(int1 i = ta[x]; i; i = la[i]){
		int1 v = go[i];
		if(!b[v]){
			dfs(v,max(w1[i],l),min(w2[i],r));
		}
	}
	b[x] = 0;
	return ;
}
void add(int1 n,int1 g,int1 d1,int1 d2){
	la[++bs] = ta[n],ta[n] = bs,go[bs] = g,w1[bs] = d1,w2[bs] = d2;
	return ;
}
/*
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
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n = read(),m = read();
	for(i = 1; i <= m; i++){
		x = read(),y = read(),l1 = read(),l2 = read();
		add(x,y,l1,l2),add(y,x,l1,l2);
	}
	dfs(1,1,1145141919);
	print(ans[n]);
	putchar('\n');
	for(i = ans_l[n]; i <= ans_r[n]; i++){
		print(i);
		putchar(' ');
	}
	return 0;
}
