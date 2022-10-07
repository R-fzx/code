#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,t,a[maxn],x[maxn],y[maxn],s=0,c[maxn];
void work(int n)
{
    int sm=0;
    for(int i=1;i<=n;i++)
    {
        c[i]=(i-1)*(t/n)-sm;
        sm+=a[i];
    }
    int x1=0; 
    sort(c+1,c+n+1);
    if(n%2==0)
        x1=(c[n/2]+c[n/2+1])/2;
    else
        x1=c[n/2+1];
    for(int i=1;i<=n;i++)
        s+=abs(x1-c[i]);
    // cout<<s<<endl;
}
int main()
{
    freopen("tanabata.in","r",stdin);
    freopen("tanabata.out","w",stdout);
    cin>>n>>m>>t;
    for(int i=1;i<=t;i++)
        cin>>x[i]>>y[i];
    if(t%n==0)
    {
        for(int i=1;i<=t;i++)
            ++a[x[i]];
        work(n);
    }
    if(t%m==0)
    {
        memset(a,0,sizeof a);
        for(int i=1;i<=t;i++)
            ++a[y[i]];
        work(m);
    }
    if(t%n==0&&t%m==0)
        cout<<"both "<<s;
    else if(t%n==0)
        cout<<"row "<<s;
    else if(t%m==0)
        cout<<"column "<<s;
    else
        cout<<"impossible";
    return 0;
}