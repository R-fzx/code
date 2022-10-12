#include<stdio.h>
#include<iostream>
using namespace std;
double ans1,ans2,ans3,ans,x1,x2,y1,y2,t[4][4];
inline double get(double x)
{
    if(x>0) return x;
    return 0;
}
void find(int a,double x,double y,double z,int flag)  //flag 1ио3об0вС2ср
{
    int i,j;
    if(a<=0) return;
    if(flag==0)
    {
      if((x<=x1)||(x-z>=x2)||(y-z/3.0>=y2)||(y+z/3.0<=y1)) return;
      if((x-z>=x1)&&(x<=x2)&&(y-z/3.0>=y1)&&(y+z/3.0<=y2)) { ans+=z+z*(a-1)*2.0/3.0; return; }
    }
    if(flag==1)
    {
      if((y+z<=y1)||(y>=y2)||(x-z/3.0>=x2)||(x+z/3.0<=x1)) return;
      if((y>=y1)&&(y+z<=y2)&&(x-z/3.0>=x1)&&(x+z/3.0<=x2)) { ans+=z+z*(a-1)*2.0/3.0; return; }
    }
    if(flag==2)
    {
      if((x+z<=x1)||(x>=x2)||(y-z/3.0>=y2)||(y+z/3.0<=y1)) return;
      if((x>=x1)&&(x+z<=x2)&&(y-z/3.0>=y1)&&(y+z/3.0<=y2)) { ans+=z+z*(a-1)*2.0/3.0; return; }
    }
    if(flag==4)
    {
      if((y<=y1)||(y-z>=y2)||(x-z/3.0>=x2)||(x+z/3.0<=x1)) return;
      if((y-z>=y1)&&(y<=y2)&&(x-z/3.0>=x1)&&(x+z/3.0<=x2)) { ans+=z+z*(a-1)*2.0/3.0; return; }
    }
    z=z/3*2;
    if(flag==0) if((y2>=y)&&(y1<=y)) ans+=get(min(x,x2)-max(x-z,x1));
    if(flag==1) if((x2>=x)&&(x1<=x)) ans+=get(min(y+z,y2)-max(y,y1));
    if(flag==2) if((y2>=y)&&(y1<=y)) ans+=get(min(x+z,x2)-max(x,x1));
    if(flag==3) if((x2>=x)&&(x1<=x)) ans+=get(min(y,y2)-max(y-z,y1));
    for(i=0;i<4;i++) 
      if(i!=(flag+2)%4) find(a-1,x+z*t[flag][0],y+z*t[flag][1],z/2,i);
    return;
}
int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    int i,j;
    double k;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    t[0][0]=t[3][1]-1,t[1][1]=t[2][0]=1;
    find(500,0.0,0.0,81.0,1);
    printf("%.1lf\n",ans);
    return 0;
}
