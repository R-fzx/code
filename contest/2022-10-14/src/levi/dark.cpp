#include <stdio.h>
#include <math.h>

long x[200001],y[200001];
long anti_x[1000001],anti_y[1000001];
long xy[200001][2];

long abs(long i){
     if(i<0)
         return -i;
     return i;
}

void qsort_x(long low,long high){
     long t,left,right,mid;
     left=low;right=high;mid=x[(low+high)/2];
     do{
         while(x[left]<mid)left++;
         while(x[right]>mid)right--;
         if(left<=right){
             t=x[left];x[left]=x[right];x[right]=t;
             left++;right--;                
         }                      
     }while(left<=right);
     if(left<high)qsort_x(left,high);
     if(right>low)qsort_x(low,right);
}
void qsort_y(long low,long high){
     long t,left,right,mid;
     left=low;right=high;mid=y[(low+high)/2];
     do{
         while(y[left]<mid)left++;
         while(y[right]>mid)right--;
         if(left<=right){
             t=y[left];y[left]=y[right];y[right]=t;
             left++;right--;                
         }                      
     }while(left<=right);
     if(left<high)qsort_y(left,high);
     if(right>low)qsort_y(low,right);
}
int main(){
    FILE *in,*out;
    in=fopen("dark.in","r");
    out=fopen("dark.out","w");
    long i,j,k,m,n;
    long l,r,xm,ym;
    double min,value;
    min=2100000;
    fscanf(in,"%ld",&n);
    for(i=1;i<=n;i++){
        fscanf(in,"%ld %ld",&x[i],&y[i]); 
        anti_x[x[i]]=i;anti_y[y[i]]=i;   
        xy[i][0]=x[i];xy[i][1]=y[i]; 
    }   
    qsort_x(1,n);
    qsort_y(1,n);
    for(i=1;i<=n;i++){
        if(i<=3)
            l=1;
        else
            l=i-3;
        if(i>=n-3)
            r=n;
        else
            r=i+3;
        for(j=l;j<=r;j++){
            if(j!=i){
                xm=abs(x[i]-x[j]);
                ym=abs(xy[anti_x[x[i]]][1]-xy[anti_y[x[j]]][1]);  
                value=sqrt(xm*xm+ym*ym);
                if(value<min)
                    min=value; 
                ym=abs(y[i]-y[j]);
                xm=abs(xy[anti_y[y[i]]][0]-xy[anti_x[y[j]]][0]);  
                value=sqrt(xm*xm+ym*ym);
                if(value<min)
                    min=value;      
            }                  
        }                  
    }
    fprintf(out,"%0.2lf\n",min/2);
    fclose(in);
    fclose(out);
    return 0;    
}
