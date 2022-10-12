#include<stdio.h>
#include<stdlib.h>
long n,m,i,j,t,h,x,y,z,k;
long long ans;
long map[1001][1001],f[1001],dist[1001],a[10000001];
bool b[1001];
int main(){
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    scanf("%ld%ld",&n,&m);
    ans=1;
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j)
            map[i][j]=1000000000;
    for (i=1;i<=m;++i){
        scanf("%ld%ld%ld",&x,&y,&z);
        if (map[x][y]>z&&x!=y)
            map[x][y]=map[y][x]=z;
        }
    for (i=2;i<=n;++i){
        dist[i]=1000000000,f[i]=1;
        }
    h=0;t=1;a[1]=1;f[1]=1;
    for (t=1;t<=n;t++){
        k=2000000000;
        for (i=1;i<=n;i++)
            if (!b[i]&&k>dist[i])
                k=dist[i],j=i;
        if (k==2000000000)
            break;
        ans*=f[j];ans%=2147483647;b[j]=1;
        for (i=1;i<=n;i++)
            if (!b[i]&&map[j][i]+dist[j]<=dist[i])
                if (dist[j]+map[j][i]==dist[i])
                    f[i]++;
                else
                    f[i]=1,dist[i]=dist[j]+map[j][i];
        }
    printf("%ld\n",ans);
    return 0;
}
