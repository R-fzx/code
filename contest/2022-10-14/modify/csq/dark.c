#include <stdio.h>
#include <math.h>
#define N 200000
#define M 1000000

int a[N+1][2]={0};
int n;
int now[M+1]={0},g[N]={0},next[N]={0},tot=1;
double ans=1e12;

void quick(int low,int high)
{
     int i=low,j=high,k=(high-low)*0.618+low;
     int t1=a[k][0],t2=a[k][1];
     
     if (i<j)
     {
        a[k][0]=a[low][0];
        a[k][1]=a[low][1];
        
        while (i<j)
        {
              while (i<j && (a[j][0]>t1 || (a[j][0]==t1 && a[j][1]>t2) ))  j--;
              if (i<j) { a[i][0]=a[j][0]; a[i][1]=a[j][1]; i++; }
              while (i<j && (a[i][0]<t1 || (a[i][0]==t1 && a[i][1]<t2)) )  i++;
              if (i<j) { a[j][0]=a[i][0]; a[j][1]=a[i][1]; j--; }
        }
        a[i][0]=t1;
        a[i][1]=t2;
        quick(low,i-1);
        quick(i+1,high);
     }
}

main()
{
      FILE *in,*out;
      int i,j,k,l,max=0;
      double r=1e9;
      
      in=fopen("dark.in","r");
      out=fopen("dark.out","w");
        
        fscanf(in,"%d",&n);
        for (i=1;i<=n;i++)
        {
            int x,y;
            fscanf(in,"%d%d",&x,&y);
            a[i][0]=x;
            a[i][1]=y;
            if (x>=max)
               max=x;
            next[tot]=now[x];
            now[x]=tot;
            g[tot]=y;
            tot++;
        }
        quick(1,n);
        for (i=1;i<n;i++)
        {
            double tt;
            j=i+1;
            tt= sqrt( (double)(a[i][0]-a[j][0])*(double)(a[i][0]-a[j][0])+(double)(a[i][1]-a[j][1])*(double)(a[i][1]-a[j][1]) );
            if (tt < r)
            {
               r=tt;
               ans = r;
            }
        }
        
        for (i=1;i<n;i++)
        {
            j=i+1;
            double rr;
            
            if (r==0)
               break;
            for (k=a[i][0]-r;k<=a[i][0]+r;k++)
            if (k>=0 && k<=max)
            {
                for (l=now[k];l;l=next[l])
                {
                    rr=sqrt( (double)(k-a[i][0])*(double)(k-a[i][0]) + (double)(g[l]-a[i][1])*(double)(g[l]-a[i][1]) );
                    if (rr!=0)
                    {
                       r = r<rr?r:rr;
                       if (r  < ans)
                          ans = r;
                    }
                }
            }
        }
        fprintf(out,"%.2lf",ans/2);
        
      fclose(in);
      fclose(out);
}
