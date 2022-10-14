var
  inp,outp:text;
  i,j,k,n,m:longint;
  x,y:array[1..200000] of double;
  ans:double;

procedure out(x:double);
begin
  writeln(outp,x:0:2);
  close(inp);close(outp);
  halt;
end;

begin
  assign(inp,'dark.in');reset(inp);
  assign(outp,'dark.out');rewrite(outp);
  readln(inp,n);
  ans:=100000000;
  for i:=1 to n do
    begin
     readln(inp,x[i],y[i]);
     for j:=1 to i-1 do
       if (x[i]=x[j])and(y[i]=y[j]) then out(0)
        else if ans>sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))then
          ans:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
    end;
  ans:=ans/2;
  out(ans);
end.

