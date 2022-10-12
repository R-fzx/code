#include<stdio.h>
#include<stdlib.h>
const int MAXN = 1020;
const int oo = (1 << 11) - 1;
char Link[MAXN][MAXN];
int Dis[MAXN],q[oo],v[MAXN];
struct fetch
{
       int y;
       int Dis;
       fetch *next;
}*f[MAXN],Me[MAXN * MAXN];
int Du[MAXN],use = 0;
int N,M;
void L(int x,int y,int Dis)
{
     fetch *Tmp = f[x];
     f[x] = &Me[++use];
     f[x]->y = y;
     f[x]->next = Tmp;
     f[x]->Dis = Dis;
}
void Init()
{
     scanf("%d %d",&N,&M);
     for(int i = 1;i <= M;i++)
     {
             int x,y,D;
             scanf("%d %d %d",&x,&y,&D);
             if (x == y) continue;
             L(x,y,D);
             L(y,x,D);
     }
}
void SPFA()
{
     for(int i = 1;i <= N;i++)
     Dis[i] = 100000000;
     Dis[1] = 0;
     int t = (oo - 1) * N,w = oo * N;
     q[w & oo] = 1;
     while(t < w)
     {
             t++;
             int x = q[t & oo];
             v[x] = 0;
             for(fetch *Tmp = f[x];Tmp != NULL;Tmp = Tmp->next)
             {
                       int y = Tmp->y;
                       if (Dis[x] + Tmp->Dis < Dis[y])
                       {
                                  Dis[y] = Dis[x] + Tmp->Dis;
                                  if (!v[y])
                                  {
                                            v[y] = 1;
                                            if (Dis[y] < Dis[ q[t & oo] ])
                                            q[(--t) & oo] = y;
                                            else 
                                            q[(++w) & oo] = y;
                                  }
                       }
             }
     }
}
void Work()
{
     for(int i = 1;i <= N;i++)
     {
             for(fetch *Tmp = f[i];Tmp != NULL;Tmp = Tmp->next)
             {
                       int y = Tmp->y;
                       if (Dis[i] + Tmp->Dis == Dis[y])
                       {
                                  if (Link[i][y]) continue;
                                  Link[i][y] = 1;
                                  Du[y]++;
                       }
             }
     }
     unsigned long long Ans = 1;
     for(int i = 2;i <= N;i++)
     {
             Ans = Ans * Du[i];
             Ans %= ((1 << 31) - 1);
     }
     printf("%I64u\n",Ans);
}
int main()
{
    freopen("Castle.in","r",stdin);
    freopen("Castle.out","w",stdout);
    Init();
    SPFA();
    Work();
    return 0;
}
