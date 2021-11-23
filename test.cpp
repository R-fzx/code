#include <bits/stdc++.h>
using namespace std;
int f(char x)
{
    string d="dafwj";
    if(int(d.find(x))!=-1)return 2;
}

int main()
{
    char c;
    cin>>c;
    cout<<f(c)<<endl;
    return 0;
}