#include<bits/stdc++.h>
#include<conio.h>
#define x first
#define y second
#define W(p) p.x*nv+p.y
using namespace std;
int T,R,C,ed[109][109],tot(1);
const pair<int,int>w[4]={{1,0},{0,1},{-1,0},{0,-1}},c[4]={{1,0},{0,1},{1,0},{0,1}};
pair<int,int>s,t,ncnt,m[109][109]/*用tot判覆盖*/;
bool b[109][109]/*会覆盖*/;
double L,lv,nv,nans;
const double d(1e-7);
inline pair<int,int> operator+(pair<int,int>a,pair<int,int>b){
    return {a.x+b.x,a.y+b.y};
}
inline double distance(pair<int,int>p){
    return abs(p.x-t.x)*nv+abs(p.y-t.y);
}
inline int read(){
    int r(0);
    char ch(getchar());
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')r=(r<<1)+(r<<3)+ch-'0',ch=getchar();
    return r;
}
struct Node{
    pair<int,int>p,c;//坐标  代价
    inline double h()const{
        return distance(p)+W(c);
    }
    inline const bool operator<(const Node x)const{
        return h()==x.h()?distance(p)>distance(x.p):h()>x.h();
    }
};
inline bool _equal(pair<int,int>a,pair<int,int>b){return a.x==b.x&&a.y==b.y;}
inline bool _judge(Node x){
    return x.p.x<0||x.p.x>=R||x.p.y<0||x.p.y>=C||b[x.p.x][x.p.y]||x.h()>=nans||(ed[x.p.x][x.p.y]==tot?(_equal(m[x.p.x][x.p.y],x.c)||W(m[x.p.x][x.p.y])<=W(x.c)):false);
}
inline void dfs(){
    priority_queue<Node>q;
    q.push({s,{0,0}});
    m[s.x][s.y]={0,0},ed[s.x][s.y]=tot;
    while(!q.empty()){
        Node x(q.top());
        //cout<<nans<<' '<<t.x<<' '<<t.y<<' '<<x.p.x<<' '<<x.p.y<<' '<<W(x.c)<<' '<<x.h()<<'\n';//<<' '<<x.c.x<<' '<<x.c.y<<' '<<W(x.c)<<'\n';
        //getch();
        q.pop();
        for(int i(0);i<4;i++){
            Node _x({x.p+w[i],x.c+c[i]});
            if(_judge(_x))continue;
            //if(ed[_x.p.x][_x.p.y]==tot)cout<<W(_x.c)<<' '<<nans<<' '<<_x.p.x<<' '<<_x.p.y<<' '<<m[_x.p.x][_x.p.y].x<<' '<<m[_x.p.x][_x.p.y].y<<':'<<_x.c.x<<' '<<_x.c.y<<'\n',getch();
            ed[_x.p.x][_x.p.y]=tot,m[_x.p.x][_x.p.y]=_x.c;
            q.push(_x);
            if(_equal(_x.p,t))ncnt=_x.c,nans=W(_x.c);
        }
    }
}
inline void check(double v){
    nv=v,nans=W(ncnt);
    if((v>=1)^(lv>=1))tot++,dfs();
    lv=v;
}
int main(){
    freopen("maze.in","r",stdin),freopen("maze.out","w",stdout);
    int start(clock());
    T=read();
    while(T--){
        cin>>L;
        R=read(),C=read();
        for(int i(0);i<R;i++){
            string str;
            getline(cin,str);
            if(!str.size()){i--;continue;}
            for(int j(0);j<C;j++){
                b[i][j]=str[j]=='#';
                if(str[j]=='S')s={i,j};
                if(str[j]=='E')t={i,j};
            }
        }
        ncnt={9+1e4,9+1e4},lv=0;
        double l(0),r(9.9999999999);
        while(l<r){
            double mid((l+r)/2.0);
            check(mid);
            //printf("%0.5f %0.5f\n",mid,nans);
            if(abs(nans-L)<d){
                printf("%0.5f\n",mid);
                break;
            }else if(nans<L){
                l=mid;
            }else{
                r=mid;
            }
            //puts(""),getch();
        }
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
#  ## #    #
#     #    #
############
*/