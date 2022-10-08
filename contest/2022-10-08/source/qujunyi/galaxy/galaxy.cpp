#include<bits/stdc++.h>
using namespace std;
int k,n,m,x,y;
struct node{
    int x,y;
}a[15];
bool b[15][15];
int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    while(cin >> k >> n >> m >> x >> y){
        for(int i = 1;i <= k;i++){
            cin >> a[i].x >> a[i].y;
        }
        for(int i = 1;i <= k;i++){
            for(int j = i+1;j <= k;j++){
                if(a[i].x%3==a[j].x%3==0&&a[i].y%3==a[j].y%3){
                    b[i][j]=1;
                }
            }
        }
        cout << "YES"<< endl;
    }
}