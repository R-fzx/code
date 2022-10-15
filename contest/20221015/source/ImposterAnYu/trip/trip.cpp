#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 5005
#define M 100005
#define K 50005
#define int1 long long
using namespace std;
int1 n,m,i,j,l = 1145141919810,r,mid,f[N],c[K],nn,bl[N],ans_l,ans_r,s,t;
struct Edge{
	int1 no,go,w,wu,wd;
} a[M << 1];
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
int1 find(int1 x){
	if(f[x] == x){
		return x;
	}
	return f[x] = find(f[x]);
}
int main(){
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
	n = read(),m = read();
	for(i = 1; i <= m; i++){
		a[i].no = read(),a[i].go = read(),a[i].w = read();
	}
	for(i = 1; i <= n; i++){
		nn = read();
		for(j = 1; j <= nn; j++){
			c[read()] = i;
		}
	}
	for(i = 1; i <= n; i++){
		bl[i] = read();
	}
	for(i = 1; i <= m; i++){
		int1 u = a[i].no,v = a[i].go;
		double d = a[i].w * (bl[c[u]] + bl[c[v]]) / 200.0;
		a[i].wu = (int1)ceil(d),a[i].wd = (int1)floor(d);
		l = min(l,a[i].wd),r = max(r,a[i].wd);
	}
	s = read(),t = read();
	while(l <= r){
		mid = (l + r) >> 1;
		for(i = 1; i <= n; i++){
			f[i] = i;
		}
		for(i = 1; i <= m; i++){
			if(a[i].wd >= mid){
				f[find(a[i].no)] = find(a[i].go);
			}
		}
		if(find(s) == find(t)){
			l = mid + 1,ans_l = mid;
		}else{
			r = mid - 1;
		}
	}
	l = 1145141919810,r = 0;
	for(i = 1; i <= m; i++){
		l = min(l,a[i].wu),r = max(r,a[i].wu);
	}
	while(l <= r){
		mid = (l + r) >> 1;
		for(i = 1; i <= n; i++){
			f[i] = i;
		}
		for(i = 1; i <= m; i++){
			if(a[i].wd >= ans_l && a[i].wu <= mid){
				f[find(a[i].no)] = find(a[i].go);
			}
		}
		if(find(s) == find(t)){
			r = mid - 1,ans_r = mid;
		}else{
			l = mid + 1;
		}
	}
	printf("%lld %lld",ans_l,ans_r);
	return 0;
}
