#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,A,B,C,D,a,b,M,ans,u[10009],v[100009];
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
//1145 2 5 2 5 89 97 1000000007
//10 2 5 2 5 89 97 1000000007
signed main(){                    
    scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&D,&a,&b,&M);
    int x(a),y(b);
    u[0]=a,v[0]=b;
    //cout<<a<<' '<<b<<'\n';
    for(int i(1);i<n;i++){
        x=(A*x+B)%M,y=(C*y+D)%M;
        u[i]=x,v[i]=y;
        //cout<<x<<' '<<y<<'\n';
    }
    for(int i(0);i<n;i++){
        for(int j(i+1);j<n;j++){
            for(int k(j+1);k<n;k++){
                if((u[i]+u[j]+u[k])%3==0&&(v[i]+v[j]+v[k])%3==0){
                    //cout<<i<<' '<<j<<' '<<k<<'\n';
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}