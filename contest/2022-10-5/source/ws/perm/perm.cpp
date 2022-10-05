#include<bits/stdc++.h>
#define int long long
using namespace std;

int c[55][55];

void init(){
	c[0][0]=1;
	for(int i=1;i<=50;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}

int C(int n,int m){
	if(n<m)return 0;
	
	return c[n][m];
}

string s;
int a[15],n;

map<__int128,int>dp[55][2];

int b[15];

__int128 D(){
	__int128 sum=0;
	for(int i=0;i<=9;i++)
		sum=sum*50+b[i];
	return sum;
}
void E(__int128 x){
	for(int i=9;i>=0;i--){
		b[i]=x%50;
		x/=50;
	}
}

int dfs(int step,bool istop,__int128 now){
	// cerr<<step<<' '<<istop<<endl;
	
    // E(now);

    // for(int i=0;i<=9;i++)
        // cerr<<b[i]<<' ';
    // cerr<<endl;

	if(step==n+1)
		return 1;
	if(dp[step][istop][now])
		return dp[step][istop][now];
	
	E(now);
	
	if(!istop){
		int nn=n-step+1,sum=1;
		for(int i=0;i<=9;i++){
			sum*=C(nn,b[i]);
			nn-=b[i];
		}
		dp[step][istop][now]=sum;
		return sum;
	}
	
	int sum=0;
	
	for(int i=0;i<=s[step-1]-'0';i++){
        E(now);
		if(b[i]){
            b[i]--;
            __int128 tmp=D();
            
            if(i!=s[step-1]-'0')
                sum+=dfs(step+1,0,tmp);
            else
                sum+=dfs(step+1,1,tmp);
        }
	}
	dp[step][istop][now]=sum;
	return sum;
}

signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	
	init();
	
	cin>>s;
	
	n=s.size();
	for(int i=0;i<n;i++)
		a[s[i]-'0']++;
	
	int ans=0;
	
	for(int i=0;i<a[0];i++)
		for(int j=1;j<=9;j++){
			if(a[j]){
				int nn=n-a[0]-1,sum=C(n-a[0]+i-1,i);
				a[j]--;
				
                // cerr<<nn<<' '<<sum<<endl;

				for(int k=1;k<=9;k++){
					sum*=C(nn,a[k]);
					nn-=a[k];
				}
				
				a[j]++;
				ans+=sum;
                // cerr<<i<<' '<<j<<' '<<sum<<endl;
			}
		}
	
    // cerr<<ans<<endl;
	
	for(int i=1;i<=s[0]-'0';i++){
		if(a[i]){
			a[i]--;			
			for(int j=0;j<=9;j++)
				b[j]=a[j];
			__int128 tmp=D();
			
			if(i==s[0]-'0')
				ans+=dfs(2,1,tmp);
			else
				ans+=dfs(2,0,tmp);
			a[i]++;
			// cerr<<i<<' '<<ans<<endl;
		}
	}
	cout<<ans-1;
	return 0;
}
