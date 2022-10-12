#include<stdio.h>
long tree[1010][3],f[1010],c[1010][1010];
void find(long x)
{
    long i,j,k1,k2,s1=0,s2=0;
    if(tree[x][1]==0 && tree[x][2]==0)
    {
        tree[x][0]=1;
        f[x]=1;
        return;
    }
    if(tree[x][1]==0)
        k1=1;
    else
    {
        find(tree[x][1]);
        k1=f[tree[x][1]];
        s1=tree[tree[x][1]][0];
    }
    if(tree[x][2]==0)
        k2=1;
    else
    {
        find(tree[x][2]);
        k2=f[tree[x][2]];
        s2=tree[tree[x][2]][0];
    }
    f[x]=(k1*k2)%10007;
    f[x]=(c[s1+s2+1][s1+1]*f[x])%10007;
    tree[x][0]=s1+s2+1;
    return;
}
int main()
{
    freopen("t1.in","r",stdin);
    freopen("t1.out","w",stdout);
    long i,j,k,n,t,q;
    scanf("%d",&t);
    c[1][1]=1;
    for(i=2;i<=1001;i++)
        for(j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%10007;
    for(;t>=1;t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            tree[i][0]=0;
            tree[i][1]=0;
            tree[i][2]=0;
            f[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            if(k>0)
            {
                scanf("%d",&q);
                tree[i][1]=q;
            }
            for(j=2;j<=k;j++)
            {
                scanf("%d",&tree[q][2]);
                q=tree[q][2];
            }
        }
        find(1);
        printf("%d\n",f[1]);
    }
    return 0; 
}
