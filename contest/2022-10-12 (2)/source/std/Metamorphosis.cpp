#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define S size()
#define B begin()
#define E end()
#define P push_back
#define L length()
#define fu(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=b-1;i>=a;--i)
typedef long long int64;
using namespace std;

struct point
{
    int x,y;
};

struct line
{
    point v,d;
};

class FractalPicture
{
	public:
        vector <line> l1[6],l2;
        
        bool init(int st,int en,int x) { return st<=x && x<=en; }

        int check(int x1,int y1,int x2,int y2,line a)
        {
            if(a.v.x==a.d.x)
            {
                swap(x1,y1);swap(x2,y2);
                swap(a.v.x,a.v.y);swap(a.d.x,a.d.y);
            }
            
            if(init(y1,y2,a.v.y) && !(min(a.v.x,a.d.x)>x2 || max(a.v.x,a.d.x)<x1)) return min(x2,max(a.v.x,a.d.x))-max(x1,min(a.v.x,a.d.x));
            else return 0;
        }

        bool judge(int x1,int y1,int x2,int y2,line a)
        {
            return init(x1,x2,a.v.x) && init(x1,x2,a.d.x+a.v.x)
                && init(y1,y2,a.v.y) && init(y1,y2,a.d.y+a.v.y);
        }
        
        bool inrec(int x1,int y1,int x2,int y2,line a)
        {
            return ( (a.v.x==x1 || a.v.x==x2) && (!a.d.x) && init(y1,y2,a.v.y) && init(y1,y2,a.v.y+a.d.y) )
            || ( (a.v.y==y1 || a.v.y==y2) && (!a.d.y) && init(x1,x2,a.v.x) && init(x1,x2,a.v.x+a.d.x) );
        }
        
        double getLength(int x1,int y1,int x2,int y2)
        {
            double ans=0;
            line st;

            st.v.x=0;st.v.y=0;
            st.d.x=0;st.d.y=81;
            l1[1].P(st);
            
            for(int i=2;i<=5;i++)
            {
                for(int j=0;j<l1[i-1].S;j++)
                {
                    line tmp;
                    point dir,en;

                    dir=l1[i-1][j].d;
                    dir.x/=3;dir.y/=3;

                    en.x=l1[i-1][j].v.x+dir.x*2;
                    en.y=l1[i-1][j].v.y+dir.y*2;
                    tmp.v=l1[i-1][j].v;tmp.d=en;
                    l2.P(tmp);

                    tmp.v=en;tmp.d=dir;
                    l1[i].P(tmp);
                    swap(tmp.d.x,tmp.d.y);
                    l1[i].P(tmp);
                    tmp.d.x*=-1;tmp.d.y*=-1;
                    l1[i].P(tmp);
                }
            }
            
            //cout<<l2.S<<":"<<endl;
            for(int i=0;i<l2.S;i++) 
            {
			    ans+=check(x1,y1,x2,y2,l2[i]);
			    //cout<<ans<<endl;
			}
			
			//cout<<l1[5].S<<':'<<endl;
            for(int i=0;i<l1[5].S;i++)
            {
                //cout<<'('<<l1[5][i].v.x<<','<<l1[5][i].v.y<<')';
                //cout<<'('<<l1[5][i].v.x+l1[5][i].d.x<<','<<l1[5][i].v.y+l1[5][i].d.y<<')'<<' ';
                if(inrec(x1,y1,x2,y2,l1[5][i])) ans+=166;//cout<<166<<endl;
                else if(judge(x1,y1,x2,y2,l1[5][i])) ans+=331;//cout<<331<<endl;
            }

            return ans;
        }
}a;

int main()
{
    freopen("Metamorphosis.in","r",stdin);
    freopen("Metamorphosis.out","w",stdout);
    
    int xx1,yy1,xx2,yy2;
    
    cin>>xx1>>yy1>>xx2>>yy2;
    printf("%.1lf\n",a.getLength(xx1,yy1,xx2,yy2));
    return 0;
}
