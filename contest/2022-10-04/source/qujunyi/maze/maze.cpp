#include<bits/stdc++.h>
using namespace std;
int n,m;
double s;
string a[105];
int e[105][105];
pair<int,int> w[10005];
int fx[4]={0,0,1,-1};
int fy[4]={1,-1,0,0};
double b[105][106];
double fz[4];
double eps = 0.0000001;
double check(double x){
    fz[1]=fz[0]=1;
    fz[2]=fz[3]=x;
    int sx,sy,ex,ey;
    priority_queue<pair<double,int> > q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            b[i][j]=1e9;
            if(a[i][j] == 'S'){
                sx=i,sy=j;
            }
            if(a[i][j] == 'E'){
                ex=i,ey=j;
            }
        }
    }
    //cout << sx << " "<< sy <<" "<<ex<<" "<< ey<< endl;
    pair<double,int> p;
    p.first = 0,p.second = e[sx][sy];
    b[sx][sy] = 0;
    q.push(p);
    while(!q.empty()){
        int x = w[q.top().second].first,y = w[q.top().second].second;
        double z = q.top().first;
        //cout << x << " "<< y << " "<< z << endl;
        if(b[x][y]<z){
            continue;;
        }
        q.pop();
        for(int i = 0;i < 4;i++){
            int sx=x+fx[i],sy=y+fy[i];
            double sz = z + fz[i];
            //cout << sx << " "<< sy << " "<< sz << endl;
            if(sx>=0&&sx<n&&sy>=0&&sy<m&&b[sx][sy]>sz&&a[sx][sy]!='#'){
                b[sx][sy]=sz;
                pair<double,int> ee;
                ee.first = sz;
                ee.second = e[sx][sy];
                q.push(ee);
            }
        }
    }
    //cout << b[ex][ey]<< endl;
    return b[ex][ey];
}
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    int sum = 0;
    for(int i = 0;i <= 100;i++){
        for(int j = 0;j <= 100;j++){
            e[i][j]=++sum;
            w[sum].first = i;
            w[sum].second = j;
        }
    }
    int t;
    cin >> t;
    while(t--){
        cin>> s >> n >> m;
            getline(cin,a[101]);
        for(int i = 0;i < n;i++){
            getline(cin,a[i]);
            //cout << a[i]<< endl;
        }
        //cout << eps<< endl;
        double l=0,r=10;
        while(r-l >=eps){ 
            double mid = (l+r)/(double)2;
        	//cout << l << " "<< r <<" "<< mid<< " "; 
            if(check(mid)>=s){
            	//cout <<"KLKL"<< endl;
                r=mid-eps;
            }else{
                l=mid+eps;
            }
            //cout << endl<< endl;
        }
        printf("%.5lf\n",r+eps);
    }
}
