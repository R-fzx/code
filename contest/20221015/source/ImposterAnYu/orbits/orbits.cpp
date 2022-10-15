#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define K 10005
#define int1 long long
using namespace std;
int1 n,m,k,fac[K],i,ans;
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
void dfs(int1 x,int1 mul){
	if(!(mul % k) && __gcd(mul / k,k) > 1){
		return ;
	}
	if(x > n){
		if(!(mul % k)){
			if(__gcd(mul / k,k) == 1){
				ans++;
			}
		}
		return ;
	}
	for(int1 i = 1; i <= m; i++){
		dfs(x + 1,mul * i);
	}
	return ;
}
int main(){
	//freopen("orbits.in","r",stdin);
	//freopen("orbits.out","w",stdout);
	n = read(),m = read(),k = read();
	dfs(1,1);
	print(ans);
	return 0;
}
