#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define oo 1000000000
struct stu
{
    long len;
    char str[MAX];       
}g[MAX][MAX][MAX][MAX],dist[MAX][MAX],min;
long hash[MAX][MAX]={0};
void cut(char s[MAX],char temp[MAX],long p,long q)
{
     long i,j;
     for(i=0,j=p;j<=q;i++,j++)
        temp[i]=s[j];     
}
long pos(char s1[MAX],char s2[MAX])
{
     long i;
     if(strlen(s1)<strlen(s2))
     {
         for(i=0;i<strlen(s1);i++)
           if(s1[i]!=s2[i])
              return(0);
         return(1);                         
     }   
     return(0);  
}
void del(char s[MAX],long i,long j)
{
     long t,p,o;
     char temp[MAX]={'\0'};
     for(t=i,o=0;t<=j;t++,o++)
       temp[o]=s[t];
     memset(s,'\0',sizeof(s));
     for(t=0;t<o;t++)
        s[t]=temp[t];     
}
main()
{
     long n,i,j,k,l,t;
     char s1[MAX]={'\0'},s2[MAX]={'\0'},s[MAX][MAX]={'\0'},temp[MAX]={'\0'};
     FILE *fp,*fo;
     fp=fopen("codes.in","r");
     fo=fopen("codes.out","w");
     fscanf(fp,"%ld\n",&n);
     for(i=1;i<=n;i++)
       fscanf(fp,"%s",s[i]);
     for(i=1;i<=n;i++)
       for(j=1;j<=strlen(s[i]);j++)
         for(k=1;k<=n;k++)
           for(l=1;l<=strlen(s[k])+1;l++)
           {
               g[i][j][k][l].len=oo;                    
               memset(g[i][j][k][l].str,'\0',sizeof(g[i][j][k][l].str));
           }
     for(i=1;i<=n;i++)
       for(j=1;j<=strlen(s[i]);j++)
       {
            memset(s1,'\0',sizeof(s1));
            cut(s[i],s1,j-1,strlen(s[i])-1);
            for(k=1;k<=n;k++)
            {
                 memset(s2,'\0',sizeof(s2));
                 strcpy(s2,s[k]);
                 if(strcmp(s1,s2)==0)
                 {
                     if(i!=k)
                     {
                         g[i][j][k][strlen(s2)+1].len=strlen(s2);
                         strcpy(g[i][j][k][strlen(s2)+1].str,s2);
                     }
                 }
                 else if(pos(s1,s2)==1)
                 {
                     g[i][j][k][strlen(s1)+1].len=strlen(s1);
                     strcpy(g[i][j][k][strlen(s1)+1].str,s1);
                 }
                 else if(pos(s2,s1)==1) 
                 {
                     g[i][j][i][j+strlen(s2)].len=strlen(s2);
                     strcpy(g[i][j][i][j+strlen(s2)].str,s2);         
                 }
            }
       }
     for(i=1;i<=n;i++)
        for(j=1;j<=strlen(s[i])+1;j++)
        {
            memset(dist[i][j].str,'\0',sizeof(dist[i][j].str));
            dist[i][j].len=oo;                             
        }
     for(i=1;i<=n;i++)
         dist[i][1].len=0;
     for(t=1;t<=n*n;t++)
     {
          min.len=oo;
          for(i=1;i<=n;i++)
            for(j=1;j<=strlen(s[i])+1;j++)                
              if(hash[i][j]==0)
                if(dist[i][j].len<min.len||(dist[i][j].len==min.len&&strcmp(dist[i][j].str,min.str)<0))
                {
                     k=i;
                     l=j;
                     min.len=dist[i][j].len;
                     memset(min.str,'\0',sizeof(min.str));
                     strcpy(min.str,dist[i][j].str);                                                                                       
                }  
          hash[k][l]=1;
          if(l==strlen(s[k])+1)
             break;
          for(i=1;i<=n;i++)
            for(j=1;j<=strlen(s[i])+1;j++)
              if(hash[i][j]==0)
                 if(dist[k][l].len+g[k][l][i][j].len<=dist[i][j].len)
                 {
                       memset(temp,'\0',sizeof(temp));
                       strcpy(temp,dist[k][l].str);
                       strcat(temp,g[k][l][i][j].str);
                       if(dist[k][l].len+g[k][l][i][j].len<dist[i][j].len)
                       {
                            memset(dist[i][j].str,'\0',sizeof(dist[i][j].str));
                            strcpy(dist[i][j].str,temp);                                                    
                       }                          
                       else if(strcmp(temp,dist[i][j].str)<0)
                       {
                            memset(dist[i][j].str,'\0',sizeof(dist[i][j].str));
                            strcpy(dist[i][j].str,temp);     
                       } 
                       dist[i][j].len=dist[k][l].len+g[k][l][i][j].len;                          
                 }
     }
     min.len=oo;
     for(i=1;i<=n;i++)
     {
          if(dist[i][strlen(s[i])+1].len<min.len)
          {
               min.len=dist[i][strlen(s[i])+1].len;
               memset(min.str,'\0',sizeof(min.str));
               strcpy(min.str,dist[i][strlen(s[i])+1].str);                                    
          }
          else if(dist[i][strlen(s[i])+1].len==min.len)
              if(strcmp(dist[i][strlen(s[i]+1)].str,min.str)<0)
              {
                  min.len=dist[i][strlen(s[i])+1].len;
                  memset(min.str,'\0',sizeof(min.str));
                  strcpy(min.str,dist[i][strlen(s[i])+1].str);                                                 
              }
     }
     fprintf(fo,"%ld\n",min.len);
     fprintf(fo,"%s",min.str);
     fclose(fp);
     fclose(fo);
}
