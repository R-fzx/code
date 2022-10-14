program test;
const
p=999983;
var
i,x,y:longint;
begin
assign(output,'output.txt');rewrite(output);
x:=1;
for i:= 1 to 1000 do
  begin
  x:=x*3 mod p;
  write(x,',');
  if i mod 10 = 0 then writeln;
  end;
close(output);
end.

