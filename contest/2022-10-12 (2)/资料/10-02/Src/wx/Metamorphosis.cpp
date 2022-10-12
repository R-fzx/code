#include<stdio.h>
#include<stdlib.h>
double ans=0;
int sx,sx2,sy,sy2;
int max(int,int);
int wx_abs(int);
void sou(int,int,int,int,int);
int init(int,int,int,int);
int main()
{
    int i,j,k;
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    scanf("%d%d%d%d",&sx,&sy,&sx2,&sy2);
    sou(0,0,0,81,1);
    printf("%.1lf",ans);
    return 0;
}
int wx_abs(int x)
{
    if(x<0)return -x;
    return x;
}
int max(int x,int y)
{
    if(x>y)return x;
    return y;
}
void swap(int &a,int &b)
{
     a=a^b;
     b=a^b;
     a=a^b;
}
void sou(int x0,int y0,int x1,int y1,int step)
{
     int s=wx_abs(x0-x1)+wx_abs(y0-y1);
     if(step<=4)
             {
               if(x0==x1)//обио 
              {
               {
                int i,j;
                if(y0<y1)
                         {
                         for(i=y0;i<y0+(y1-y0)*2/3;i++)
                         if(init(x0,i,x0,i+1)>0)
                         ans+=1.0;
                         }
                else
                    {
                         for(i=y0-(y0-y1)*2/3;i<y0;i++)
                         if(init(x0,i,x0,i+1)>0)
                         ans+=1.0;
                    }
               }
               sou(x0,y0+(y1-y0)*2/3,x0,y1,step+1);//ио
               sou(x0,y0+(y1-y0)*2/3,x0-(y1-y0)/3,y0+(y1-y0)*2/3,step+1);
               sou(x0,y0+(y1-y0)*2/3,x0+(y1-y0)/3,y0+(y1-y0)*2/3,step+1); 
              }
              else if(y0==y1)
              {
               {
                int i,j;
                if(x0<x1)
                         {
                         for(i=x0;i<x0+(x1-x0)*2/3;i++)
                         if(init(i,y0,i+1,y0)>0)
                         ans+=1.0;
                         }
                else {
                         for(i=x0-(x0-x1)*2/3;i<x0;i++)
                         if(init(i,y0,i+1,y0)>0)
                         ans+=1.0;
                     }
               }
               sou(x0+(x1-x0)*2/3,y0,x1,y0,step+1);
               sou(x0+(x1-x0)*2/3,y0,x0+(x1-x0)*2/3,y0-(x1-x0)/3,step+1);
               sou(x0+(x1-x0)*2/3,y0,x0+(x1-x0)*2/3,y0+(x1-x0)/3,step+1);
              }
             }
     else {
           int ok=init(x0,y0,x1,y1);
           if(ok==2)
           ans+=1.0+495.0*2.0/3.0;
           else if(ok==1)
           ans+=1.0+495.0/3.0;
          }
}
int init(int x0,int y0,int x1,int y1)
{
    if(x0==x1){
               if(y1<y0)swap(y0,y1);
                           if(y1<=sy2&&y0>=sy)
                           {
                            if(x0==sx||x0==sx2)return 1;
                            else if(x0>=sx&&x0<=sx2)
                                    return 2;
                                 else return 0;
                           }
                           else return 0;
               }
    else {
               if(x1<x0)swap(x0,x1);
                           if(x1<=sx2&&x0>=sx)
                           {
                            if(y0==sy||y0==sy2)return 1;
                            else if(y0>=sy&&y0<=sy2)
                                    return 2;
                                 else return 0;
                           }
                           else return 0;
         }
}
