//type ansistring=string;
var
  n,m,c,i,j,tot:longint;
  b:array[1..250]of boolean;
  a:array[1..250]of ansistring;
  st:ansistring;
procedure dfs(i,s:longint;sddr:boolean;st1:ansistring);
var
  j:longint;
  st:ansistring;
begin
  if s=n then
  begin
    inc(tot);
    a[tot]:=st1;
  end
  else
    if sddr then
    begin
      for j:=i+1 to n do
        if not b[j] then
        begin
          b[j]:=true;
          str(j,st);
          dfs(j,s+1,false,st1+st+' ');
          b[j]:=false;
        end;
     end else
     begin
       for j:=1 to i-1 do
         if not b[j] then
         begin
           b[j]:=true;
           str(j,st);
           dfs(j,s+1,true,st1+st+' ');
           b[j]:=false;
         end;
    end;
end;
procedure qsort(l,r:longint);
var
  i,j:longint;
  mid,t:ansistring;
begin
  i:=l;j:=r;mid:=a[(i+j)shr 1];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      t:=a[i];a[i]:=a[j];a[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
begin
  assign(input,'wave.in');reset(input);
  assign(output,'wave.out');rewrite(output);
  readln(m);
  for i:=1 to m do
  begin
    readln(n,c);
    tot:=0;
    for j:=2 to n do
    begin
      fillchar(b,sizeof(b),false);
      str(j,st);
      b[j]:=true;
      dfs(j,1,false,st+' ');
    end;
    for j:=1 to n-1 do
    begin
      fillchar(b,sizeof(b),false);
      str(j,st);
      b[j]:=true;
      dfs(j,1,true,st+' ');
    end;
    qsort(1,tot);
    //for j:=1 to tot do writeln(a[j]);
    writeln(a[c]);
  end;
  close(input);
  close(output);
end.