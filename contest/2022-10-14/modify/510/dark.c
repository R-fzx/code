#include <stdio.h>
#include <math.h>
#define in "dark.in"
#define out "dark.out"
#define MaxN 250000
#define oo 100000000
FILE *fp,*fq;
struct point
{
       long x,y;
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

long long getans(long low,long high,long long min)
{
       long i,j;
       long long temp;
       
       for(i=low;i<=high;i++) 
        for(j=i-1;j>=low;j--)
         {
         temp=(long long)(tmp[j].y-tmp[i].y)*(long long)(tmp[j].y-tmp[i].y);
         if(temp<=min)
          {
          temp+=(long long)(tmp[j].x-tmp[i].x)*(long long)(tmp[j].x-tmp[i].x);
          min=temp<min?temp:min;
          }
         else break;
         }
       return min;
}

void merge(long low,long high)
{
     long mid=(low+high)/2;
     long i,j,k;
     
     for(i=j=low,k=mid+1;j<=mid && k<=high;i++)
      if(d[j].y<=d[k].y) tmp[i]=d[j++];
      else tmp[i]=d[k++];
     if(j<=mid) for(;j<=mid;j++) tmp[i++]=d[j];
      else for(;k<=high;k++) tmp[i++]=d[k];
     for(i=low;i<=high;i++) d[i]=tmp[i];
}

long long deal(long low,long high)
{
       long mid,i,j=0;
       long long ans1,ans2,ans;
       
       if(low==high)
        return oo*oo;
       else
        {
        mid=(low+high)/2;
        ans1=deal(low,mid);
        ans2=deal(mid+1,high);
        ans=ans1>ans2?ans2:ans1;
        ans1=d[mid].x;
        merge(low,high);
        j=0;ans2=sqrt(ans);
        ans1+=ans2;ans2=ans1-2*ans2;
        for(i=low;i<=high;i++)
         if(ans1>=d[i].x && ans2<=d[i].x)
          tmp[j++]=d[i];
        ans=getans(0,j-1,ans);
        return ans;
        }
}

void work(long n)
{
     qs(0,n-1);
     fprintf(fq,"%.2lf\n",sqrt(deal(0,n-1))/2);
}

int main()
{
    long n,i;
    
    if(opens()==0)
     return 0;
    fscanf(fp,"%ld",&n);
    for(i=0;i<n;i++) fscanf(fp,"%ld%ld",&d[i].x,&d[i].y);
    work(n);
    close();
    return 0;
}
