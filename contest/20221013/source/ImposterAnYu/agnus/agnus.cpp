#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 30005
#define int1 long long
using namespace std;
int1 n,m = 5,i,j,s;
char a[N],b[10] = {'\0','a','g','n','u','s'};
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
	freopen("agnus.in","r",stdin);
	freopen("agnus.out","w",stdout);
	scanf("%s",a + 1);
	n = strlen(a + 1);
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(a[i + j - 1] != b[j]){
				break;
			}
		}
		if(j > m){
			s += i * (n - i - 3);
		}
	}
	print(s);
	return 0;
}
