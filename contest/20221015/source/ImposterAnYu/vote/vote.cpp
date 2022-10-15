#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define M 100005
#define int1 int
using namespace std;
int1 n,m,a[M],i,s,b[M];
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
int main(){
	freopen("vote.in","r",stdin);
	freopen("vote.out","w",stdout);
	n = read(),m = read();
	for(i = 1; i <= m; i++){
		a[i] = read(),b[a[i]]++;
		if(b[a[i]] == 1){
			s++;
		}
	}
	if(b[a[1]] == m){
		printf("1.0000");
	}
	for(i = 2; i <= m; i++){
		if(b[a[i]] != b[a[i - 1]]){
			break;
		}
	}
	if(i > m && n - m == 1){
		printf("%.4lf",1.0 / s);
	}else{
		printf("0.0000");
	}
	return 0;
}
