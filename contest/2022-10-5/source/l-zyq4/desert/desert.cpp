#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int tx[8]={1,-1,1,-1,0,0,1,-1},ty[8]={1,-1,-1,1,1,-1,0,0};
int n,m[59][59],rnk[59][59],f[2509],cnt(1),si,sj,s,ans(-1);
unordered_map<int,int>mp[2509];
bool c[2509],d[2509];
vector<pair<int,int> >v[2509];
inline void add(int x,int y,int k){
    mp[x][y]=v[x].size(),mp[y][x]=v[y].size();
    v[x].push_back({1,y}),v[y].push_back({1,x});
}
struct Node{
    int num,w,fa;
    inline const bool operator<(const Node x)const{
        return w>x.w;
    }
};
signed main(){              
    freopen("desert.in","r",stdin),freopen("desert.out","w",stdout);
    cin>>n;
    for(int i(0);i<n;i++){
        for(int j(0);j<n;j++){
            char ch;
            cin>>ch;
            m[i][j]=(ch=='X'?-1:(ch=='*'?1:0));
            if(ch=='@')si=i,sj=j;
        }
    }
    for(int i(0);i<n;i++){
        for(int j(0);j<n;j++){
            if(m[i][j]==-1)continue;
            if(si==i&&sj==j)s=cnt;
            f[cnt]=LONG_LONG_MAX;
            //cout<<i<<' '<<j<<' '<<cnt<<' '<<'\n';
            c[cnt]=m[i][j],rnk[i][j]=cnt++;
        }
    }
    for(int i(0);i<n;i++){
        for(int j(0);j<n;j++){
            if(!rnk[i][j])continue;
            for(int k(0);k<8;k++){
                int _i(i+tx[k]),_j(j+ty[k]);
                if(_i<0||_j<0||(!rnk[_i][_j]))continue;
                add(rnk[i][j],rnk[_i][_j],k);
            }
        }
    }
    priority_queue<Node>q;
    d[s]=true;
    q.push({s,0,s});
    int nans(-1);
    while(!q.empty()){
        Node cur(q.top());
        q.pop();
        //cout<<cur.num<<' '<<cur.w<<'\n';
        if(c[cur.num]){
            nans=cur.w;
            break;
        }
        if(f[cur.num]!=LONG_LONG_MAX)continue;
        if(!d[cur.fa]){
            q.push({cur.fa,cur.w-1,s});
            d[cur.fa]=true;
            v[cur.fa][mp[cur.fa][cur.num]].x=3;
            continue;
        }
        f[cur.num]=cur.w;
        for(int i(0);i<v[cur.num].size();i++){
            //cout<<cur.num<<' '<<v[cur.num][i].x<<' '<<v[cur.num][i].y<<'\n';
            q.push({v[cur.num][i].y,cur.w+v[cur.num][i].x,cur.num});
        }
    }
    cout<<nans;
    return 0;
}