#include<bits/stdc++.h>
#define printlf(x) print(x),putchar('\n')
#define printsp(x) print(x),putchar(' ')
using namespace std;
inline int read(){
    int x=0;
    bool w=0;
    char c=getchar();
    while(!isdigit(c))  w|=c=='-',c=getchar();
    while(isdigit(c))   x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void print(int x){
    if(x<0) x=-x,putchar('-');
    if(x>9) print(x/10);
    putchar('0'+x%10);
}
int n;
double r;
//map<double,int> mp;
inline double qp(int a,int b)
{
	double res=1;
	while(b){
		if(b&1)	res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	while(cin>>n>>r){
		for(register double i=1;;++i){
			bool flag=0;
			for(register double j=1;j<i;++j){
				double x=(j/i*qp(10,n+1));
//				cout<<j<<' '<<i<<' '<<(j/i)<<' '<<x<<' '<<(int)x<<endl;
//				if(mp[(int)(x)])	continue;
//				mp[(int)(x)]=i;
				int val=((int)x)-(int)(r*qp(10,n+1));
				if((val<=4 && val>=0) || ((-val)<=5) && val<=0){
					printlf(i);
					flag=1;
					break;
				}
				if(val>4)	break;
			}
			if(flag)	break;
		}
	}
    return 0;	
}

