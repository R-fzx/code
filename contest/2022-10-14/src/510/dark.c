#include <stdio.h>
#include <math.h>
#define in "dark.in"
#define out "dark.out"
#define MaxN 250000
#define oo 100000000
FILE *fp,*fq;
struct point
{
       double x,y;
}d[MaxN]={0},tmp[MaxN]={0};

int opens()
{
    if((fp=fopen(in,"r"))==NULL)
     return 0;
    if((fq=fopen(out,"w"))==NULL)
     return 0;
    return 1;
}

void close()
{
     fclose(fp);
     fclose(fq);
}

double wym(double x)
{ return x>0?x:-x;}

void solve(long n)
{
     long i,j;
     double min=oo;
     
     min*=oo;
     for(i=0;i<n;i++)
      for(j=0;j<i;j++)
       if(min>(d[i].x-d[j].x)*(d[i].x-d[j].x)+(d[i].y-d[j].y)*(d[i].y-d[j].y))
        min=(d[i].x-d[j].x)*(d[i].x-d[j].x)+(d[i].y-d[j].y)*(d[i].y-d[j].y);
     fprintf(fq,"%.2lf\n",sqrt(min)/2);
}

void qs(long low,long high)
{
     long i,j;
     struct point t;
     
     if(low<high)
      {
      i=low;j=high;
      t=d[i+(j-i)/3];d[i+(j-i)/3]=d[i];
      while(i<j)
       {
       while(i<j && (d[j].x>t.x || (d[j].x==t.x && d[j].y>t.y))) j--;
       if(i<j) d[i++]=d[j];
       while(i<j && (d[i].x<t.x || (d[i].x==t.x && d[i].y<t.y))) i++;
       if(i<j) d[j--]=d[i];       
       }
      d[i]=t;
      qs(low,i-1);qs(i+1,high);
      }
}

double getans(long low,long high,struct point tt[])
{
       long i,j;
       double min=oo;
       
       min*=min;
       for(i=low;i<=high;i++)
        for(j=low;j<i;j++)
          if(min>(tt[i].x-tt[j].x)*(tt[i].x-tt[j].x)+(tt[i].y-tt[j].y)*(tt[i].y-tt[j].y))
            min=(tt[i].x-tt[j].x)*(tt[i].x-tt[j].x)+(tt[i].y-tt[j].y)*(tt[i].y-tt[j].y);
       return sqrt(min);
}

void qs2(long low,long high)
{
     long i,j;
     struct point t;
     
     if(low<high)
      {
      i=low;j=high;
      t=tmp[i+(j-i)/3];tmp[i+(j-i)/3]=tmp[i];
      while(i<j)
       {
       while(i<j && tmp[j].y>t.y) j--;
       if(i<j) tmp[i++]=tmp[j];
       while(i<j && tmp[i].y<t.y) i++;
       if(i<j) tmp[j--]=tmp[i];       
       }
      tmp[i]=t;
      qs2(low,i-1);qs2(i+1,high);
      }
}

double deal(long low,long high)
{
       long mid,i,j=0,k=0;
       double ans1,ans2,ans;
       
       if(low+10>=high)
        return getans(low,high,d);
       else
        {
        mid=(low+high)/2;
        ans1=deal(low,mid);
        ans2=deal(mid+1,high);
        ans=ans1>ans2?ans2:ans1;
        for(i=low;i<=high;i++)
         if(wym(d[i].x-d[mid].x)<=ans)
          tmp[j++]=d[i];
        qs2(0,j-1);
        for(i=0;i<j;i++)
         {
         while(tmp[i].y+ans<=tmp[k].y && k<j) k++;
         ans1=getans(i,k-1,tmp);
         ans=ans1<ans?ans1:ans;
         }
        return ans;
        }
}

void work(long n)
{
     qs(0,n-1);
     fprintf(fq,"%.2lf\n",deal(0,n-1)/2);
}

int main()
{
    long n,i;
    
    if(opens()==0)
     return 0;
    fscanf(fp,"%ld",&n);
    for(i=0;i<n;i++)
     fscanf(fp,"%lf%lf",&d[i].x,&d[i].y);
    if(n<3000) solve(n);
     else work(n);
    close();
    return 0;
}
