var
  t,x,ans:qword;
  i,n:longint;
begin
  assign(input,'bus.in');reset(input);
  assign(output,'bus.out');rewrite(output);
  readln(n);
  t:=maxlongint;
  for i:=1 to n do
  begin
    read(x);
    if x<t then t:=x;
    inc(ans,t);
  end;
  writeln(ans);
  close(input);
  close(output);
end.