program bus;
const
max=100000000;
var
n:longint;
cln,min:int64;
a:array[1..100001]of longint;

procedure init;
var
i,x,y:longint;
begin
readln(n);
for i:= 1 to n do read(a[i]);
end;

procedure main;
var
i,x,y:longint;
begin
min:=max;
for i:= 1 to n do
  begin
  if a[i]<min then min:=a[i];
  cln:=cln+min;
  end;
writeln(cln);
end;

begin
assign(input,'bus.in');reset(input);
assign(output,'bus.out');rewrite(output);
init;
main;
close(input);close(output);
end.

