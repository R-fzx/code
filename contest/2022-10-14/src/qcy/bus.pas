var
  min,x:int64;
  i,n,s:longint;
  ip,op:text;
begin
  assign(ip,'bus.in'); reset(ip);
  assign(op,'bus.out'); rewrite(op);
  readln(ip,n);
  min:=1000000;
  x:=0;
  for i:=1 to n do begin
    read(ip,s);
    if s<min then min:=s;
    x:=x+min;
  end;
  writeln(op,x);
  close(ip);
  close(op);
end.