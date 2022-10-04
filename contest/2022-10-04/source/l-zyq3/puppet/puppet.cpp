#include<bits/stdc++.h>
#define int short
using namespace std;
int n,c[109],u[109],ans,uans;
inline int read(){
    int r(0);
    char ch(getchar());
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
    return r;
}
queue<pair<int,int> >q,_q;
inline void f(){
    for(;!q.empty();){
        auto cur(q.front());
        q.pop();
        if(u[cur.first+1]){
            int a(min(cur.second,u[cur.first+1]));
            cur.second-=a,u[cur.first+1]-=a;
        }
        if(cur.second){
            int a(min(cur.second,u[cur.first]));
            cur.second-=a,u[cur.first]-=a;
        }
        if(cur.second){
            int a(min(cur.second,u[cur.first-1]));
            cur.second-=a,u[cur.first-1]-=a;
        }
        uans+=cur.second;
    }
}
inline void work(){
    uans=0;
    f();
    ans+=uans,fill(u,&u[108],0);
}
signed main(){
    //freopen("puppet.in","r",stdin),freopen("puppet.out","w",stdout);
    while(cin>>n){
        fill(c,&c[108],0);
        for(int i(0);i<n;i++)c[read()]++;
        int last(0);
        while(!c[last])last++;
        last--;
        for(int i(last);i<=100;i++){
            if(c[i]){
                if(i-last>1)work();
                last=i;
                u[i]=c[i];
                q.push({i,c[i]});
            }
        }
        work();
        cout<<ans<<'\n';
    }
    return 0;
}