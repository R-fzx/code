#include<stdio.h>
long map[202][202];
void shu(long x,long a,long b)
{
    long i,j,k,q,w;
    if(a>b)
    {
        q=b;w=a;
    }
    if(a<b)
    {
        q=a;w=b;
    }
    for(i=q;i<=w;i++)
        map[i][x]=1;
    map[i][x]=2;
    if((w-q+1)%3==0)
    {
        if(a>b)
        {
            shu(a-(a-b+1)/3,x+1,x+(a-b+1)/3);
            shu(a-(a-b+1)/3,x-1,x-(a-b+1)/3);
        }
        else
        {
            shu(b-(b-a+1)/3,x+1,x+(b-a+1)/3);
            shu(b-(b-a+1)/3,x-1,x-(b-a+1)/3);
        }
    }
    return;
}
void heng(long x,long a,long b)
{
    long i,j,k,q,w;
    if(a>b)
    {
        q=b;w=a;
    }
    if(a<b)
    {
        q=a;w=b;
    }
    for(i=q;i<=w;i++)
        map[x][i]=1;
    map[x][w]=2;
    if((w-q+1)%3==0)
    {
        if(a>b)
        {
            shu(a-(a-b+1)/3,x+1,x+(a-b+1)/3);
            shu(a-(a-b+1)/3,x-1,x-(a-b+1)/3);
        }
        else
        {
            shu(b-(b-a+1)/3,x+1,x+(b-a+1)/3);
            shu(b-(b-a+1)/3,x-1,x-(b-a+1)/3);
        }
    }
    return;
}
int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    long i,j,k,x1,x2,y1,y2;
    double ans=0;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x1+=100;
    y1+=100;
    x2+=100;
    y2+=100;
    heng(100,101,181);
    k=0;
    for(i=x1;i<=x2;i++)
        for(j=y1;j<=y2;j++)
        {
            if(map[i][j]==2)
                k++;
            if(map[i][j]==1)
                ans++;
        }
    ans+=k*330;
    printf("%0.1lf",ans);
    return 0;
}

