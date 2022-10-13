#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 1000005
#define int1 long long
using namespace std;
int1 t,n,q,i,a[N],b[N],x,y,xx,yy,qa[N],qb[N];
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
	freopen("simple.in","r",stdin);
	freopen("simple.out","w",stdout);
	t = read();
	while(t--){
		n = read(),q = read();
		for(i = 1; i <= n; i++){
			xx = read(),yy = read();
			a[i] = xx + yy,b[i] = xx - yy;
		}
		sort(a + 1,a + n + 1);
		sort(b + 1,b + n + 1);
		for(i = 1; i <= n; i++){
			qa[i] = qa[i - 1] + a[i],qb[i] = qb[i - 1] + b[i];
		}
		while(q--){
			xx = read(),yy = read(),x = xx + yy,y = xx - yy;
			xx = lower_bound(a + 1,a + n + 1,x) - a - 1,yy = lower_bound(b + 1,b + n + 1,y) - b - 1;
			print((((xx << 1) - n) * x + ((yy << 1) - n) * y + qa[n] + qb[n] - ((qa[xx] + qb[yy]) << 1)) >> 1);
			putchar('\n');
		}
	}
	return 0;
}
