#include<bits/stdc++.h>
#define printlf(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
using namespace std;
int N,M;
const int maxn=105;
char ans[maxn][maxn];
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
inline void dfs(int dir,int n,int m,int t){
//	cout<<"NMÊÇÉ¶:"<<n<<' '<<m<<endl;
	if(n==N+1 || m==M+1){
		for(register int i=1;i<=N;++i){
			for(register int j=1;j<=M;++j)
				putchar(ans[i][j]);putchar('\n');
		}
		exit(0);
	}
	int nn=N-n+1,mm=M-m+1;
	if(nn>mm)	swap(nn,mm);
	int p=mm/nn,cnt=0;
//	cout<<"ppÊÇÉ¶:"<<p<<endl;
//	cout<<"nmÊÇÉ¶"<<nn<<' '<<mm<<endl;
	for(register int k=0;k<p;++k){
		for(register int i=0;i<nn;++i)
			for(register int j=0;j<nn;++j){
				if(!dir)	ans[i+n][j+k*nn+m]=(k&1)?('B'+t):('A'+t);	
				else	ans[j+k*nn+n][i+m]=(k&1)?('B'+t):('A'+t);
//				cout<<i<<' '<<j<<" ij\n";
//				cout<<i+k*nn+n<<' '<<j+k*nn+m<<" i+k*nn+n j+k*nn+m\n";	
			}
		cnt=min(2,cnt+1);
	}
//	for(register int i=1;i<=N;++i){
//		for(register int j=1;j<=M;++j)
//			putchar(ans[i][j]);putchar('\n');
//	}
//	cout<<endl;
//	cout<<"cnt:"<<cnt<<endl;
//	system("pause");
	if(!dir)	dfs(dir^1,n,m+p*nn,t+cnt);
	else	dfs(dir^1,n+p*nn,m,t+cnt);
}
signed main(){
	freopen("chongjg.in","r",stdin);
	freopen("chongjg.out","w",stdout);
	N=read(),M=read();
	if(N>M)	dfs(1,1,1,0);
	else	dfs(0,1,1,0);
    return 0;
}


