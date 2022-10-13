#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 200005
#define int1 int
using namespace std;
int1 n,x,ans,s,siz,i;
priority_queue<int1,vector<int1>,greater<int1> > q;
char ch;
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
	freopen("clickbait.in","r",stdin);
	freopen("clickbait.out","w",stdout);
	//My name is chicky,chicky chicky chicky!
	//My name is chickier,chickier chickier chickier!
	//My name is chickiest,chickiest chickiest chickiest!
	print(1145141919);//뷔，뷔，뷔，가가가가가가가가가가가가가가가가가가가가가■ 
	return 0;
}
