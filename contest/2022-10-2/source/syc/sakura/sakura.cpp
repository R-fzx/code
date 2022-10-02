#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5,mod=1e9+7;
int n,bk[maxn];
queue<int> q;
signed main()
{
    freopen("sakura.in","r",stdin);
    freopen("sakura.out","w",stdout);
    cin>>n;
    bk[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!bk[i])
        {
            for(int j=2;j*i<=n;j++)
                bk[j*i]=1;
        }
    } 
    for(int i=1;i<=n;i++)
    {
        if(!bk[i])
        {
            int k=n,t=0;
            while(k)
            {
                t+=k/i;
                k/=i;
            }
            q.push(t);
        }
    }
    int s=1;
    while(!q.empty())
    {
        s*=2*(q.front())%mod+1;
        s%=mod;
        q.pop();
    }
    cout<<s;
    // cout<<s<<' '<<tp<<endl;
    return 0;
}
// int s=0,qwq=1;
// for(int i=1;i<=n;qwq*=i,i++);
// int t=n,tp=0;
// for(int i=2;i<=qwq;i++)
// {
//     if(qwq%i==0)
//     {
//         while(qwq%i==0)
//         {
//             qwq/=i;
//             ++tp;
//         }
//     }
// }
// if(qwq!=1)
//     ++tp;