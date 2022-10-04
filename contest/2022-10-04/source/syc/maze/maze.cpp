#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node
{
    int v,nxt;
    double w;
}e[maxn<<1];
int tot,head[maxn];
void add(int x,int y,double w)
{
    e[++tot].v=y;
    e[tot].nxt=head[x];
    head[x]=tot;
    e[tot].w=w;
}
int T,n,m,s,E;
double l;
string a[505];
int get(int i,int j)
{
    return (i-1)*m+j;
}
struct diji
{
    int x,di;
    bool operator<(diji s2)const
    {
        return x>s2.x;
    }
};
double dis[maxn];
double dij()
{
    for(int i=1;i<=n*m;i++)
        dis[i]=692608;
    priority_queue<diji> q;
    dis[s]=0;
    // cout<<dis[s]<<endl;
    q.push((diji){s,0});
    while(!q.empty())
    {
        int x=q.top().x;
        // cout<<x<<' '<<dis[x]<<endl;
        q.pop();
        for(int i=head[x];i;i=e[i].nxt)
        {
            int v=e[i].v;
            // cout<<x<<' '<<v<<endl;
            if(dis[v]>dis[x]+e[i].w)
            {
                // cout<<v<<' '<<dis[x]<<' '<<e[i].w<<endl;
                dis[v]=dis[x]+e[i].w;
                q.push((diji){v,dis[v]});
            }
        }
    }
    // cout<<dis[E]<<endl;
    return dis[E];
}
int check(double x)
{
    double tw=x;
    // cout<<tw<<endl;
    for(int i=1;i<=tot;i++)
        e[i].w=e[i].v=e[i].nxt=0;
    tot=0;
    memset(head,0,sizeof head);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==' '||a[i][j]=='S'||a[i][j]=='E')
            {
                // cout<<"QWQ"<<endl;
                if(a[i+1][j]!='#')
                    add(get(i,j),get(i+1,j),tw);
                if(a[i-1][j]!='#')
                    add(get(i,j),get(i-1,j),tw);
                if(a[i][j+1]!='#')
                    add(get(i,j),get(i,j+1),1);
                if(a[i][j-1]!='#')
                    add(get(i,j),get(i,j-1),1);
            }
    // cout<<x<<' '<<dij()<<endl;
    return dij()>=l;
}
const double eps=1e-7;
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>l>>n>>m;
        getline(cin,a[1]);
        for(int i=1;i<=n;i++)
        {
            // getchar(); 
            getline(cin,a[i]);
            // cout<<a[i]<<endl;
            // if(i!=n)
            // for(int j=m;j>=1;j--)
            //     a[i][j]=a[i][j-1];
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]=='S')
                    s=get(i,j);
                if(a[i][j]=='E')
                    E=get(i,j);
            }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<a[i][j];
        //     cout<<endl;
        // }
        // cout<<"QWQ";
        double ans=0,l=0,r=10;
        while(r-l>1e-7)
        {
            double mid=(l+r)/2.0;
            if(check(mid))
                r=mid-eps,ans=mid;
            else
                l=mid+eps;
        }  
        printf("%.5lf\n",ans);
        // cout<<check(0.21053)<<endl;
        // printf("%.5lf",double(ans)/10000000.0);
    }
    return 0;
}
/*
2
2.5 4 5
#####
#S  #
#  E#
#####
21 13 12
############
#S##     #E#
# ##  #  # #
#   # #  # #
### # #  # #
#   # #  # #
#  ## #  # #
##  # #  # #
### # #  # #
##  # #  # #
#   # #  # #
#     #    #
############ 
*/