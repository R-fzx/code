#include<fstream>
#include<cmath>
#include<string.h>
#include<iostream>
using namespace std;
ifstream fin("t3.in");
ofstream fout("t3.out");

const int NUM=5000+10;
const int maxn=1000;
struct bign
{
	int len, s[maxn];
	bign() 
	{
    	memset(s, 0, sizeof(s));
    	len = 1;
	}
	bign(int num) 
	{
    	*this = num;
	}
	bign(const char* num)
	{
    	*this = num;
	}
	bign operator =(int num) 
	{
    	char s[maxn];
    	sprintf(s, "%d", num);
    	*this = s;
    	return *this;
	}
	bign operator =(const char* num) 
	{
    	len = strlen(num);
    	for(int i = 0; i < len; i++)
			s[i] = num[len-i-1] - '0';
    	return *this;
	}
	string str() const 
	{
    	string res = "";
    	for(int i = 0; i < len; i++) 
			res = (char)(s[i] + '0') + res;
    	if(res == "") res = "0";
    	return res;
	}
	bign operator + (const bign& b) const
	{
    	bign c;
    	c.len =0;
    	for(int i=0,g=0;g||i<max(len, b.len);i++) 
		{
      		int x=g;
      		if(i<len)x+=s[i];
      		if(i<b.len)x+=b.s[i];
      		c.s[c.len++]=x%10;
      		g=x/10;
    	}
    	return c;
	}
	bign operator - (const bign& b)
	{
    	bign c; c.len = 0;
    	for(int i = 0, g = 0; i < len; i++)
		{
      		int x = s[i] - g;
      		if(i < b.len) x -= b.s[i];
      		if(x >= 0) g = 0;
      		else 
	  		{
        		g = 1;
        		x += 10;
      		}
      		c.s[c.len++] = x;
    	}
    	c.clean();
    	return c;
	}
	bign operator * (const int b) const
	{
    	bign c;
    	c.len=0;
		if(len==0||(len==1&&s[0]==0))
		{
			return c;
		}
    	for(int i=0;i<len;i++)
    	{
			c.s[i]=s[i]*b;
			++c.len;
		}
		for(int i=0;i<len;i++)
    	{
			if(i==len-1&&c.s[i]/10!=0)++c.len;
			c.s[i+1]+=c.s[i]/10;
			c.s[i]=c.s[i]%10;
		}
		return c;
	}
	bign operator*(const bign& b) const
	{
    	bign c=0;
    	c.len=0;
    	for(int i=len-1;i>=0;i--) 
		{
			bign t=b*s[i];
			c=c*10+t;
    	}
    	return c;
	}
	void clean() 
	{
    	while(len > 1 && !s[len-1]) len--;
	}
	bool operator < (const bign& b) const
	{
    	if(len != b.len) return len < b.len;
    	for(int i = len-1; i >= 0; i--)
      		if(s[i] != b.s[i]) return s[i] < b.s[i];
    	return false;
	}
	bool operator == (const bign& b) const
	{
    	if(len != b.len) return 0;
    	for(int i = len-1; i >= 0; i--)
      		if(s[i] != b.s[i]) return 0;
    	return 1;
	}
};

istream& operator >> (istream &in, bign& x) 
{
	string s;
	in>> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream &out, const bign& x) 
{
	out << x.str();
	return out;
}

int n;
bign f[300];
bign p[200][200];
bign t[300];

int main()
{
	fin>>n;
	f[1]=0;
	f[2]=1;
	f[3]=2;
	t[0]=t[1]=1;
	t[2]=2;t[3]=6;
	p[3][1]=1;p[3][2]=3;p[3][3]=3;p[3][4]=1;
	for(int i=4;i<=n;i++)
	{
		f[i]=(f[i-1]+f[i-2])*bign(i-1);
	}
	fout<<f[n]<<endl;
}
