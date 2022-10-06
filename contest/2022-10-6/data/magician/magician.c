i,n,m,x,y,z=1,f[200020];
F(x){
	return f[x]?f[x]=F(f[x]):x;
}
main(){
	for(scanf("%d %d",&n,&m);m--;)
		scanf("%d %d",&x,&y),F(x)-F(y)?f[F(x)]=F(y):(z=z*2%1000000009),printf("%d\n",z-1);
}
