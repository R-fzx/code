var
  a:array[1..20] of string;
  c,sc:string;
  i,j,ml,n,mml:longint;
  save,ss:array[1..100] of longint;

Procedure qsort(l,r:longint);
var i,j,mid:longint;
  tmp:string;
begin
  i:=l;
  j:=r;
  mid:=length(a[(i+j) div 2]);
  repeat
    while length(a[i])<mid do inc(i);
    while length(a[j])>mid do dec(j);
    if i<=j then begin
      tmp:=a[i];
      a[i]:=a[j];
      a[j]:=tmp;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

Procedure print;
var i:longint;
  flag:boolean;
begin
  flag:=false;
  for i:=1 to j do if ss[i]<>save[i] then flag:=true;
  if flag then begin
    writeln(sc);
    halt;
  end;
end;

Procedure runing(k:longint);
var i,f:longint;
begin
    if c='' then print;
    if k>j then exit;
    for i:=1 to n do if (pos(a[i],c)<>0) then begin
      f:=pos(a[i],c);
      delete(c,f,length(a[i]));
      ss[k]:=i;
      runing(k+1);
      insert(a[i],c,f);
    end;
end;

Procedure find(l:longint);
var i,p:longint;
begin
  if l=0 then begin
    sc:=c;
    runing(1);
    exit;
  end;
  for i:=1 to n do if (l-length(a[i])>=mml) or (l-length(a[i])=0)  then begin
    inc(j);
    save[j]:=i;
    l:=l-length(a[i]);
    p:=length(c);
    c:=c+a[i];
    find(l);
    delete(c,p+1,100);
    l:=l+length(a[i]);
    dec(j);
  end;
end;

begin
  assign(input,'codes.in'); reset(input);
  assign(output,'codes.out'); rewrite(output);
  readln(n);
  ml:=20;
  for i:=1 to n do begin
    readln(a[i]);
    if length(a[i])<ml then ml:=length(a[i]);
  end;
  qsort(1,n);
  mml:=ml;
  ml:=ml+ml-1;
  while true do begin
    inc(ml);
    j:=0;
    c:='';
    find(ml);
  end;
  close(input);
  close(output);
end.