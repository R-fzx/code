#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int b[maxn],sum,l[maxn],tn,tl[maxn],n,k,a,c[maxn];
double s=0,f[maxn];
double ans=1;
void dfs(int x,int tot)
{ 
    if(x==n+1)
    { 
        double tp=0; 
        if(tot>(n>>1)) 
            tp+=ans;  
        else 
            tp+=ans*(double(a)/double(a+sum));  
        s+=tp;
        // if(l[1]==10&&l[2]==100&&l[5]==80&&l[6]==80)
        //     cout<<ans<<' '<<s<<endl;
        return;
    }
    double ts=ans;
    ans*=double(l[x])/100.0;
    dfs(x+1,tot+1);
    ans=ts;
    ans*=1.0-double(l[x])/100.0;
    sum+=b[x];
    dfs(x+1,tot);
    sum-=b[x];
    ans=ts;
}
double ma=0;
void qpl(int x,int yy)
{
    // cout<<x<<' '<<yy<<endl;
    if(x==n+1)
    {
        for(int i=1;i<=n;i++)
            tl[i]=l[i];
        for(int j=1;j<=n;j++)
            l[j]+=c[j],l[j]=min(l[j],100);
        ans=1;
        s=0; 
        sum=0;
        dfs(1,0); 
        // if(abs(s-0.757202)<=0.000001)
        // {
        //     for(int j=1;j<=n;j++)
        //         cout<<l[j]<<' ';
        //     cout<<endl;
        // }
        for(int j=1;j<=n;j++)
            l[j]=tl[j]; 
        ma=max(ma,s);
        return;
    }
    for(int i=(x==n?k-yy:0);i<=k-yy;i++)
    {  
        c[x]=i*10;
        qpl(x+1,yy+i);
        c[x]=0;
    }
}
int main()
{
    freopen("assembly.in","r",stdin);
    freopen("assembly.out","w",stdout);
    cin>>n>>k>>a;
    for(int i=1;i<=n;i++)
        cin>>b[i]>>l[i];
    qpl(1,0);
    printf("%.6lf",ma);
    return 0;
}
