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
int sum[59],t[59],num[59],len,cntn,cnt0,ans;
char s[59];
void Init(){
	sum[1]=1;
	for(int i=2;i<=25;i++)sum[i]=sum[i-1]*i;
}
void write(int x[],int ln){
	for(int i=1;i<=ln;i++)cout<<x[i]<<" ";
	cout<<endl;
}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	Init();
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		num[i]=t[i]=s[i]-'0';
		if(num[i]==0)cnt0++;
		else cntn++;
	}
//	cout<<cnt0<<" "<<cntn<<endl;
	for(int i=0;i<cnt0;++i)ans+=cntn*sum[i+cntn-1];
//	cout<<ans<<endl;
	sort(t+1,t+len+1);
	do{
		if(t[1]==0)continue;
		bool b=1;
		for(int i=1;i<=len;i++)if(num[i]!=t[i]){b=0;break;}
		if(b)break;
		ans++;
	}while(next_permutation(t+1,t+len+1));
	print(ans);
	return 0;
}
