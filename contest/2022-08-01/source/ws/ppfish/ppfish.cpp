#include<bits/stdc++.h>
#define int long long
using namespace std;
int hh1[1000005],hh2[1000005];const int bs1=13331,md1=1000000007LL,bs2=17033,md2=998244353LL;
int n,k,ch1[205],ch2[205],len[205],cnt[205],ccnt[205],b[205];
char s[1000005];
double dp[205],remmr;
signed main(){
	freopen("ppfish.in","r",stdin);
	freopen("ppfish.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>(s+1);
		len[i]=strlen(s+1);
		for(int j=1;j<=len[i];j++){
			ch1[i]=(ch1[i]*bs1%md1+s[j]-'a')%md1;
			ch2[i]=(ch2[i]*bs2%md2+s[j]-'a')%md2;
		}
	}
	cin>>(s+1);int m=strlen(s+1);
	for(int j=1;j<=m;j++){
		hh1[j]=(hh1[j-1]*bs1%md1+s[j]-'a')%md1;
		hh2[j]=(hh2[j-1]*bs2%md2+s[j]-'a')%md2;
	}
	for(int i=1;i<=n;i++){
		int nbs1=1,nbs2=1;
		for(int j=1;j<=len[i];j++)nbs1=nbs1*bs1%md1,nbs2=nbs2*bs2%md2;
		for(int j=len[i];j<=m;j++){
			if(
			(hh1[j]+md1-hh1[j-len[i]]*nbs1%md1)%md1==ch1[i] &&
			(hh2[j]+md2-hh2[j-len[i]]*nbs2%md2)%md2==ch2[i]
			)cnt[i]++;
		}
	}
	memcpy(b,cnt,sizeof cnt);
	sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
	cin>>remmr>>k;
	for(int i=1;i<=m;i++)dp[i]=1;
	for(;k--;){
		double sum_1=1,sum=0,lst,llst=0;
		for(int i=1;i<=m;i++){
			lst=dp[i];
			dp[i]=sum_1*dp[i]*remmr+llst;
			sum=sum*lst+sum_1*lst;
			sum_1*=(1-lst);
			llst=lst;
		}
	}
	for(int i=1;i<=n;i++)cout<<fixed<<setprecision(3)<<dp[lower_bound(b+1,b+m+1,cnt[i])-b]<<' ';
	return 0;
}
