#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 100005
#define int1 long long
using namespace std;
int1 t,n,v,u,a,b,c;
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
bool prime(int1 x){
	for(int1 i = 2; i * i <= x; i++){
		if(!(x % i)){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	t = read();
	while(t--){
		v = n = read(),u = n + 1;
		while(!prime(u)){
			u++;
		}
		while(!prime(v)){
			v--;
		}
		a = v * u - ((v + u - n) << 1) + 2,b = ((v * u) << 1);
		c = __gcd(a,b),a /= c,b /= c;
		printf("%lld/%lld\n",a,b);
	}
	return 0;
}
