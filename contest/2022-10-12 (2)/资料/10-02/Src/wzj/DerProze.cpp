#include<stdio.h>
#include<stdlib.h>
long a,b,c,i,j,k,l,x,xq,y,z;
int main(){
	freopen("DerProze.in","r",stdin);
	freopen("DerProze.out","w",stdout);
	scanf("%ld%ld%ld",&a,&b,&c); 
	xq=6;
	if(a<2000){x=a;y=2000;z=1;}
	else{x=2000;y=a;z=-1;}
	for(i=x;i<y;i++){
		if((i%100!=0 && i%4==0)|| i%400==0){
			xq-=2*z;
			if(xq<1)xq+=7;
			if(xq>7)xq-=7;
		}else{
			xq-=1*z;
			if(xq<1)xq+=7;
			if(xq>7)xq-=7;
		}		
	}
	for(i=1;i<b;i++){
		if(i==4 || i==6 || i==9 || i==11 ){
			xq+=2;
			if(xq>7)xq-=7;
		}else if(i==2){
			if((a%100!=0 && a%4==0)|| a%400==0){
				xq+=1;
			}
			if(xq>7)xq-=7;
		}else{
			xq+=3;
			if(xq>7)xq-=7;
		}
	}
	xq+=c-1;
	xq=(xq-1)%7+1;
	if(xq==1)printf("monday\n");
	if(xq==2)printf("tuesday\n");
	if(xq==3)printf("wednesday\n");
	if(xq==4)printf("thursday\n");	
	if(xq==5)printf("friday\n");
	if(xq==6)printf("saturday\n");
	if(xq==7)printf("sunday\n");		
	return 0;
}// monday tuesday wednesday thursday friday  saturday sunday 
