program ex;
var
  fin,fout:text;
  i,j,n:longint;
  x,y:array[0..200000] of int64;
  ans:int64;
begin
  assign(fin,'dark.in');
  reset(fin);
  assign(fout,'dark.out');
  rewrite(fout);
  readln(fin,n);
  for i:=1 to n do
  begin
    readln(fin,x[i],y[i]);
    for j:=1 to i-2 do
      if (x[i]=x[j]) and (y[i]=y[j]) then
      begin
        writeln('0.00');
        close(fin);
        close(fout);
        halt;
      end;
  end;
  ans:=maxlongint;
  for i:=1 to n do
    for j:=1 to i-1 do
    begin
      if sqr(x[i]-x[j])+sqr(y[i]-y[j])<ans then
        ans:=sqr(x[i]-x[j])+sqr(y[i]-y[j]);
    end;
  writeln(fout,sqrt(ans):0:2);
  close(fin);
  close(fout);
end.
