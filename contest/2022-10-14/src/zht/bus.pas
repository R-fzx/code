var
  inp,outp:text;
  i,j,k,n:longint;
  ans,m,t:int64;
begin
  assign(inp,'bus.in');reset(Inp);
  assign(outp,'bus.out');rewrite(outp);
  readln(inp,n);
  t:=maxlongint shr 3;
  for i:=1 to n do
    begin
      read(inp,m);
      if m<t then
        begin
          inc(ans,m);
          t:=m;
          continue;
        end;
      inc(ans,t);
    end;
  writeln(outp,ans);
  close(inp);close(outp);
end.
