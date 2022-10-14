program codes;
const
maxn=1000;
var
n,cln:longint;
words,now:ansistring;
s:array[1..21]of ansistring;

procedure init;
var
i,x,y:longint;
begin
readln(n);
for i:= 1 to n do readln(s[i]);
end;

function min(a,b:longint):longint;
begin
if a<b then exit(a) else exit(b);
end;

procedure dfs(t:ansistring;k:longint);
var
i,x,y,len:longint;
t0:ansistring;
begin
if k>maxn then exit;
if k>cln then exit;
if t='' then
  begin
  if k<cln then words:=now;
  if (k=cln) and (now<words) then words:=now;
  cln:=k;
  exit;
  end;
t0:=t;
for i:= 1 to n do
  begin
  len:=min(length(t),length(s[i]));
  if copy(s[i],1,len)=copy(t,1,len) then
    begin
    if length(t)<length(s[i]) then t:=s[i];
    now:=now+copy(t,1,len);
    delete(t,1,len);
    dfs(t,k+len);
    t:=t0;
    delete(now,k+1,len);
    end;
  end;
end;

procedure main;
var
i,j,x,y,len:longint;
t:ansistring;
begin
cln:=maxn;
for i:= 1 to n-1 do
 for j:= i+1 to n do
   begin
   len:=min(length(s[i]),length(s[j]));
   if copy(s[i],1,len)<>copy(s[j],1,len) then continue;
   if length(s[i])>length(s[j]) then t:=s[i] else t:=s[j];
   now:=copy(s[i],1,len);
   delete(t,1,len);
   dfs(t,len);
   end;
writeln(cln);
writeln(words);
end;

begin
assign(input,'codes.in');reset(input);
assign(output,'codes.out');rewrite(output);
init;
main;
close(input);close(output);
end.

