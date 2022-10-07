/*
冷雨夜我在你身边
盼望你会知
可知道我的心
比当初已改变
只牵强的相处
冷雨夜我不想回家
怕望你背影
只苦笑望雨点
须知要说清楚
可惜我没胆试 
*/
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
const int N=1e5+9;
int n,m,k,cntl[N],cntc[N],ans;
bool r=0,c=0;
signed main(){
	freopen("tanabata.in","r",stdin);
	freopen("tanabata.out","w",stdout);
    n=read(),m=read(),k=read();
    if(k%n!=0&&k%m!=0)return puts("impossible"),0;
    for(int i=1;i<=k;i++){
    	int x=read(),y=read();
    	cntl[x]++,cntc[y]++;
    }
    int t1=0,t2=0,t3=0,t4=0;
    if(k%n==0){
    	r=1;
    	int l[N];
    	for(int i=1;i<=n;i++)l[i]=cntl[i];
    	for(int i=1;i<=n;i++){
    		if(i!=1&&l[i-1]<k/n)l[i]-=k/n-l[i-1],t1+=k/n-l[i-1],l[i-1]=k/n;
    		if(i==1&&l[n]<k/n)l[1]-=k/n-l[n],t1+=k/n-l[n],l[n]=k/n;
			if(l[i]<k/n)continue;
    		if(i!=n)l[i+1]+=l[i]-k/n,t1+=l[i]-k/n,l[i]=k/n;
    		if(i==n)l[1]+=l[n]-k/n,t1+=l[n]-k/n,l[n]=k/n;
    	}
    	for(int i=1;i<=n;i++)l[i]=cntl[i];
    	for(int i=n;i>=1;i--){
    		if(i!=n&&l[i+1]<k/n)l[i]-=k/n-l[i+1],t2+=k/n-l[i+1],l[i+1]=k/n;
    		if(i==n&&l[n]<k/n)l[n]-=k/n-l[1],t2+=k/n-l[1],l[1]=k/n;
			if(l[i]<k/n)continue;
    		if(i!=1)l[i-1]+=l[i]-k/n,t2+=l[i]-k/n,l[i]=k/n;
    		if(i==1)l[n]+=l[1]-k/n,t2+=l[1]-k/n,l[n]=k/n;
    	}
    	for(int i=1;i<=n;i++)l[i]=cntl[i];
    	for(int i=1;i<=n;i++){
    		if(l[i]<k/n)continue;
    		if(i!=n)l[i+1]+=l[i]-k/n,t3+=l[i]-k/n,l[i]=k/n;
    		if(i==n)l[1]+=l[n]-k/n,t3+=l[n]-k/n,l[n]=k/n;
    	}
    	for(int i=1;i<=n;i++)if(l[i]<k/n||l[i]>k/n){t3=LONG_LONG_MAX;break;}
    	for(int i=1;i<=n;i++)l[i]=cntl[i];
    	for(int i=n;i>=1;i--){
    		if(l[i]<k/n)continue;
    		if(i!=1)l[i-1]+=l[i]-k/n,t4+=l[i]-k/n,l[i]=k/n;
    		if(i==1)l[n]+=l[1]-k/n,t4+=l[1]-k/n,l[1]=k/n;
    	}
    	for(int i=1;i<=n;i++)if(l[i]<k/n||l[i]>k/n){t4=LONG_LONG_MAX;break;}
    	ans+=min(t1,min(t2,min(t3,t4)));
    }
    if(k%m==0){
    	c=1;
    	int cc[N];
    	t1=t2=t3=t4=0;
    	for(int i=1;i<=m;i++)cc[i]=cntc[i];
    	for(int i=1;i<=m;i++){
    		if(i!=1&&cc[i-1]<k/m)cc[i]-=k/m-cc[i-1],t1+=k/m-cc[i-1],cc[i-1]=k/m;
    		if(i==1&&cc[m]<k/m)cc[1]-=k/m-cc[m],t1+=k/m-cc[m],cc[m]=k/m;
			if(cc[i]<k/m)continue;
    		if(i!=m)cc[i+1]+=cc[i]-k/m,t1+=cc[i]-k/m,cc[i]=k/m;
    		if(i==m)cc[1]+=cc[m]-k/m,t1+=cc[m]-k/m,cc[m]=k/m;
    	}
    	for(int i=1;i<=m;i++)cc[i]=cntc[i];
    	for(int i=m;i>=1;i--){
    		if(i!=m&&cc[i+1]<k/m)cc[i]-=k/m-cc[i+1],t2+=k/m-cc[i+1],cc[i+1]=k/m;
    		if(i==m&&cc[1]<k/m)cc[m]-=k/m-cc[1],t2+=k/m-cc[1],cc[1]=k/m;
			if(cc[i]<k/m)continue;
    		if(i!=1)cc[i-1]+=cc[i]-k/m,t2+=cc[i]-k/m,cc[i]=k/m;
    		if(i==1)cc[m]+=cc[1]-k/m,t2+=cc[1]-k/m,cc[1]=k/m;
    	}
		for(int i=1;i<=m;i++)cc[i]=cntc[i];
    	for(int i=1;i<=m;i++){
			if(cc[i]<k/m)continue;
    		if(i!=m)cc[i+1]+=cc[i]-k/m,t3+=cc[i]-k/m,cc[i]=k/m;
    		if(i==m)cc[1]+=cc[m]-k/m,t3+=cc[m]-k/m,cc[m]=k/m;
    	}
    	for(int i=1;i<=m;i++)if(cc[i]<k/m||cc[i]>k/m){t3=LONG_LONG_MAX;break;}
    	for(int i=1;i<=m;i++)cc[i]=cntc[i];
    	for(int i=m;i>=1;i--){
			if(cc[i]<k/m)continue;
    		if(i!=1)cc[i-1]+=cc[i]-k/m,t4+=cc[i]-k/m,cc[i]=k/m;
    		if(i==1)cc[m]+=cc[1]-k/m,t4+=cc[1]-k/m,cc[1]=k/m;
    	}
    	for(int i=1;i<=m;i++)if(cc[i]<k/m||cc[i]>k/m){t4=LONG_LONG_MAX;break;}
    	ans+=min(t1,min(t2,min(t3,t4)));
    }
    if(r&&c)printf("both %d",ans);
    else if(r)printf("row %d",ans);
    else printf("column %d",ans);
	return 0;
}
