#include <stdio.h>
#include <string.h>
char st[21][32]={""},tt[1002]="",as[1002]="";
int rot,s=0,a[201]={0},gs=0,len[201]={0},ans=0,n,tl=0,ttl=0;
short hash[20][1<<19+1]={0};
int has(char str[],int l)
{int i=0,s=0,t=0;
 for(i=1;i<=l;i++)s=(s*2+str[i]-'0')%(1<<20+1);
 return(s%(1<<20+1));
}
/*void dfs(char t[],*/
/*int check(int k)
{int i,j,fl=0;
 if(k>ans)return(0);
 if(s>=2)return(1);
 if(k<ans)
 {for(i=1;i<=n;i++)
  if(len[i]+k<=ans)
  {fl=0;a[k]=i;
   for(j=k+1;j<=len[i]+k;j++) 
     if(t[j]!=st[i][j-k]){fl=1;break;}
   if(!fl)
   {if(check(k+len[i]))return(1);}
   a[k]=0;
  }
 }
 else s++;
 if(s>=2)return(1);
 return(0);
}    
int dfs(int k)
{int i,j;
 if(k>ans)return 0;
 if(k<ans)
 {for(i=1;i<=n;i++)
  if(len[i]+k<=ans)
  {for(j=k+1;j<=len[i]+k;j++)
     t[j]=st[i][j-k];
   if(dfs(k+len[i]))return(1);
  }
 }
 else
 {s=0;if(check(0))return(1);
 }
 return(0);
}*/
/*int small(int a,int b)
{int i,j;
 char t1[201]="",t2[201]="";
 for(i=1;i<=len[a]+len[b];i++)
 {if(i<=len[a])t1[i]=st[a][i];else t1[i]=st[b][i-len[a]];
  if(i<=len[b])t2[i]=st[b][i];else t2[i]=st[a][i-len[b]];
 }
 for(i=1;i<=len[a]+len[b];i++)
   if(t1[i]<t2[i])return(1);
   else if(t2[i]<t1[i])return(0);
 return(1);
}
*/
/*int ssmall(char a[],int l1,char b[],int l2)
{int i,j;
 char t1[1001]="",t2[1001]="";
 for(i=1;i<=l1+l2;i++)
 {if(i<=l1)t1[i]=a[i];else t1[i]=b[i-l1];
  if(i<=l2)t2[i]=b[i];else t2[i]=a[i-l2];
 }
 for(i=1;i<=l1+l2;i++)
   if(t1[i]<t2[i])return(1);
   else if(t2[i]<t1[i])return(0);
 return(1);
}
int chec(char a[],char b[])
{int i,j,fl=0,l1,l2;
 for(i=1;b[i]!='\0'&&a[i]!='\0';i++)
   if(a[i]!=b[i]){fl=1;break;}
 return(!fl);
}*/
void dfs(char str[],int t,int fll)
{char tmp[21]="";
 int i,tl1,tl2,l,j,fl;
 tl1=strlen(str);
 if(t>ans)return;
 for(i=1;i<=n;i++)
   if(i!=rot||fll)
   {fl=1;
    tl2=strlen(st[i]);
    for(j=0;str[j]!='\0'&&st[i][j]!='\0';j++)
      if(str[j]!=st[i][j])
      {fl=0;break;}
    if(fl)
    {int f=0;
     if(tl1<tl2)
     {for(j=tl1;j<tl2;j++)
      {tt[j+t-tl1]=st[i][j];
       tmp[j-tl1]=st[i][j];
       f=f*2+st[i][j]-'0';
      }
      if(hash[tl2-tl1][f]=='\0')
      {hash[tl2-tl1][f]=1;
       dfs(tmp,t+tl2-tl1,1);
       hash[tl2-tl1][f]='\0';
      } 
      for(j=tl1;j<tl2;j++)
      {tt[j+t-tl1]='\0';
       tmp[j-tl1]='\0';
      }
     }else if(tl2<tl1)
     {for(j=tl2;j<tl1;j++)
      {tmp[j-tl2]=str[j];
       f=f*2+str[j]-'0';
      }
      if(hash[tl1-tl2][f]=='\0')
      {hash[tl1-tl2][f]=1;
       dfs(tmp,t,1);
       hash[tl1-tl2][f]='\0';
      } 
      for(j=tl2;j<tl1;j++)tmp[j-tl2]='\0';
     } 
     else if(tl1==tl2)
     {if(ans>t||ans==t&&strcmp(tt,as)<0)
      {for(j=0;j<ans;j++)as[j]=tt[j];ans=t;}
     }
   }
  }
 }
/*int dfs()
{int i,j;
 char tmp1[1001]="",tmp2[1001]="";
 int tl1,tl2;
 if(tl+ttl>=ans)return 0;
 for(i=1;i<=n;i++)
  if(ttl+len[i]<=ans)
  if(chec(t,st[i]))
  {if(tl>len[i])
   {for(j=1;j<=ttl;j++)tmp1[j]=tt[j];
    tl1=ttl;
    for(j=1;j<=tl;j++)tmp2[j]=t[j];
    tl2=tl;
    for(j=1;j<=len[i];j++)tt[j+ttl]=st[i][j];
    ttl+=len[i];
    for(j=1;j<=tl-len[i];j++)t[j]=t[j+len[i]];
    for(;j<=tl;j++)t[j]='\0';
    tl=tl-len[i];
    int t1=has(t,tl);
    if(hash[tl][t1]<5){hash[tl][t1];dfs();}
    for(j=1;j<=tl1||j<=ttl;j++){tt[j]=tmp1[j];tmp1[j]='\0';}
    ttl=tl1;
    tl1=0;
    for(j=1;j<=tl2||j<=tl;j++){t[j]=tmp2[j];tmp2[j]='\0';}
    tl=tl2;
    tl2=0;
   }else if(tl<=len[i])
   {for(j=1;j<=ttl;j++)tmp1[j]=tt[j];
    tl1=ttl;
    for(j=1;j<=tl;j++)tmp2[j]=t[j];
    tl2=tl;
    for(j=1;j<=tl;j++)tt[j+ttl]=t[j];
    ttl+=tl;
    for(j=1;j<=len[i]-tl;j++)t[j]=st[i][j+tl];
    for(;j<=len[i];j++)t[j]='\0';
    tl=len[i]-tl;
    if(tl==0)
    {if(ttl<=ans)
      if(ttl==ans&&ssmall(tt,ttl,as,ans)||ttl<ans)
      {for(i=1;i<=ttl;i++)as[i]=tt[i];
       for(i=ttl+1;i<=ans;i++)as[i]='\0';
       ans=ttl;
      }
    }
    int t1=has(t,tl);
    if(hash[tl][t1]<5){hash[tl][t1]++;dfs();}
    for(j=1;j<=tl1||j<=ttl;j++){tt[j]=tmp1[j];tmp1[j]='\0';}
    ttl=tl1;
    tl1=0;
    for(j=1;j<=tl2||j<=tl;j++){t[j]=tmp2[j];tmp2[j]='\0';}
    tl=tl2;
    tl2=0;
   }
  }
 return 0;
}*/
main()
{FILE *fp,*fo;
 int m,i,j,l,k;
 fp=fopen("codes.in","r");
 fo=fopen("codes.out","w");
 fscanf(fp,"%d\n",&n);
 for(i=1;i<=n;i++)
 {fscanf(fp,"%s",st[i]);
  len[i]=strlen(st[i]);
  /*for(j=len[i];j>=1;j--)st[i][j]=st[i][j-1];
  st[i][0]='\0';*/
 }
 ans=117;
 /*for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
     if(!small(i,j))
     {l=len[i];len[i]=len[j];len[j]=l;
      for(l=1;l<=30;l++)
      {char ttt=st[i][l];
       st[i][l]=st[j][l];
       st[j][l]=ttt;
      }
     }  
 */
 
 /*do
 {ans++;
  if(dfs(0))break;
 }while(ans<=200);*/
 /*ans=9;
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     if(chec(st[i],st[j]))
     {if(len[j]<len[i]&&i!=j&&len[i]<=ans)
     {for(k=1;k<=len[j];k++)tt[k]=st[j][k];
      ttl=len[j];
      for(k=len[j]+1;k<=len[i];k++)t[k-len[j]]=st[i][k];
      tl=len[i]-len[j];
      dfs();
      for(i=1;i<=ttl;i++)tt[i]='\0';
     }
     else if(len[j]==len[i]&&i!=j&&len[i]<=ans)
     {if(ttl<=ans)
      if(ttl==ans&&ssmall(tt,ttl,as,ans)||ttl<ans)
      {for(i=1;i<=ttl;i++)as[i]=tt[i];
       for(i=ttl+1;i<=ans;i++)as[i]='\0';
       ans=ttl;
      }
     }
   }*/ 
 for(i=1;i<=n;i++)
 {for(j=0;j<len[i];j++)tt[j]=st[i][j];
  ttl=len[i];
  rot=i;
  dfs(st[i],len[i],0);
  for(j=0;j<len[i];j++)tt[j]='\0';
  ttl=0;
 } 
 fprintf(fo,"%d\n",ans); 
 for(i=0;i<ans;i++)fprintf(fo,"%c",as[i]);
 fclose(fp);
 fclose(fo);
}
