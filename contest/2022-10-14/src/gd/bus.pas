var fin,fou:text;
    ans,i,n,now:longint;
    p,a:array[1..100000]of longint;
procedure quick(l,r:longint);
var i,j,k,x:longint;
begin
  i:=l;j:=r;x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then begin
      k:=a[i];a[i]:=a[j];a[j]:=k;
      k:=p[i];p[i]:=p[j];p[j]:=k;
      inc(i);dec(j);
    end;
  until i>j;
if i<r then quick(i,r);
if l<j then quick(l,j);
end;
begin
assign(fin,'bus.in');
assign(fou,'bus.out');
reset(fin);
rewrite(fou);
  readln(fin,n);
  for i:=1 to n do begin
    read(fin,a[i]);
    p[i]:=i;
  end;
  quick(1,n);
  now:=n+1;
  for i:=1 to n do begin
    if p[i]<now then begin
      ans:=ans+a[i]*(now-p[i]);
      now:=p[i];
    end;
    if now=1 then break;
  end;
  writeln(fou,ans);
close(fin);
close(fou);
end.
