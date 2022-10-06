#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,l[10005][25],r[10005][25];
int check(int x,int y)
{
    int tp=0;
    for(int i=1;i<=n;i++)
    {
        int f=0,tmp=0;
        for(int j=max(l[i][0],r[i][0]);j>k;j--)
        {
            if(r[i][j]!=l[i][j])
            {
                if(r[i][j]>l[i][j])
                    tmp=1;
                break;
            }
        }
        if(tmp)
        {
            // cout<<"QWQ"<<endl;
            for(int j=k;j>=1;j--)
            {
                if(l[i][j]!=9)
                    tp=1;
                if(l[i][j]<=x&&y<l[i][j])
                    return 0;
            }
        }
        // else
        for(int j=k;j>=1;j--)
        {
            if(x==l[i][j]||x==r[i][j]||y==l[i][j]||y==r[i][j])
                tp=1;
            if(l[i][j]==r[i][j]&&l[i][j]==x)
                return 0;
            if(l[i][j]!=r[i][j])
                f=1;
            if(!f)
                continue;
            if(l[i][j]<=x&&x<r[i][j]&&y>=r[i][j])
            {
                int tp=0;
                for(int qwq=j-1;qwq>=1;qwq--)
                    if(l[i][qwq]!=9)
                        tp=1;
                if(tp)
                    return 0;
            }
            if(l[i][j]<x&&x<=r[i][j]&&y<=l[i][j])
            {
                int tp=0;
                for(int qwq=j-1;qwq>=1;qwq--)
                    if(l[i][qwq]!=0)
                        tp=1;
                if(tp)
                    return 0;
            }
            if(!(i==1&&r[i][j]-l[i][j]==1))
                tp=1;
            if(x<=r[i][j]&&y>r[i][j])
                return 0;
            if(x>=l[i][j]&&y<l[i][j])
                return 0; 
        }
    }
    if(!tp)
        return 0;
    return 1;
}
int fa[20];
int getfa(int x)
{
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int bk[15];
signed main()
{
    freopen("laser.in","r",stdin);
    freopen("laser.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=9;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        while(x)
        {
            l[i][++l[i][0]]=x%10;
            x/=10;
        }
        while(y)
        {
            r[i][++r[i][0]]=y%10;
            y/=10;
        }
        // for(int j=1;j<=l[i][0];j++)
        //     cout<<l[i][j]<<' '<<r[i][j];
        // cout<<endl;
    }
    // cout<<check(6,9)<<endl;
    for(int i=1;i<=9;i++)
        for(int j=i+1;j<=9;j++)
        {
            if(check(i,j)&&check(j,i))
            {
                // cout<<i<<' '<<j<<endl;
                int fx=getfa(i),fy=getfa(j);
                fa[fx]=fy;               
            }           
        }
    set<int> q[15];
    for(int i=1;i<=9;i++)
    {
        // cout<<getfa(i)<<endl;
        q[getfa(i)].insert(i);
    }
    for(int i=1;i<=9;i++)
    {
        int x=getfa(i);
        if(!bk[x])
        {
            while(!q[x].empty())
            {
                cout<<(*q[x].begin());
                q[x].erase(q[x].begin());
            }
            cout<<endl;
            bk[getfa(i)]=1;
        }
    }
    return 0;
}