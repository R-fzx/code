#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 12
#define MN 128
#define MM 128
#define mod 1000000007
#define int1 long long
using namespace std;
int1 n,nn,x,y,z,_x,_y,_z,i,j,k,ans;
unordered_map<int1,unordered_map<int1,unordered_map<int1,int1> > > b;
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
struct owo{
	int1 ma[MN][MM],n,m;
} aa,bb;

owo operator*(const owo &x,const owo &y) {
	owo a;
	if(x.m != y.n){
		for(int1 i = 0; i < y.n; i++){
			for(int1 j = 0; j < x.m; j++){
				a.ma[i][j] = 0;
			}
		}
		a.n = y.n,a.m = x.m;
		for(int1 i = 0; i < y.n; i++){
			for(int1 j = 0; j < x.m; j++){
				for(int1 k = 0; k < y.m; k++){
					a.ma[i][j] = (a.ma[i][j] + x.ma[i][k] * y.ma[k][j] % mod) % mod;
				}
			}
		}
	}else{
		for(int1 i = 0; i < x.n; i++){
			for(int1 j = 0; j < y.m; j++){
				a.ma[i][j] = 0;
			}
		}
		a.n = x.n,a.m = y.m;
		for(int1 i = 0; i < x.n; i++){
			for(int1 j = 0; j < y.m; j++){
				for(int1 k = 0; k < x.m; k++){
					a.ma[i][j] = (a.ma[i][j] + x.ma[i][k] * y.ma[k][j] % mod) % mod;
				}
			}
		}
	}
	return a;
}

void martix_quick_pow(owo &a,owo aa,int1 b){
	owo bb = aa;
	while(b){
		if(b & 1){
			aa = aa * bb;
		}
		bb = bb * bb,b >>= 1;
	}
	a = aa;
	return ;
}

void add_ans(){
	ans++,sum += a[i].wei;
	return ;
}

void _push(){
	q.push(a[i].wei);
	return ;
}
*/
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	nn = n = read();
	while(nn--){
		x = read(),y = read(),z = read(),_x = read(),_y = read(),_z = read();
		for(i = x; i <= _x; i++){
			for(j = y; j <= _y; j++){
				for(k = z; k <= _z; k++){
					b[i][j][k]++;
					if(b[i][j][k] == n - 1){
						ans++;
					}
				}
			}
		}
	}
	if(n == 1){
		print(1145141919810);
	}else{
		print(ans);
	}
	return 0;
}
