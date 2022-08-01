#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0)x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
//fuck you
int main(){
	freopen("ppfish.in","r",stdin);
	freopen("ppfish.out","w",stdout);
	
	return 0;
}

