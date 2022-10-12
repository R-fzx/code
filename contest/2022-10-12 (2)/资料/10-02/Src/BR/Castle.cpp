#include<stdio.h>
#include<stdlib.h>
#define mOd 2147483647LL
FILE *fin=fopen("Castle.in","r");
FILE *fout=fopen("Castle.out","w");
struct cas{
	long to,ne;
}mp[1000003];
long ap[1003][1003];
long st[1003],mps,str[10003],fa[1003],di[1003];
bool in[1003],fp[1003];
long long ans;
int main(){
	long i,j,k,m,n,o,p,q,h,t;
	fscanf(fin,"%ld%ld",&n,&m);
	for (i=1;i<=m;++i){
		fscanf(fin,"%ld%ld%ld",&o,&p,&q);
		if (o==p){
			if (q==0) fp[o]=1;
			continue;
		}
		if (ap[o][p]==0){
			++mps;
			mp[mps].to=p;
			mp[mps].ne=st[o];
			st[o]=mps;
			++mps;
			mp[mps].to=o;
			mp[mps].ne=st[p];
			st[p]=mps;
			ap[o][p]=ap[p][o]=q;
		}
		else if (ap[o][p]>q) ap[o][p]=q;
	}
	h=0;
	t=1;
	str[1]=1;
	for (i=2;i<=n;++i) di[i]=2147483647;
	while (h<t){
		++h;
		for (i=st[str[h]];i!=0;i=mp[i].ne){
			p=mp[i].to;
			q=ap[str[h]][p];
			if (di[p]>di[str[h]]+q){
				di[p]=di[str[h]]+q;
				fa[p]=1;
				if (!in[p]){
					str[++t]=p;
					in[p]=1;
				}
			}
			else if (di[p]==di[str[h]]+q) ++fa[p];
		}
		in[str[h]]=0;
	}
	fa[1]=1;
	for (i=1;i<=n;++i)
		fa[i]+=fp[i];
	ans=1LL;
	for (i=1;i<=n;++i) ans=(ans*(long long)(fa[i]))%mOd;
	fprintf(fout,"%I64d\n",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
