program wave;
var
m,n:longint;
c:int64;
ans:array[1..21] of longint;
f:array[1..21,1..21,0..1]of int64;
b:array[0..21]of boolean;

procedure print;
var
i,x,y:longint;
begin
for i:= 1 to n-1 do write(ans[i],' ');
writeln(ans[n]);
end;

procedure prework;
var
i,j,k:longint;
begin
f[1,1,0]:=1;f[1,1,1]:=1;
for i:= 2 to 20 do
 for j:= 1 to i do
   begin
   for k:= 1 to j-1 do inc(f[i,j,1],f[i-1,k,0]);
   for k:= j to i-1 do inc(f[i,j,0],f[i-1,k,1]);
   end;
end;

function find(x:longint):longint;
var
i,t,s:longint;
begin
s:=0;
for i:= 1 to n do
  begin
  if not b[i] then inc(s);
  if s=x then exit(i);
  end;
end;

procedure cal(t,num,key:longint);
var
i,j,x,y,k:longint;
begin
//writeln(t,' ',c,' ',key,' ',num);
if t<1 then exit;
for i:= 1 to n do
  begin
  if (i<num) and (key=1) then continue;
  if (i>=num) and (key=0) then continue;
  if f[t,i,key]>=c then break;
  dec(c,f[t,i,key]);
  end;
//writeln(i);
x:=find(i);
if x>100 then x:=0;
b[x]:=true;
ans[n-t+1]:=x;
x:=i;
cal(t-1,x,1-key);
end;

procedure main;
var
i,x,y,k,key:longint;
chk:boolean;
begin
chk:=false;
for i:= 1 to n do if chk then break else
 for k:= 1 downto 0 do if chk then break else
   if f[n,i,k]>=c then
     begin
     b[i]:=true;ans[1]:=i;
     chk:=true;key:=k;x:=i;
     break;
     end
   else dec(c,f[n,i,k]);
cal(n-1,x,1-key);
end;

procedure init;
var
i,x,y:longint;
begin
prework;
readln(m);
for i:= 1 to m do
  begin
  fillchar(b,sizeof(b),false);
  fillchar(ans,sizeof(ans),0);
  readln(n,c);
  main;
  print;
  end;
end;

begin
assign(input,'wave.in');reset(input);
assign(output,'wave.out');rewrite(output);
init;
close(input);close(output);
end.

