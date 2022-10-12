#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 500010;
const long long oo = 1000000000000000ll;
int A,B,C;
struct node
{
       long long val[4];
       long long sum;
       long long p;
}d[MAXN],s[MAXN];
int Top,w;
struct V
{
       long long A1,A2;
       V(){A1 = A2 = -oo;}
       friend bool operator <(V a,V b)
       {
              if (a.A1 < b.A1 || a.A1 == b.A2 && a.A2 < b.A2) return 1;
              return 0;
       }
}f[103][103][103];
int N;
void Work()
{
     f[0][0][0].A1 = f[0][0][0].A2 = 0;
     for(int S = 1;S <= Top;S++)
     {
             for(int i = A;i >= 0;i--)
              for(int j = B;j >= 0;j--)
               for(int k = C;k >= 0;k--)
               if (f[i][j][k].A1 > -oo)
               {
                       V p;
                       p = f[i][j][k];
                       V e;
                       e = p;
                       e.A1 += d[S].val[1];
                       e.A2 += d[S].sum;
                       if (f[i + 1][j][k] < e)
                       f[i + 1][j][k] = e;
                       
                       e = p;
                       e.A1 += d[S].val[2];
                       e.A2 += d[S].sum;
                       if (f[i][j + 1][k] < e)
                       f[i][j + 1][k] = e;
                       
                       e = p;
                       e.A1 += d[S].val[3];
                       e.A2 += d[S].sum;
                       if (f[i][j][k + 1] < e)
                       f[i][j][k + 1] = e;
               }
     }
}
inline bool cmp1(node a,node b)
{
    return a.val[1] > b.val[1] || a.val[1] == b.val[1] && a.sum > b.sum;
}
inline bool cmp2(node a,node b)
{
    return a.val[2] > b.val[2] || a.val[2] == b.val[2] && a.sum > b.sum;
}
inline bool cmp3(node a,node b)
{
    return a.val[3] > b.val[3] || a.val[3] == b.val[3] && a.sum > b.sum;
}
inline bool cmp(node a,node b)
{
       return a.p < b.p;
}
void sort1(int l,int r)
{
     if (l > w) return;
//     if (r < w) return;
     int i = l,j = r;
     node mid,k;
     mid = s[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && cmp1(s[i] , mid)) i++;
           while (i<=j && cmp1(mid , s[j])) j--;
           if (i<=j)
           {
              k=s[i],s[i]=s[j],s[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort1(l,j);
     if (i<r) sort1(i,r);
     return;
}
void sort2(int l,int r)
{
     if (l > w) return;
//     if (r < w) return;
     int i = l,j = r;
     node mid,k;
     mid = s[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && cmp2(s[i] , mid)) i++;
           while (i<=j && cmp2(mid , s[j])) j--;
           if (i<=j)
           {
              k=s[i],s[i]=s[j],s[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort2(l,j);
     if (i<r) sort2(i,r);
     return;
}
void sort3(int l,int r)
{
     if (l > w) return;
//     if (r < w) return;
     int i = l,j = r;
     node mid,k;
     mid = s[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && cmp3(s[i] , mid)) i++;
           while (i<=j && cmp3(mid , s[j])) j--;
           if (i<=j)
           {
              k=s[i],s[i]=s[j],s[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort3(l,j);
     if (i<r) sort3(i,r);
     return;
}
long long Get(char S[],int &Pos)
{
     while(S[Pos] == ' ') Pos++;
     long long t = 0,flag = 1;
     if (S[Pos] == '-') flag = -1,Pos++;
     while(S[Pos] >= '0' && S[Pos] <= '9')
     {
                  t = t * 10 + S[Pos] - '0';
                  Pos++;
     }
     return t * flag;
}
void Init()
{
     scanf("%d %d %d %d%*c",&N,&A,&B,&C);
     char S[1000];
     for(int i = 1;i <= N;i++)
     {
             gets(S + 1);
             int Pos = 1;
             s[i].val[1] = Get(S,Pos);
             s[i].val[2] = Get(S,Pos);
             s[i].val[3] = Get(S,Pos);
      //       scanf("%I64d %I64d %I64d",&s[i].val[1],&s[i].val[2],&s[i].val[3]);
             s[i].sum = s[i].val[1] + s[i].val[2] + s[i].val[3];
             s[i].p = i;
     }
     w = A + B + C;
     if (A + B + C > N)
     {
           printf("I am a godlike cowcowcow\n");
           exit(0);
     }
     sort1(1,N);
     for(int i = 1;i <= w && i <= N;i++)
     d[++Top] = s[i];
     for(int i = w + 1;i <= N;i++)
     s[i - w] = s[i];
     if (N > w) N -= w;
     else 
     return;
     
     sort2(1,N);
     for(int i = 1;i <= w && i <= N;i++)
     d[++Top] = s[i];
     for(int i = w + 1;i <= N;i++)
     s[i - w] = s[i];
     if (N > w) N -= w;
     else 
     return;
     
     sort3(1,N);
     for(int i = 1;i <= w && i <= N;i++)
     d[++Top] = s[i];
}
int main()
{
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);
    Init();
    Work();
    printf("%I64d\n%I64d\n",f[A][B][C].A1,f[A][B][C].A2);
    return 0;
}
