#include<bits/stdc++.h>
#define inf 1000000010
using namespace std;
const int maxn=100010;
int n;
int Minx,Miny,Minz,Maxx,Maxy,Maxz;
struct E{
    int lx,ly,lz,rx,ry,rz;
}a[maxn];
struct S{
    int x,y,z;
};
bool operator<(S kkk,S KKK){
    return kkk.x<KKK.x;
}
bool m[1000000];
int main(){
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);
    ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    Minx=inf;
    Miny=inf;
    Minz=inf;
    Maxx=-inf;
    Maxy=-inf;
    Maxz=-inf;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].lx>>a[i].ly>>a[i].lz>>a[i].rx>>a[i].ry>>a[i].rz;
        Minx=min(Minx,a[i].lx);
        Miny=min(Miny,a[i].ly);
        Minz=min(Minz,a[i].lz);
        Maxx=max(Maxx,a[i].rx);
        Maxy=max(Maxy,a[i].ry);
        Maxz=max(Maxz,a[i].rz);
    }
    for(int I=1;I<=n;I++){
        E tmp;
        int maxx=-inf,maxy=-inf,maxz=-inf,minx=inf,miny=inf,minz=inf;
        for(int j=1;j<=n;j++){
            if(j==I)continue;
            minx=min(minx,a[j].lx);
            miny=min(miny,a[j].ly);
            minz=min(minz,a[j].lz);
            maxx=max(maxx,a[j].rx);
            maxy=max(maxy,a[j].ry);
            maxz=max(maxz,a[j].rz);
        }
        for(int i=minx;i<=maxx;i++)
            for(int j=miny;j<=maxy;j++)
                for(int k=minz;k<=maxz;k++){
                    m[i*2500+j*50+k]=1;
                } 
    }
    unsigned long long ans=0;
    for(int i=Minx;i<=Maxx;i++){
        for(int j=Miny;j<=Maxy;j++){
            for(int k=Minz;k<=Maxz;k++){
                if(m[i*2500+j*50+k])ans++;
            }
        }
    } 
    cout<<ans/2;
    return 0;
}