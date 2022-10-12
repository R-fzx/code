#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define oo 1000000047
//M_PI
using namespace std;

struct ss{
       long long a,b,c,pd;
}y[500047];
/*
class people
{
      public:
          long long a,b,c;
          char tag;

          inline void read()
          {
               a=b=c=tag=0;
          
               gets(str);
          
               Now=0;
          
               n2=1;
          
               if (str[Now]=='-') Now++,n2=-1;
          
               while (str[Now]!=' ') 
               a=a*10+str[Now]-48,Now++;
          
               a*=n2;
          
               Now++;
          
               n2=1;
          
               if (str[Now]=='-') Now++,n2=-1;
          
               while (str[Now]!=' ') 
               b=b*10+str[Now]-48,Now++;
          
               b*=n2;
          
               Now++;
          
               n2=1;
          
               if (str[Now]=='-') Now++,n2=-1;
          
               while (str[Now]!=' ' && str[Now]!=0) 
               c=c*10+str[Now]-48,Now++;
          
               c*=n2;
          
               return;
          }
}
*/
long long n,m,A,B,C,f[47][47][47],f2[47][47][47],leny,hash[500047];
/*
inline bool cmpa(ss i,ss j)
{
       return i.a>j.a;
}

inline bool cmpb(ss i,ss j)
{
       return i.b>j.b;
}

inline bool cmpc(ss i,ss j)
{
       return i.c>j.c;
}
*/
inline void sort1(int l,int r)
{
     if (l>m || r<=m) return;
     long long i=l,j=r,mid;
     ss k;
     mid=y[(l+r)>>1].a;
     while (i<=j)
     {
           while (i<=j && y[i].a>mid) i++;
           while (i<=j && y[j].a<mid) j--;
           if (i<=j)
           {
              k=y[i],y[i]=y[j],y[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort1(l,j);
     if (i<r) sort1(i,r);
     return;
}

inline void sort2(int l,int r)
{
     if (l>m || r<=m) return;
     long long i=l,j=r,mid;
     ss k;
     mid=y[(l+r)>>1].b;
     while (i<=j)
     {
           while (i<=j && y[i].b>mid) i++;
           while (i<=j && y[j].b<mid) j--;
           if (i<=j)
           {
              k=y[i],y[i]=y[j],y[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort2(l,j);
     if (i<r) sort2(i,r);
     return;
}

inline void sort3(int l,int r)
{
     if (l>m || r<=m) return;
     long long i=l,j=r,mid;
     ss k;
     mid=y[(l+r)>>1].c;
     while (i<=j)
     {
           while (i<=j && y[i].c>mid) i++;
           while (i<=j && y[j].c<mid) j--;
           if (i<=j)
           {
              k=y[i],y[i]=y[j],y[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort3(l,j);
     if (i<r) sort3(i,r);
     return;
}

int main()
{
    freopen("ゆりっぺ.in","r",stdin);
    freopen("ゆりっぺ.out","w",stdout);

    cin>>n>>A>>B>>C;

    m=A+B+C;

	if(m>n)
	{
		printf("I am a godlike cowcowcow\n");
	
		return 0;
	}

    for(long long i=1;i<=n;i++)
       scanf("%I64d%I64d%I64d",&y[i].a,&y[i].b,&y[i].c);

    sort1(1,n);

    for(long long i=1;i<=m;i++)
       y[i].pd=1;

    sort2(1,n);

    for(long long i=1;i<=m;i++)
       y[i].pd=1;

    sort3(1,n);

    for(long long i=1;i<=m;i++)
       y[i].pd=1;

    for(int j=0;j<=A;j++)
       for(int k=0;k<=B;k++)
          for(int l=0;l<=C;l++)
             f[j][k][l]=f2[j][k][l]=-oo;
    
    f[0][0][0]=f2[0][0][0]=0;
/*
    for(long long i=1;i<=n;i++)
    {
       if(y[i].pd==0)
         continue;
    
       for(long long a=A;a>=0;a--)
          for(long long b=B;b>=0;b--)
             for(long long c=C;c>=0;c--)
             {
                if(a<A && f[a+1][b][c]<f[a][b][c]+y[i].a)
                {
                  f[a+1][b][c]=f[a][b][c]+y[i].a;
                
                  f2[a+1][b][c]=f2[a][b][c]+y[i].a+y[i].b+y[i].c;
                }
             
                else if(a<A && f[a+1][b][c]==f[a][b][c]+y[i].a)
                  f2[a+1][b][c]=max(f2[a+1][b][c],f2[a][b][c]+y[i].a+y[i].b+y[i].c);
             
                if(b<B && f[a][b+1][c]<f[a][b][c]+y[i].b)
                {
                  f[a][b+1][c]=f[a][b][c]+y[i].b;
                
                  f2[a][b+1][c]=f2[a][b][c]+y[i].a+y[i].b+y[i].c;
                }
             
                else if(b<B && f[a][b+1][c]==f[a][b][c]+y[i].b)
                  f2[a][b][c+1]=max(f2[a][b+1][c],f2[a][b][c]+y[i].a+y[i].b+y[i].c);
             
                if(c<C && f[a][b][c+1]<f[a][b][c]+y[i].c)
                {
                  f[a][b][c+1]=f[a][b][c]+y[i].c;
                
                  f2[a][b][c+1]=f2[a][b][c]+y[i].a+y[i].b+y[i].c;
                }
             
                else if(c<C && f[a][b][c+1]==f[a][b][c]+y[i].c)
                  f2[a][b][c+1]=max(f2[a][b][c+1],f2[a][b][c]+y[i].a+y[i].b+y[i].c);
             }
    }
*/
    for(int i=1;i<=n;i++)
    {
       if(y[i].pd==0)
         continue;
    
       long long ai=y[i].a,bi=y[i].b,ci=y[i].c;
    
       for(int j=A;j>=0;j--)
          for(int k=B;k>=0;k--)
             for(int l=C;l>=0;l--)
             {
                long long key=f[j][k][l],k2,K2;
                long long Key=f2[j][k][l];
             
                if (j>0)
                {
                   k2=f[j-1][k][l]+ai;
                   K2=f2[j-1][k][l]+ai+bi+ci;
                   if (k2>key || (k2==key && K2>Key)) key=k2,Key=K2;
                }
             
                if (k>0)
                {
                   k2=f[j][k-1][l]+bi;
                   K2=f2[j][k-1][l]+ai+bi+ci;
                   if (k2>key || (k2==key && K2>Key)) key=k2,Key=K2;
                }
             
                if (l>0)
                {
                   k2=f[j][k][l-1]+ci;
                   K2=f2[j][k][l-1]+ai+bi+ci;
                   if (k2>key || (k2==key && K2>Key)) key=k2,Key=K2;
                }
             
                f[j][k][l]=key;
                f2[j][k][l]=Key;
             }
    }

    cout<<f[A][B][C]<<endl<<f2[A][B][C]<<endl;

    return 0;
}
