#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,A,B,C,D,a,b,M,cnt[3][3],ans;
/*
n,A,B,C,D,x0,y0,M,

X=x0,Y=y0
For i=1 to n-1{
X=(A*X+B)mod M
Y=(C*Y+D)mod M
xi=X,yi=Y;
}
*/
//114514 1 9 1 9 8 1 114514191
//20 6 9 6 9 8 6 14
//250 2 5 2 5 89 97 1000000007
//50 2 5 2 5 89 97 1000000007
signed main(){                    
    scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&D,&a,&b,&M);
    int x(a),y(b);
    cnt[x%3][y%3]++;
    for(int i(1);i<n;i++){
        x=(A*x+B)%M,y=(C*y+D)%M;
        cnt[x%3][y%3]++;
        //cout<<x<<' '<<y<<'\n';
    }
    for(int i(0);i<3;i++){
        for(int j(0);j<3;j++){
            for(int k(0);k<3;k++){
                for(int l(0);l<3;l++){
                    for(int o(0);o<3;o++){
                        for(int p(0);p<3;p++){
                            if(((i+j+k)%3==0)&&((p+l+o)%3==0)){
                                //printf("%d,%d %d,%d %d,%d\n",i,l,j,o,k,p);
                                if(i==j&&l==o)ans+=cnt[i][l]*(cnt[i][l]-1)*(cnt[i][l]-2);
                                else ans+=cnt[i][l]*cnt[j][o]*cnt[k][p];
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans/6;
    return 0;
}