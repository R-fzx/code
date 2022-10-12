#include<stdio.h>
#include<stdlib.h>
int sx,sy,tx,ty;
double sum;
int deng(double a,double b)
{
    if(a-b<0.000000001&&a-b>-0.000000001)
     return 1;
    return 0;
}
double min(double a,double b)
{
       if(a<b)
        return a;
       return b;
}
double max(double a,double b)
{
       if(a>b)
        return a;
       return b;
}
double jiao1(double x,double y1,double y2)
{
       if(sx<=x+0.0001&&x<=tx+0.0001&&sy<=y2+0.0001&&y1<=ty+0.0001)
        return min(ty,y2)-max(sy,y1);
       return 0;
}
double jiao2(double y,double x1,double x2)
{
       if(sy<=y+0.0001&&y<=ty+0.0001&&sx<=x2+0.0001&&x1<=tx+0.0001)
        return min(tx,x2)-max(sx,x1);
       return 0;
}
double tree(int f,double k,double x,double y)
{
     int i,xx=x,yy=y;
     double j=0;
     if(k<0.9)
     {
      if(x<sx||x>tx||y<sy||y>ty)
       return 0;
      else
      if(deng(x,tx)||deng(x,sx)||deng(y,ty)||deng(y,sy))
       return k*495+k;
      else
       return 2*k*495+k;
     }
     
     if(f!=1)
      j+=tree(0,k/3,x,y+2*k/3);
     if(f!=0)
      j+=tree(1,k/3,x,y-2*k/3);
     if(f!=3)
      j+=tree(2,k/3,x+2*k/3,y);
     if(f!=2)
      j+=tree(3,k/3,x-2*k/3,y);
      if(f==0)
      {
       j+=jiao2(y,x-k*2/3,x);
       j+=jiao2(y,x,x+k*2/3);
       j+=jiao1(x,y,y+k*2/3);
      }
      if(f==1)
      {
       j+=jiao2(y,x-k*2/3,x);
       j+=jiao2(y,x,x+k*2/3);
       j+=jiao1(x,y-k*2/3,y);
      }
      if(f==2)
      {
       j+=jiao2(y,x,x+k*2/3);
       j+=jiao1(x,y-k*2/3,y);
       j+=jiao1(x,y,y+k*2/3);
      }
      if(f==3)
      {
       j+=jiao2(y,x-k*2/3,x);
       j+=jiao1(x,y-k*2/3,y);
       j+=jiao1(x,y,y+k*2/3);
      }
     return j;
}
int main()
{
    int i,j,temp;
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    if(sx>tx) temp=sx,sx=tx,tx=temp;
    if(sy>ty) temp=sy,sy=ty,ty=temp;
    sum=81;
    sum=tree(0,27,0,54);
    if(sx<=0&&0<=tx&&sy<=54&&ty>=0)
     sum+=min(ty,54)-max(sy,0);
    printf("%.1lf\n",sum);
    return 0;
}
