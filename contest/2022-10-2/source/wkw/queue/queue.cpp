#include<bits/stdc++.h>
#define printlf(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
using namespace std;
inline int read(){
    int x=0;
    bool w=0;
    char c=getchar();
    while(!isdigit(c))  w|=c=='-',c=getchar();
    while(isdigit(c))   x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void print(int x){
    if(x<0) x=-x,putchar('-');
    if(x>9) print(x/10);
    putchar('0'+x%10);
}
int n,h[305];
double cnt,ans;
struct node{
	int val,num;
	bool operator<(const node &x) const{
		return x.val<val;
	}
};
signed main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout); 
	n=read();
	for(register int i=1;i<=n;++i)	h[i]=read();
	do{
		priority_queue<node> q;
		for(register int i=n;i;--i){
			while(!q.empty() && h[i]>=q.top().val)	ans+=q.top().num-i,q.pop();
			q.push((node){h[i],i});
		}	
		while(!q.empty())	ans+=q.top().num,q.pop();		
		++cnt;
	}while(next_permutation(h+1,h+n+1));
	printf("%.2lf",ans/cnt);
    return 0;
}


