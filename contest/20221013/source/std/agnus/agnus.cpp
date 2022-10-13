#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 30010
char s[N];int n;
long long ans = 0;
int main()
{
    freopen("agnus.in","r",stdin);
    freopen("agnus.out","w",stdout);
    
	scanf("%s",s+1);n = strlen(s+1);
    int last = 0,left,right;
    for(int i=1;i+4<=n;i++) 
    {
        if(s[i]=='a'&&s[i+1]=='g'&&s[i+2]=='n'&&s[i+3]=='u'&&s[i+4]=='s')
        {
            left = i-last;
            right = n-i-3;
            ans+=(long long)left*right;
            last = i;
            i+=4;
        }      
    }  
    printf("%lld",ans);
    return 0;
}
