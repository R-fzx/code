#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#define MOD 10007
using namespace std;
int n,m,k,fac[4001],kpri[4001],fsf[4001][4001],mp[10000001];
int m1,sum;
int dp[3001][4001];
void dfs(int cnt,int p_m,int assemble)
{
    if(cnt>kpri[0]) {sum+=m1/assemble*p_m;return;}
    dfs(cnt+1,p_m,assemble);
    dfs(cnt+1,-p_m,assemble*kpri[cnt]);
}
int main()
{
	freopen("orbits.in","r",stdin);
    freopen("orbits.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int sqtk=sqrt(k);
    for(int i=1;i<=sqtk;i++)
        if(k%i==0)
        {
            fac[++fac[0]]=i;
            if(k/i>sqtk) fac[++fac[0]]=k/i;
        }
    sort(fac+1,fac+1+fac[0]);
    int tmp=k;
    for(int i=2;i<=sqtk;i++)
    {
        if(tmp==1) break;
        if(tmp%i==0)
        {
            kpri[++kpri[0]]=i;
            while(tmp%i==0) tmp/=i;
        }
    }
    if(tmp!=1) kpri[++kpri[0]]=tmp;
    sort(kpri+1,kpri+1+kpri[0]);
    for(int i=1;i<=fac[0];i++)
    {
        mp[fac[i]]=i;
        sum=0,m1=m/fac[i];
        dfs(1,1,1);
        dp[1][i]=sum%MOD;
    } 
    for(int i=1;i<=fac[0];i++)
        for(int j=1;j<=i;j++)
            if(fac[i]%fac[j]==0) fsf[i][++fsf[i][0]]=j;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=fac[0];j++)
        {
            if(fsf[j][0]==0) continue;
            for(int k=1;k<=fsf[j][0];k++)
                (dp[i][j]+=dp[i-1][fsf[j][k]]*dp[1][mp[fac[j]/fac[fsf[j][k]]]])%=MOD;
        }
    printf("%d\n",dp[n][fac[0]]);
    return 0;
}
