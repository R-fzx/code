const
    maxn=200000;
var
    infile,outfile:text;
    n:longint;
    x,y:array[1..maxn] of double;
    now:double;
    ans:double=1000000000000000;
    i,j:longint;
begin
    assign(infile,'dark.in');reset(infile);
    assign(outfile,'dark.out');rewrite(outfile);
    readln(infile,n);
    for i:=1 to n do
        readln(infile,x[i],y[i]);
    for i:=1 to n-1 do
        for j:=i+1 to n do
        begin
            now:=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
            if now<ans then
                ans:=now;
        end;
    writeln(outfile,sqrt(ans)/2:0:3);
    close(infile);
    close(outfile);
end.