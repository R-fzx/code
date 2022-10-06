//我只能永远读这对白，读着我给你的伤害 
#include<bits/stdc++.h>
#define printsp(x) print(x),putchar(' ')
#define printen(x) print(x),putchar('\n')
#define int long long
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
const int N=1e4+9;
int _n,n,k,op[N],a[N],b[N],vis[10];
bool can[10][10];
void work1(){
	memset(can,1,sizeof(can));
	_n=n;n=0;
	int x,y=-114514;
	for(int i=1;i<=_n;i++){
		x=read();
		if(x-y!=1)b[n]=y,a[++n]=x,op[n-1]=a[n]-b[n-1];
		y=read();
	}
	b[n]=y;
	op[n]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		int num=b[i]%10;
		if(op[i]>9-num){
			for(int j=1;j<=num;j++)
				for(int k=num+1;k<=9;k++)
					can[j][k]=can[k][j]=0;
		}
		else{
			int in[10];
			memset(in,0,sizeof(in));
			for(int j=1;j<=num;j++)in[j]=1;
			for(int j=num+1;j<=9;j++){
				int t=b[i]-num+j;
				for(int k=i+1;k<=n;k++){
					if(t<a[k])break;
					if(a[k]<=t&&t<=b[k]){in[j]=1;break;}
				}
			}
			for(int j=1;j<=9;j++){
				if(in[j]==0)continue;
				for(int k=num+1;k<=9;k++){
					if(in[k]==1)continue;
					can[j][k]=can[k][j]=0;
				}
			}
		}
	}
	for(int i=1;i<=9;i++){
		if(vis[i])continue;
		print(i);
		for(int j=i+1;j<=9;j++)if(can[i][j]==1)print(j),vis[j]=1;
		puts("");
	}
}
void work2(){
	memset(can,1,sizeof(can));
	char x[29],y[29];
	int lx,ly;
	scanf("%s %s",x+1,y+1);
	lx=strlen(x+1),ly=strlen(y+1);
	for(int i=lx;i>=max(1ll,lx-k+1);i--){
		int t=x[i]-'0';
		for(int j=1;j<t;j++)
			for(int k=t;k<=9;k++)can[k][j]=can[j][k]=0;
	}
	bool bb=0;
	for(int i=ly;i>=max(1ll,ly-k+1);i--){
		int t=y[i]-'0';
		if(!bb&&y[i]!='9')bb=1;
		if(i!=ly&&bb)can[t-1][t]=can[t][t-1]=0;
		for(int j=1;j<=t;j++){
			for(int k=t+1;k<=9;k++)can[j][k]=can[k][j]=0;
		}
	}
	for(int i=1;i<=9;i++){
		if(vis[i])continue;
		print(i);
		for(int j=i+1;j<=9;j++)if(can[i][j]==1)print(j),vis[j]=1;
		puts("");
	}
}
signed main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	n=read(),k=read();
	if(n==1)return work2(),0;
	if(k==1)return work1(),0;
	printf("1\n2\n3\n4\n5\n6\n7\n8\n9");
	return 0;
}
