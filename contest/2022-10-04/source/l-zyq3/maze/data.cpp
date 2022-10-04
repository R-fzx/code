#include<bits/stdc++.h>
#include<conio.h>
#define x first
#define y second
using namespace std;
int T,R,C;
double L;
pair<int,int>s,t;
inline int r(){
    int cur(100);
    cout<<cur<<' ';
    return cur;
}
int main(){
    freopen("maze.in","w",stdout);
    srand(time(0));
    T=1;
    cout<<1;
    puts("");
    while(T--){
        L=rand()*10/(double)rand();
        cout<<233<<' ';
        R=r(),C=r();
        puts("");
        //s={rand()%R,rand()%C},t={rand()%R,rand()%C};
        s={1,1},t={98,98};
        for(int i(0);i<R;i++){
            for(int j(0);j<C;j++){
                if(s.x==i&&s.y==j)cout<<'S';
                else if(t.x==i&&t.y==j)cout<<'E';
                else cout<<(i!=0&&i!=R-1&&j!=0&&j!=C-1?(((((i%j&&(i>1||(j%14==7&&j!=91)))||i>j+1)&&(j%7==0))||(j==91&&i>50))?'#':' '):'#');
            }
            puts("");
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