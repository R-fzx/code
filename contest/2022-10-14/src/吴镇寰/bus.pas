const
    maxn=100000;
var
    infile,outfile:text;
    n:longint;
    a,f:array[1..maxn]of longint;
    min:longint=maxlongint;
    i,k:longint;
    ans:int64=0;
begin
    assign(infile,'bus.in');reset(infile);
    assign(outfile,'bus.out');rewrite(outfile);
    filldword(f,sizeof(f)div 4,0);
    readln(infile,n);
    for i:=1 to n do
        read(infile,a[i]);
    for i:=1 to n do
    begin
        if a[i]<min then
        begin
            min:=a[i];
            k:=i;
        end;
        inc(f[k]);
    end;
    for i:=1 to n do
        inc(ans,f[i]*a[i]);
    writeln(outfile,ans);
    close(infile);
    close(outfile);
end.