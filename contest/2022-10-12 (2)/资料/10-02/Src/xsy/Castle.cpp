#include<stdio.h>
long long map[1001][1001],k[1001],dis[1001],v[1001];
int main()
{
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    long long a,b,c,m,n,i,j,q,min,ans=1;
    scanf("%I64d%I64d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        if(map[a][b]==0 || map[a][b]>c)
        {
            map[a][b]=c;
            map[b][a]=c;
        }
    }
    for(i=1;i<=n;i++)
        dis[i]=2147483640;
    dis[1]=0;dis[n+1]=2147483647;k[1]=1;
    for(q=1;q<=n;q++)
    {   
        min=n+1;
        for(i=1;i<=n;i++)
            if(dis[i]<dis[min] && v[i]==0)
                min=i;
        v[min]=1;
        for(i=1;i<=n;i++)
        {
            if(v[i]==0 && map[min][i]!=0 && dis[min]+map[min][i]<dis[i])
            {
                dis[i]=dis[min]+map[min][i];
                k[i]=1;
            }
            else if(v[i]==0 && map[min][i]!=0 && dis[min]+map[min][i]==dis[i])
                k[i]++;
        }
    }
    for(i=1;i<=n;i++)
    {
        ans*=k[i];
        ans%=2147483647;
    }
    printf("%I64d\n",ans);
    return 0;
}
