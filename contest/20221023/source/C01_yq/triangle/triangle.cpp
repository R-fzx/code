#include<bits/stdc++.h>
#define lson (x<<1)
#define rson ((x<<1)|1)
#define inf 1000000010
using namespace std;
const int maxn=100010;
int n,q,a[maxn];
// struct Tree{
//     pair<int,int>maxx;
//     int maxx_third;
//     pair<int,int>minn;
//     int minn_third;
// }tree[maxn<<2],kkk1,kkk2,kkk;
// vector<int>tmp;
// void modify(int x,int l,int r,int L,int val){
//     if(l>L||r<L)return;
//     if(l==r&&l==L){
//         tree[x].maxx.first=val;
//         tree[x].minn.first=val;
//         return;  
//     }
//     int mid=(l+r)>>1;
//     modify(lson,l,mid,L,val);
//     modify(rson,mid+1,r,L,val);
//     tmp.clear();
//     tmp.push_back(tree[lson].maxx.first);
//     tmp.push_back(tree[lson].maxx.second);
//     tmp.push_back(tree[lson].maxx_third);
//     tmp.push_back(tree[rson].maxx.first);
//     tmp.push_back(tree[rson].maxx.second);
//     tmp.push_back(tree[rson].maxx_third);
//     sort(tmp.begin(),tmp.end());
//     tree[x].maxx.first=tmp[5];
//     tree[x].maxx.second=tmp[4];
//     tree[x].maxx_third=tmp[3];tmp.clear();
//     tmp.push_back(tree[lson].minn.first);
//     tmp.push_back(tree[lson].minn.second);
//     tmp.push_back(tree[lson].minn_third);
//     tmp.push_back(tree[rson].minn.first);
//     tmp.push_back(tree[rson].minn.second);
//     tmp.push_back(tree[rson].minn_third);
//     sort(tmp.begin(),tmp.end());
//     int tot=0;
//     while(tmp[tot]==0)tot++;
//     tree[x].minn.first=tmp[tot];
//     if(tot+1<tmp.size())tree[x].minn.second=tmp[tot+1];
//     else tree[x].minn.second=0;
//     if(tot+2<tmp.size())tree[x].minn_third=tmp[tot+2];
//     else tree[x].minn_third=0;
//     return;
// }
// Tree query(int x,int l,int r,int L,int R){
//     //if(L==2&&R==5&&l==2&&r==2)cout<<tree[x].minn.first<<' '<<tree[x].minn.second<<' '<<tree[x].minn_third<<endl;
//     if(L<=l&&r<=R)return tree[x];
//     if(r<L||l>R)return Tree{{0,0},0,{0,0},0};
//     int mid=(l+r)>>1;
//     kkk1=query(lson,l,mid,L,R);
//     kkk2=query(rson,mid+1,r,L,R);
//     tmp.clear();
//     tmp.push_back(kkk1.maxx.first);
//     tmp.push_back(kkk1.maxx.second);
//     tmp.push_back(kkk1.maxx_third);
//     tmp.push_back(kkk2.maxx.first);
//     tmp.push_back(kkk2.maxx.second);
//     tmp.push_back(kkk2.maxx_third);
//     sort(tmp.begin(),tmp.end());
//     kkk.maxx.first=tmp[5];
//     kkk.maxx.second=tmp[4];
//     kkk.maxx_third=tmp[3];tmp.clear();
//     tmp.push_back(kkk1.minn.first);
//     tmp.push_back(kkk1.minn.second);
//     tmp.push_back(kkk1.minn_third);
//     tmp.push_back(kkk2.minn.first);
//     tmp.push_back(kkk2.minn.second);
//     tmp.push_back(kkk2.minn_third);
//     sort(tmp.begin(),tmp.end());
    
//     int tot=0;
//     while(tmp[tot]==0)tot++;
//     kkk.minn.first=tmp[tot];
//     if(tot+1<tmp.size())kkk.minn.second=tmp[tot+1];
//     else kkk.minn.second=0;
//     if(tot+2<tmp.size())kkk.minn_third=tmp[tot+2];
//     else kkk.minn_third=0;
//   //  if(L==2&&R==5&&l==1&&r==2)cout<<kkk.minn.first<<' '<<kkk.minn.second<<' '<<kkk.minn_third<<endl;
//     return kkk;
// }
int main(){
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //cout<<tree[2].minn.first<<' '<<tree[2].minn.second<<' '<<tree[2].minn_third<<endl<<endl;
    while(q--){
        int l,r;cin>>l>>r;
        vector<int>tmp;
        for(int i=l;i<=r;i++)tmp.push_back(a[i]);
        if(r-l<2){cout<<"No"<<endl;continue;}
        bool flag=0;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size()-2;i++){
            if(tmp[i]+tmp[i+1]>tmp[i+2]){
                if(tmp[i+2]-tmp[i+1]<tmp[i]){flag=1;break;}
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}