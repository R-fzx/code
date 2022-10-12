#include<stdio.h>
#include<stdlib.h>

FILE *fin,*fout;

int dist[1001];
int n,m;
int q[10001];
bool inq[1001];
int a[1001][1001];

int min(int x,int y)
{
    return x<y?x:y;
}
int main()
{
    int i,j,k;
    fin=fopen("Castle.in","r");
    fout=fopen("Castle.out","w");
    
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=214748364;
    for(i=1;i<=m;i++)
    {
        int x,y,z;
        fscanf(fin,"%d %d %d",&x,&y,&z);
        if(x==y)
            continue;
        a[x][y]=a[y][x]=min(a[x][y],z);
    }
    for(i=1;i<=n;i++)
        dist[i]=214748364;
    int h,t;
    h=0;t=1;
    q[t]=1;
    inq[1]=true;
    dist[1]=0;
    while(h<t)
    {
        ++h;
        inq[q[h]]=false;
        for(i=1;i<=n;i++)
            if(a[q[h]][i]!=0 && a[q[h]][i]+dist[q[h]]<dist[i])
            {
                dist[i]=a[q[h]][i]+dist[q[h]];
                if(!inq[i])
                {
                    q[++t]=i;
                    inq[i]=true;
                }
            }
    }
    long long tot=1;
    for(i=2;i<=n;i++)
    {
        long long k=0;
        for(j=1;j<=n;j++)
            if(a[i][j]!=214748364 && dist[j]+a[j][i]==dist[i])
            {
                //fprintf(fout,"%d %d %d %d %d\n",i,j,dist[j],a[i][j],dist[i]);
                k++;
            }
        tot*=k;
        tot%=2147483647;
        //fprintf(fout,"%lld\n",tot);
    }
    fprintf(fout,"%lld\n",tot);
    fclose(fin);
    fclose(fout);
    return 0;
}
