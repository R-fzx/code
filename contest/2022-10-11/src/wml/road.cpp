#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

struct ss{
       int a,b,u,v,count_uv;
       }map[50047];

int n,m,P,Q,fa[247],ans,len,co,max_P,max_Q;

inline bool cmp(ss i,ss j)
{
       return (i.count_uv<j.count_uv);
}

inline int getfa(int i)
{
       if(fa[i]==i)
         return i;

       int now_fa=getfa(fa[i]);

       fa[i]=now_fa;

       return now_fa;
}

bool rs(int p,int q)
{
     int fa_p=getfa(p),fa_q=getfa(q);

     if(fa_p==fa_q)
       return 0;

     if(fa_q==q)
       fa[q]=fa_p;

     else if(fa_p==p)
       fa[p]=fa_q;

     else
       fa[q]=fa_p;

     return 1;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>P>>Q;

    for(int i=1;i<=m;i++)
    {
       int a1,b1,u1,v1;
    
       scanf("%d%d%d%d",&a1,&b1,&u1,&v1);
    
       if(a1!=b1)
         map[++len]=(ss){a1,b1,u1,v1,u1*P+v1*Q};
    }

    sort(map+1,map+1+len,cmp);

    for(int i=1;i<=n;i++)
       fa[i]=i;

    for(int i=1;i<=len;i++)
       if(rs(map[i].a,map[i].b))
         max_P=max(max_P,map[i].u),
       
         max_Q=max(max_Q,map[i].v);

    ans=max_P*P+max_Q*Q;

    for(int i=1;i<=n;i++)
       if(fa[i]==i)
         co++;

    if(co>=2)
    {
      cout<<-1<<endl;
    
      return 0;
    }
    
    //cout<<max_P<<' '<<max_Q<<endl;

    cout<<ans<<endl;

    return 0;
}
