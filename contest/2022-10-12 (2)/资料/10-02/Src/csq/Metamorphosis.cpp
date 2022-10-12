#include<stdio.h>
#include<stdlib.h>
long x1,x2,y1,y2,ans;
long abs(long x){
     return x>0?x:-x;
}
long min(long x,long y){
     return x>y?y:x;
}
long max(long x,long y){
     return x<y?y:x;
}
void dfs1(long,long,long,long,long);
void dfs2(long,long,long,long,long);
void dfs3(long,long,long,long,long);
void dfs4(long,long,long,long,long);
int main(){
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    scanf("%ld",&x1);
    scanf("%ld",&y1);
    scanf("%ld",&x2);
    scanf("%ld",&y2);
    dfs2(0,0,0,81,0);
    printf("%ld.0\n",ans);
    //system("pause");
    return 0;
}
void dfs1(long xx1,long yy1,long xx2,long yy2,long z){
     //printf("%ld %ld %ld %ld %ld %ld 4\n",ans,xx1,yy1,xx2,yy2,z);
     //system("pause");
     if (abs(xx2-xx1)<=1&&abs(yy2-yy1)<=1){
         if (xx1<=x2&&xx2>=x1){
             if (y1<=yy1&&y2>=yy2)
                 ans++;
             if (y1<yy1&&y2>=yy2)
                 ans+=165;
             if (y2>yy2&&y1<=yy1)
                 ans+=165;
             }
         return;
         }
     if (y1<=yy1 && y2>=yy2)
         if (min(x2,xx1)-max(x1,xx2-(xx2-xx1)/3)>0)
             ans+=min(x2,xx1)-max(x1,xx2-(xx2-xx1)/3);
     dfs1(xx2-(xx2-xx1)/3,yy1,xx2,yy2,4);
     dfs2(xx2-(xx2-xx1)/3,yy1,xx2-(xx2-xx1)/3,yy1-(xx2-xx1)/3,4);
     dfs4(xx2-(xx2-xx1)/3,yy1,xx2-(xx2-xx1)/3,yy1+(xx2-xx1)/3,4);
     return;
}
void dfs2(long xx1,long yy1,long xx2,long yy2,long z){
     //printf("%ld %ld %ld %ld %ld %ld 1\n",ans,xx1,yy1,xx2,yy2,z);
     //system("pause");
     if (abs(xx2-xx1)<=1&&abs(yy2-yy1)<=1){
         if (yy1>=y1&&yy2<=y2){
             if (x1<=xx1&&x2>=xx2)
                 ans++;
             if (x1<xx1&&x2>=xx2)
                 ans+=165;
             if (x2>xx2&&x1<=xx1)
                 ans+=165;
             }
         return;
         }
     if (x1<=xx1 && x2>=xx2)
         if (min(y2,yy2-(yy2-yy1)/3)-max(y1,yy1)>0)
             ans+=min(y2,yy2-(yy2-yy1)/3)-max(y1,yy1);
     dfs2(xx1,yy2-(yy2-yy1)/3,xx2,yy2,1);
     dfs3(xx1,yy2-(yy2-yy1)/3,xx1+(yy2-yy1)/3,yy2-(yy2-yy1)/3,1);
     dfs1(xx1,yy2-(yy2-yy1)/3,xx1-(yy2-yy1)/3,yy2-(yy2-yy1)/3,1);
     return;
}
void dfs3(long xx1,long yy1,long xx2,long yy2,long z){
     //printf("%ld %ld %ld %ld %ld %ld 2\n",ans,xx1,yy1,xx2,yy2,z);
     //system("pause");
     if (abs(xx2-xx1)<=1&&abs(yy2-yy1)<=1){
         if (xx1>=x1&&xx2<=x2){
             if (y1<=yy1&&y2>=yy2)
                 ans++;
             if (y1<yy1&&y2>=yy2)
                 ans+=165;
             if (y2>yy2&&y1<=yy1)
                 ans+=165;
             }
         return;
         }
     if (y1<=yy1 && y2>=yy2)
         if (min(x2,xx2-(xx2-xx1)/3)-max(x1,xx1)>0)
             ans+=min(x2,xx2-(xx2-xx1)/3)-max(x1,xx1);
     dfs3(xx2-(xx2-xx1)/3,yy1,xx2,yy2,2);
     dfs4(xx2-(xx2-xx1)/3,yy1,xx2-(xx2-xx1)/3,yy1-(xx2-xx1)/3,2);
     dfs2(xx2-(xx2-xx1)/3,yy1,xx2-(xx2-xx1)/3,yy1+(xx2-xx1)/3,2);
     return;
}
void dfs4(long xx1,long yy1,long xx2,long yy2,long z){
     //printf("%ld %ld %ld %ld %ld %ld 3\n",ans,xx1,yy1,xx2,yy2,z);
     //system("pause");
     if (abs(xx2-xx1)<=1&&abs(yy2-yy1)<=1){
         if (yy2>=y1&&yy1<=y2){
             if (x1<=xx1&&x2>=xx2)
                 ans++;
             if (x1<xx1&&x2>=xx2)
                 ans+=165;
             if (x2>xx2&&x1<=xx1)
                 ans+=165;
             }
         return;
         }
     if (x1<=xx1 && x2>=xx2)
         if (min(y2,yy1)-max(y1,yy2-(yy2-yy1)/3)>0)
             ans+=min(y2,yy1)-max(y1,yy2-(yy2-yy1)/3);
     dfs4(xx1,yy2-(yy2-yy1)/3,xx2,yy2,3);
     dfs1(xx1,yy2-(yy2-yy1)/3,xx1+(yy2-yy1)/3,yy2-(yy2-yy1)/3,3);
     dfs3(xx1,yy2-(yy2-yy1)/3,xx1-(yy2-yy1)/3,yy2-(yy2-yy1)/3,3);
     return;
}
