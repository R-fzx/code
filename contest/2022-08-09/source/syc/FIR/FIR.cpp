#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n,k,bk[maxn][maxn],x[maxn],y[maxn],id[maxn*maxn],fa[maxn*maxn],q[maxn*maxn],m=1100;
int getnum(int x,int y)
{
    return (x-1)*m+y;
}
int getfa(int x)
{
    return fa[x]==x||fa[x]==0?x:fa[x]=getfa(fa[x]);
}
int tp[5],tot;
void tz(int xx)
{
    queue<int> qq;
    for(int i=1;i<xx;i++)
    {
        int f=getfa(getnum(x[i],y[i]));
        // cout<<i<<' '<<f<<endl;
        if(bk[x[i]][y[i]]!=i)
            continue;
        if(q[f]==0)
            fa[f]=0,bk[x[i]][y[i]]=0;
        if(fa[f]==0)
        {
            // cout<<"###"<<i<<' '<<getfa(i)endl;
            bk[x[i]][y[i]]=0;
            q[getnum(x[i],y[i])]=0;
            qq.push(i);
        }   
    }
    while(!qq.empty())
    {
        int i=qq.front();
        fa[getnum(x[i],y[i])]=0,qq.pop();
        tot=0;
        // cout<<qq.front()<<endl;
        if(bk[x[i]+1][y[i]])
            tp[++tot]=getfa(getnum(x[i]+1,y[i]));
        if(bk[x[i]-1][y[i]])
            tp[++tot]=getfa(getnum(x[i]-1,y[i]));
        if(bk[x[i]][y[i]+1])
            tp[++tot]=getfa(getnum(x[i],y[i]+1));
        if(bk[x[i]][y[i]-1])
            tp[++tot]=getfa(getnum(x[i],y[i]-1));
        // cout<<"###"<<bk[x[i]][y[i]-1]<<' '<<x[i]<<' '<<y[i]<<endl;
        sort(tp+1,tp+tot+1);
        tot=unique(tp+1,tp+tot+1)-tp-1;
        for(int i=1;i<=tot;i++)
        {
            ++q[tp[i]];
            // cout<<tp[i]<<' '<<q[tp[i]]<<endl;
        }
    }
}
int ans=0;
int check(int xx)
{
    for(int i=1;i<=xx;i++)
    {
        if(bk[x[i]][y[i]]==i)
        {
            int t=0;
            for(int j=y[i];j<=min(m,y[i]+k);j++)
                if(id[bk[x[i]][j]]==id[i])
                    ++t;
                else
                    break;
            for(int j=y[i]-1;j>=max(1,y[i]-1-k);j--)
                if(id[bk[x[i]][j]]==id[i])
                    ++t;
                else
                    break;
            if(t>=k)
                return id[i];
            t=0;
            for(int j=x[i];j<=min(m,x[i]+k);j++)
                if(id[bk[j][y[i]]]==id[i])
                    ++t;
                else
                    break;
            for(int j=x[i]-1;j>=max(1,x[i]-1-k);j--)
                if(id[bk[j][y[i]]]==id[i])
                    ++t;
                else
                    break;
            if(t>=k)
                return id[i];
            t=0;
            int qwq=x[i],qaq=y[i];
            while(qwq<=min(m,x[i]+k)&&qaq<=min(m,y[i]+k))
            {
                if(id[bk[qwq][qaq]]==id[i])
                    ++t;       
                else
                    break;
                ++qwq,++qaq;
            }
            qwq=x[i],qaq=y[i];
            while(qwq-1>=max(1,x[i]-1-k)&&qaq>=max(1,y[i]-1-k))
            {
                if(id[bk[qwq][qaq]]==id[i])
                    ++t;       
                else
                    break;
                --qwq,--qaq;
            }
            if(t>=k)
                return id[i];
        }
    }
    return -1;
}
int main()
{
    freopen("FIR.in","r",stdin);
    freopen("FIR.out","w",stdout);
    id[0]=-1;
    cin>>n>>k; 
    int f=0;
    for(int i=1;i<=n;i++)
    {
        id[i]=i&1;
        cin>>x[i]>>y[i];
        tot=0;
        if(bk[x[i]][y[i]])
        {
            f=1;
            cout<<"illegal";
            return 0;
        }
        fa[getnum(x[i],y[i])]=getnum(x[i],y[i]);
        bk[x[i]][y[i]]=i;
        if(!bk[x[i]+1][y[i]])
            ++q[getnum(x[i],y[i])];
        else 
        {
            if(id[bk[x[i]+1][y[i]]]==id[i])
                tp[++tot]=getfa(getnum(x[i]+1,y[i]));
            --q[getfa(getnum(x[i]+1,y[i]))];
        }
        if(!bk[x[i]-1][y[i]])
            ++q[getnum(x[i],y[i])];
        else
        {
            if(id[bk[x[i]-1][y[i]]]==id[i])
                tp[++tot]=getfa(getnum(x[i]-1,y[i]));
            --q[getfa(getnum(x[i]-1,y[i]))];
        }
        if(!bk[x[i]][y[i]+1])
            ++q[getnum(x[i],y[i])];
        else
        {
            if(id[bk[x[i]][y[i]+1]]==id[i])
                tp[++tot]=getfa(getnum(x[i],y[i]+1));
            --q[getfa(getnum(x[i],y[i]+1))];
        }
        if(!bk[x[i]][y[i]-1])
            ++q[getnum(x[i],y[i])];
        else
        {
            if(id[bk[x[i]][y[i]-1]]==id[i])
                tp[++tot]=getfa(getnum(x[i],y[i]-1));
            --q[getnum(x[i],y[i]-1)];
        }
        if(tot)
        {
            sort(tp+1,tp+tot+1);
            tot=unique(tp+1,tp+tot+1)-tp-1;
            for(int i=2;i<=tot;i++)
            {
                fa[tp[i]]=fa[tp[1]];
                q[tp[1]]+=q[tp[i]];
            }
            fa[getnum(x[i],y[i])]=tp[1];
            q[tp[1]]+=q[getnum(x[i],y[i])];
        }
        else
            tp[1]=getnum(x[i],y[i]);
        // cout<<getnum(x[i],y[i])<<' '<<q[getnum(x[i],y[i])]<<endl;
        tz(i);
        if(q[tp[1]]==0)
        {
            cout<<"illegal"; 
            return 0;
            f=1;
        }
        int xx=check(i);
        if(xx!=-1)
        {
            if(xx)
            {
                cout<<"ITer "<<i; 
            }
            else
            {
                cout<<"Kitty "<<i; 
            }
            return 0;
        } 
        // cout<<"qwq"<<x[i]<<' '<<y[i]<<endl;
        // cout<<x[i]<<' '<<y[i]<<endl;
        // for(int i=1;i<=10;puts(""),i++)
        //     for(int j=1;j<=10;j++)
        //         if(!bk[i][j])
        //             cout<<"#";
        //         else
        //             cout<<id[bk[i][j]];
    }
    cout<<"draw";
    return 0;
}
/*
100 5 
5 5
1 1
5 4
5 3
3 3
4 4
4 3
4 5
1 2
5 6
5 2
6 4
1 3
6 5
6 3
1 4 
5 4

*/