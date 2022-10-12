#include<stdio.h>
#include<algorithm>
using namespace std;
struct point { long long a,b,c,h,pos,s; }a[500005],b[500005],p[500005];
int n,m[4],sum,s,t,c;
long long f[2][105][105][105][3];
inline bool cmp1(point x,point y) { return x.a>y.a; }
inline bool cmp2(point x,point y) { return x.b>y.b; }
inline bool cmp3(point x,point y) { return x.c>y.c; }
int main()
{
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);
    int i,j,k,l;
    scanf("%d%d%d%d",&n,&m[1],&m[2],&m[3]),sum=m[1]+m[2]+m[3];
    for(i=1;i<=n;i++) scanf("%I64d%I64d%I64d",&a[i].a,&a[i].b,&a[i].c),a[i].s=a[i].a+a[i].b+a[i].c,p[i]=a[i],p[i].pos=i;
    if(sum>n) { printf("I am a godlike cowcowcow\n"); return 0; }
    sort(p+1,p+1+n,cmp1);
    for(i=1;i<=sum;i++) b[++c]=a[p[i].pos],a[p[i].pos].h=1;
    sort(p+1,p+1+n,cmp2);
    for(i=1;i<=sum;i++) if(!a[p[i].pos].h) b[++c]=a[p[i].pos],a[p[i].pos].h=1;
    sort(p+1,p+1+n,cmp3);
    for(i=1;i<=sum;i++) if(!a[p[i].pos].h) b[++c]=a[p[i].pos],a[p[i].pos].h=1;
    for(t=l=1,s=0;l<=c;l++,s^=1,t^=1)
    {
      for(i=0;i<=m[1];i++)
        for(j=0;j<=m[2];j++)
          for(k=0;k<=m[3];k++) f[t][i][j][k][1]=f[t][i][j][k][2]=-(long long)2e60;
      for(i=0;i<=m[1];i++)
        for(j=0;j<=m[2];j++)
          for(k=0;k<=m[3];k++)
          {
            if((f[t][i][j][k][1]<f[s][i][j][k][1])||((f[t][i][j][k][1]==f[s][i][j][k][1])&&(f[t][i][j][k][2]<f[s][i][j][k][2])))
              f[t][i][j][k][1]=f[s][i][j][k][1],f[t][i][j][k][2]=f[s][i][j][k][2];
            //1
            if((i>0)&&(f[t][i][j][k][1]<f[s][i-1][j][k][1]+b[l].a))
              f[t][i][j][k][1]=f[s][i-1][j][k][1]+b[l].a,f[t][i][j][k][2]=f[s][i-1][j][k][2]+b[l].s;
            if((i>0)&&(f[t][i][j][k][1]==f[s][i-1][j][k][1]+b[l].a)&&(f[t][i][j][k][2]<f[s][i-1][j][k][2]+b[l].s))
              f[t][i][j][k][2]=f[s][i-1][j][k][2]+b[l].s;
            //2
            if((j>0)&&(f[t][i][j][k][1]<f[s][i][j-1][k][1]+b[l].b))
              f[t][i][j][k][1]=f[s][i][j-1][k][1]+b[l].b,f[t][i][j][k][2]=f[s][i][j-1][k][2]+b[l].s;
            if((j>0)&&(f[t][i][j][k][1]==f[s][i][j-1][k][1]+b[l].a)&&(f[t][i][j][k][2]<f[s][i][j-1][k][2]+b[l].s))
              f[t][i][j][k][2]=f[s][i][j-1][k][2]+b[l].s;
            //3
            if((k>0)&&(f[t][i][j][k][1]<f[s][i][j][k-1][1]+b[l].c))
              f[t][i][j][k][1]=f[s][i][j][k-1][1]+b[l].c,f[t][i][j][k][2]=f[s][i][j][k-1][2]+b[l].s;
            if((k>0)&&(f[t][i][j][k][1]==f[s][i][j][k-1][1]+b[l].c)&&(f[t][i][j][k][2]<f[s][i][j][k-1][2]+b[l].s))
              f[t][i][j][k][2]=f[s][i][j][k-1][2]+b[l].s;
          }
      /*for(i=0;i<=m[1];i++)
        for(j=0;j<=m[2];j++)
          for(k=0;k<=m[3];k++)
            printf("%d %d %d %d %d %d %d %d %d\n",l,b[l].a,b[l].b,b[l].c,i,j,k,f[t][i][j][k][1],f[t][i][j][k][2]);*/
    }
    printf("%I64d\n%I64d\n",f[s][m[1]][m[2]][m[3]][1],f[s][m[1]][m[2]][m[3]][2]);
    return 0;
}
