#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 1000005
#define M 10005
#define logT 6 
#define mod 100000000
#define int1 long long
using namespace std;
int1 n,m,q,i,j,k,ans,mm,mi,a[N],op,fz[N],x,lx;
bool l[N];
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
	freopen("section.in","r",stdin);
	freopen("section.out","w",stdout);
	n = read(),m = read(),q = read();
	for(i = 1; i <= n; i++){
		a[i] = read();
	}
	for(i = 1; i <= q; i++){
		op = read(),x = read();
		if(op == 1){
			l[x] ^= 1;
		}else{
			for(j = 1; j <= n; j++){
				if(l[j]){
					l[j] ^= 1,mm = j + m - 1;
					for(k = j; k <= mm - k + 1; k++){
						swap(a[k],a[mm - k + 1]);
					}
				}
			}
			ans ^= a[x];
		}
	}
	print(ans);
	return 0;
}
