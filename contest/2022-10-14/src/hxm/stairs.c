#include <stdio.h>
int now[1000]={0},flag[1000]={0};
void sort(int l,int r)
{
     if(l<r)
     {
         int i,j,t,x,ft;
         t=(r-l)*0.29+l;
         x=now[t];
         ft=flag[t];
         now[t]=now[l];
         flag[t]=now[l];
         i=l,j=r;
         while(i<j)
         {
            while(i<j && now[j]>x)  j--;
            if(i<j) { now[i]=now[j]; flag[i]=flag[j]; i++;}
            while(i<j && now[i]<x) i++;
            if(i<j) { now[j]=now[i]; flag[j]=flag[i]; j--;}
         }
         now[i]=x;
         flag[i]=ft;
         sort(l,i-1);
         sort(i+1,r);
     }
}
int main()
{
    FILE *fr,*fw;
    int tot,n,f,b;
    int k,i,j,sum,time,t;
    
    fr=fopen("stairs.in","r");
    fw=fopen("stairs.out","w");
    fscanf(fr,"%d",&tot);
    for(k=0;k<tot;k++)
    {
       fscanf(fr,"%d%d%d",&n,&f,&b);
       time=sum=0;
       for(i=0;i<n;i++)
       {
          fscanf(fr,"%d%d",now+i,flag+i);
          if(flag[i]==0)
            sum++;
       }
       sort(0,n-1);
       if(b>0)
       {
           while(b>n)
           {
              b-=n;
              time+=2*f;
           }
           if(b>sum)
           {
             b-=sum;
             time+=f;
             sum=n-sum;
             if(b>0)
             {
               t=0;
               for(i=n-1;i>=0;i--)
               {
                 if(flag[i]==1)
                   t++;
                 if(t==b)
                   break;
               }
               time+=2*f-now[i];
             }
           }
           else if(b>0)
           {
               t=0;
               for(i=0;i<n;i++)
               {
                  if(flag[i]==0)
                     t++;
                  if(t==b)
                     break;
               }
               time+=f+now[i];
           }
       }
       else
       {
           for(i=n-1;i>=0;i--)
              if(flag[i]==1)
                 t=i;
           time+=f-now[t];
       }
       fprintf(fw,"%d\n",time);
    }
    fclose(fr);
    fclose(fw);
    return 0;
}
