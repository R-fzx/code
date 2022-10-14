program dark;
const
max=1e100;
var
n:longint;
cln:extended;
xi,yi:array[1..200001]of extended;

procedure init;
var
i,x,y:longint;
begin
readln(n);
for i:= 1 to n do readln(xi[i],yi[i]);
end;

procedure qsort(l,r:longint);
var
i,x,y:longint;
z,t:extended;
begin
x:=l;y:=r;z:=xi[(l+r) div 2];
repeat
while xi[x]<z do inc(x);
while xi[y]>z do dec(y);
if x<=y then
  begin
  t:=xi[x];xi[x]:=xi[y];xi[y]:=t;
  t:=yi[x];yi[x]:=yi[y];yi[y]:=t;
  inc(x);dec(y);
  end;
until x>y;
if x<r then qsort(x,r);
if l<y then qsort(l,y);
end;

procedure main;
var
i,j,x,y:longint;
t:extended;
begin
qsort(1,n);
cln:=max;
for i:= 1 to n-1 do
 for j:= i+1 to n do
   begin
   if xi[j]-xi[i]>=cln then break;
   t:=sqrt(sqr(xi[i]-xi[j])+sqr(yi[i]-yi[j]));
   if t<cln then cln:=t;
   end;
cln:=cln/2;
writeln(cln:0:2);
end;

begin
assign(input,'dark.in');reset(input);
assign(output,'dark.out');rewrite(output);
init;
main;
close(input);close(output);
end.

