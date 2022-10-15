#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 50005
#define M 100005
#define K 15
#define mod 1000000007
#define int1 int
using namespace std;
const int1 s = 100;
int1 n = 10 * s,m = 30 * s,i,l,ma = 10000 * s;
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
int1 r(int1 l,int1 r){
	return (rand() + (rand() << 16)) % (r - l + 1) + l;
}
int main(){
	freopen("travel.in","w",stdout);
	srand(time(0));
	printf("%d %d\n",n,m);
	for(i = 1; i <= m; i++){
		l = r(1,ma);
		printf("%d %d %d %d\n",r(1,n),r(1,n),l,l + r(1,ma - l));
	} 
	return 0;
}
