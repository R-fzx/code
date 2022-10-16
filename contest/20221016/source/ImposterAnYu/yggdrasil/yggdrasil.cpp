#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 700005
#define mod 10007
#define int1 int
using namespace std;
int1 n,ta[N],la[N << 1],go[N << 1],w[N << 1],a[N],zjd[N],i,ans_s = 1145141919,ans_i,s,bs,x,y,l;
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
void add(int1 x,int1 y,int1 l){
	la[++bs] = ta[x],ta[x] = bs,go[bs] = y,w[bs] = l;
	return ;
}
void dfs(int1 x,int1 f){
	zjd[x] = 1;
	for(int1 i = ta[x]; i; i = la[i]){
		int1 v = go[i];
		if(v != f){
			dfs(v,x);
			zjd[x] += zjd[v],s += zjd[v] * w[i];
		}
	}
	return ;
}
int main(){
	freopen("yggdrasil.in","r",stdin);
	freopen("yggdrasil.out","w",stdout);
	n = read();
	for(i = 1; i <= n; i++){
		a[i] = read();
	}
	for(i = 1; i < n; i++){
		x = read(),y = read(),l = read();
		add(x,y,l - a[x]),add(y,x,l - a[y]);
	}
	for(i = 1; i <= n; i++){
		s = 0;
		dfs(i,0);
		if(s < ans_s){
			ans_s = s,ans_i = i;
		}
	}
	printf("%d\n%d",ans_i,ans_s);
	return 0;
}
