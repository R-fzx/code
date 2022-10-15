#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
struct fetch
{
       int y;
       long long Q;
       fetch *next,*pre,*fan;
       fetch(){
               next = pre = fan = NULL;
               }
}*f[300],*D;
long long MaxQ = 0,s,Totfe = 0;
struct Flist
{
       int x,y;
       long long p,q;
}List[60000];
int use = 0;
int N,M;
long long Ans = -1,P,Q,NowP,NowQ;
int cmp(Flist a,Flist b)
{
    return a.p < b.p;
}
void Init()
{
     scanf("%d %d",&N,&M);
     scanf("%I64d %I64d",&P,&Q);
     for(int i = 1;i <= M;i++)
     {
             int x,y;
             long long pp,qq;
             scanf("%d %d %I64d %I64d",&List[i].x,&List[i].y,&List[i].p,&List[i].q);
     }
     sort(List + 1,List + M + 1,cmp);
}
int Dfs(int x,int Gole,int fa)
{
     if (x == Gole) return 1;
     for(fetch *Tmp = f[x];Tmp != NULL;Tmp = Tmp->next)
     {
               int y = Tmp->y;
               if (y == fa) continue;
               if (Dfs(y,Gole,x))
               {
                              if (Tmp->Q > MaxQ)
                              {
                                         MaxQ = Tmp->Q;
                                         D = Tmp;
                                         s = x;
                              }   
                   return 1;
               }
     }
     return 0;
}
void Insert(Flist d)
{
     fetch *Tmp = f[d.x];
     f[d.x] = new(fetch);
     f[d.x]->y = d.y;
     f[d.x]->next = Tmp;
     f[d.x]->Q = d.q;
     if (Tmp != NULL) Tmp->pre = f[d.x];
     
           Tmp = f[d.y];
     f[d.y] = new(fetch);
     f[d.y]->y = d.x;
     f[d.y]->next = Tmp;
     f[d.y]->Q = d.q;
     if (Tmp != NULL) Tmp->pre = f[d.y];
     
     f[d.x]->fan = f[d.y];
     f[d.y]->fan = f[d.x];
}
void Delet(fetch *g,int Now)
{
     fetch *Tmp;
     if (g->next != NULL)
     {
                 Tmp = g->next;
                 Tmp->pre = g->pre;
     }
     if (g->pre != NULL)
     {
                Tmp = g->pre;
                Tmp->next = g->next;
     }
     if (f[Now] == g) f[Now] = g->next;
     free(g);
}
void Add(Flist d)
{
     MaxQ = -1;
     if (!Dfs(d.x,d.y,-1))
     {
                          Insert(d);
                          Totfe ++;
     }
     else 
     if (MaxQ > d.q)
     {
              Delet(D->fan,D->y);
              Delet(D,s);
              Insert(d);
     }
}
void Cal()
{
     long long Tmp = NowP * P + NowQ * Q;
     if (Tmp < Ans || Ans == -1) Ans = Tmp;
}
void Work()
{
     for(int i = 1;i <= M;i++)
     {
             NowP = List[i].p;
             Add(List[i]);
             NowQ = -1;
             for(int j = 1;j <= N;j++)
              for(fetch *Tmp = f[j];Tmp != NULL;Tmp = Tmp->next)
              {
                        int y = Tmp->y;
                        NowQ = max(NowQ,Tmp->Q); 
              }             
             if (Totfe == N - 1) Cal();
     }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    Init();
    Work();
    printf("%I64d\n",Ans);
    return 0;
}
