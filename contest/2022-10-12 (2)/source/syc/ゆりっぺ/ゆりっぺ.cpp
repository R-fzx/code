/*
音无结弦之时
立于浮华之世
跃动天使之心
奏响天籁之音
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5,maxb=105;
struct node
{
    int a,b,c,tp;
}a[maxn];
int f[maxb][maxb][maxb][2],g[maxb][maxb][maxb][2],n,A,B,C;
int sum(node a)
{
    return a.a+a.b+a.c;
}
int cmpA(node s1,node s2)
{
    return s1.a==s2.a?sum(s1)>sum(s2):s1.a>s2.a;
}
int cmpB(node s1,node s2)
{
    return s1.b==s2.b?sum(s1)>sum(s2):s1.b>s2.b;
}
int cmpC(node s1,node s2)
{
    return s1.c==s2.c?sum(s1)>sum(s2):s1.c>s2.c;
}
node b[maxn];
int tn;
signed main()
{
    freopen("���ä�.in","r",stdin);
    freopen("���ä�.out","w",stdout);
    cin>>n>>A>>B>>C;
    if(A+B+C>n)
    {
        cout<<"I am a godlike cowcowcow";
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i].a>>a[i].b>>a[i].c;
    sort(a+1,a+n+1,cmpA);
    for(int i=1;i<=n;i++)
    {
        if(tn==A+B+C)
            break;
        a[i].tp=1;
        b[++tn]=a[i];
    }
    sort(a+1,a+n+1,cmpB);
    for(int i=1;i<=n;i++)
    {
        if(a[i].tp)
            continue;
        if(tn==2*(A+B+C))
            break;
        a[i].tp=1;
        b[++tn]=a[i];
    }
    sort(a+1,a+n+1,cmpC);
    for(int i=1;i<=n;i++)
    {
        if(a[i].tp)
            continue;
        if(tn==3*(A+B+C))
            break;
        a[i].tp=1;
        b[++tn]=a[i];
    }
    int op=0;
    for(int i=1;i<=tn;i++)
    {
        // cout<<b[i].a<<' '<<b[i].b<<' '<<b[i].c<<endl;
        op^=1;
        for(int j=0;j<=A;j++)
            for(int k=0;k<=B;k++)
                for(int l=0;l<=B;l++)
                {
                    f[j][k][l][op]=f[j][k][l][op^1];
                    g[j][k][l][op]=g[j][k][l][op^1];
                    if(k>=1)
                    {
                        if(f[j][k-1][l][op^1]+b[i].b>f[j][k][l][op]||f[j][k-1][l][op^1]+b[i].b==f[j][k][l][op]&&sum(b[i])+g[j][k-1][l][op^1]>g[j][k][l][op])
                        {
                            f[j][k][l][op]=f[j][k-1][l][op^1]+b[i].b;
                            g[j][k][l][op]=g[j][k-1][l][op^1]+sum(b[i]);
                            // cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<f[j][k-1][l][op^1]<<' '<<b[i].b<<' '<<f[j][k][l][op]<<endl;
                        } 
                    }
                    if(j>=1)
                    {
                        if(f[j-1][k][l][op^1]+b[i].a>f[j][k][l][op]||f[j-1][k][l][op^1]+b[i].a==f[j][k][l][op]&&sum(b[i])+g[j-1][k][l][op^1]>g[j][k][l][op])
                        {
                            f[j][k][l][op]=f[j-1][k][l][op^1]+b[i].a;
                            g[j][k][l][op]=g[j-1][k][l][op^1]+sum(b[i]);
                        }
                        
                    }
                    if(l>=1)
                    {
                        if(f[j][k][l-1][op^1]+b[i].c>f[j][k][l][op]||f[j][k][l-1][op^1]+b[i].c==f[j][k][l][op]&&sum(b[i])+g[j][k][l-1][op^1]>g[j][k][l][op])
                        {
                            f[j][k][l][op]=f[j][k][l-1][op^1]+b[i].c;
                            g[j][k][l][op]=g[j][k][l-1][op^1]+sum(b[i]);
                        }
                    }
                }
        // cout<<f[1][1][0][op]<<endl;
    }
    cout<<f[A][B][C][op]<<endl<<g[A][B][C][op];
    return 0;
}
