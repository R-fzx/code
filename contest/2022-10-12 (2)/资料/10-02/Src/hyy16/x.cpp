#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.000000001
#define mo 1048575

double mi[505];

int bj(double a,double b);
double min(double a,double b);
double max(double a,double b);

class point
{
      public:
          double x,y;
};

class vec
{
      public:
          point st,en;
          int t;
      
      double len()
      {
             if (bj(st.x,en.x)==0) return fabs(st.y-en.y);
             else return fabs(st.x-en.x);
      }
      
      double slen()
      {
             return (500-t+1)*len()*5.0/3.0;
      }
};

class jx
{         
      public:
          point lu,rd;

          void read()
          {
               double temp;
               scanf("%lf %lf %lf %lf",&lu.x,&lu.y,&rd.x,&rd.y);
               if (lu.x>rd.x)
               temp=lu.x,lu.x=rd.x,rd.x=temp;
               if (lu.y<rd.y)
               temp=lu.y,lu.y=rd.y,rd.y=temp;
          }
          
          friend double operator * (jx a,vec b)
          {
              double l1,l2;
              if (bj(b.st.x,b.en.x)==0)
              {
                 if (bj(b.st.x,a.lu.x)<0 || bj(b.st.x,a.rd.x)>0)
                 return 0;
                 if (bj(max(b.st.y,b.en.y),min(a.lu.y,a.rd.y))<0) return 0;
                 if (bj(min(b.st.y,b.en.y),max(a.lu.y,a.rd.y))>0) return 0;
                 l1=min(b.st.y,b.en.y);
                 l2=max(b.st.y,b.en.y);
                 return min(a.lu.y,l2)-max(a.rd.y,l1);
              }
              else
              {
                  if (bj(b.st.y,a.lu.y)>0 || bj(b.st.y,a.rd.y)<0)
                  return 0;
                  if (bj(max(b.st.x,b.en.x),min(a.lu.x,a.rd.x))<0) return 0;
                  if (bj(min(b.st.x,b.en.x),max(a.lu.x,a.rd.x))>0) return 0;
                  l1=min(b.st.x,b.en.x);
                  l2=max(b.st.x,b.en.x);
                  return min(a.rd.x,l2)-max(a.lu.x,l1);
              }
          }    
};

void fl(vec a,vec &b,vec &c);

jx a;
int i,h,t;
vec x,y,z,zl[2000005];
double l,l1,l2,ans;

int main()
{
    freopen("Metamorphosis.in","r",stdin); freopen("Metamorphosis.out","w",stdout);
    mi[0]=1;
    for(i=1;i<=500;i++)
    mi[i]=mi[i-1]*(double)(5)/(double)(3);
    a.read();
    x.st.x=x.st.y=x.en.x=0;
    x.en.y=81;
    x.t=1;
    zl[1]=x;
    for(h=t=1;h<=t;h++)
    {
       if (h==8)
       h=8;
       x=zl[h&mo];
       l=a*x;
       if (bj(l,0)==0)
       {
          if (x.t>=14) continue;
          fl(x,y,z);
          t++,zl[t&mo]=y;
          t++,zl[t&mo]=z;
       }
       else if (bj(l,x.len())==0)
       {
          fl(x,y,z);
          l1=a*y;
          l2=a*z;
          if (bj(l1,y.len())==0 && bj(l2,z.len())==0)
          ans+=x.slen();
       }
       else
       {
           ans+=l;
           fl(x,y,z);
           t++,zl[t&mo]=y;
           t++,zl[t&mo]=z;
       }
    }
    printf("%.1lf\n",ans);
    return 0;
}

int bj(double a,double b)
{
    if (a-b>0-eps && a-b<eps) return 0;
    if (a>b) return 1;
    else return -1;
}

double min(double a,double b)
{
       if (bj(a,b)<0) return a;
       else return b;
}

double max(double a,double b)
{
       if (bj(a,b)>0) return a;
       else return b;
}

void fl(vec a,vec &b,vec &c)
{
     double midx,midy,len;
     midx=a.en.x-(a.en.x-a.st.x)/(3.0);
     midy=a.en.y-(a.en.y-a.st.y)/(3.0);
     len=a.len()/(3.0);
     b.t=c.t=a.t+1;
     c.st.x=b.st.x=midx;
     c.st.y=b.st.y=midy;
     if (bj(a.st.x,a.en.x)==0)
     {
        b.en.y=c.en.y=midy;
        b.en.x=midx-len;
        c.en.x=midx+len;
     }
     else
     {
         b.en.x=c.en.x=midx;
         b.en.y=midy-len;
         c.en.y=midy+len;
     }
     return;
}
