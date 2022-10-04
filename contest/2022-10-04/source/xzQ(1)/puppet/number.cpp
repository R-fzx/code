#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')

using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}

signed main(){
	freopen("puppet.in","w",stdout);
	srand(clock());
	int T=100;
	while(T--){
		int n=rand()%50+2;
		cout<<n<<endl;
		for(int i=1;i<=n;i++)cout<<rand()%100+1<<" ";
		cout<<endl;
	}
	return 0;
}
