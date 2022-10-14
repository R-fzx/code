#include<stdio.h>
#define in "wave.in"
#define out "wave.out"
FILE *fs,*fp;
int M,N,C,num[50]={0},pd[50]={0},count=0,jl=0;
void find(int);
int main()
{
    if((fs=fopen(in,"r"))==NULL) return 0;
    if((fp=fopen(out,"w"))==NULL) return 0;
     fscanf(fs,"%d",&M);
     int i;
     for(i=1;i<=M;i++)
     {
        fscanf(fs,"%d%d",&N,&C);
        count=0;jl=0;
        find(1);
     }
    fclose(fs);
    fclose(fp);
    return 0;
}
void find(int w)
{
     int i;
     if(w>N)
     {
       count++;
       if(count==C&&jl==0)
       {
          jl=1;
          for(i=1;i<=N;i++)
          if(i!=N)
           fprintf(fp,"%d ",num[i]);
          else
           fprintf(fp,"%d\n",num[i]);
       }
       return ;
     }
     else
     if(count<C)
     {
         if(w==1||w==2)
         {
           for(i=1;i<=N;i++)
           if(jl==1)
            break;
           else
           if(pd[i]==0)
           {
             pd[i]=1;
             num[0]++;
             num[num[0]]=i;
             find(w+1);
             num[num[0]]=0;
             num[0]--;
             pd[i]=0;
           }
         }
         else
         {
            if(num[w-2]<num[w-1])
            {
               for(i=1;i<num[w-1];i++)
               if(jl==1)
                break;
               else
               if(pd[i]==0)
               {
                  pd[i]=1;
                  num[0]++;
                  num[num[0]]=i;
                  find(w+1);
                  num[num[0]]=0;
                  num[0]--;
                  pd[i]=0;
               }
            }
            else
            {
               for(i=num[w-1]+1;i<=N;i++)
               if(jl==1)
                break;
               else
               if(pd[i]==0)
               {
                  pd[i]=1;
                  num[0]++;
                  num[num[0]]=i;
                  find(w+1);
                  num[num[0]]=0;
                  num[0]--;
                  pd[i]=0;
               }
            }
         }
     }
}
