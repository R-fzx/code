type arr=array[0..400,0..400]of longint;
     ar=array[0..400]of longint;
var n,i,j,w:longint;
    f,a:arr;
    b,c:ar;
procedure gj(q,w:longint;var e:ar);
var i,t:longint;
begin
  t:=0;
  for i:=1 to 400 do begin
    e[i]:=f[q,i]+f[w,i]+t;
    t:=e[i] div 10;
    e[i]:=e[i] mod 10;
  end;
end;
function gj2(e:ar;q:longint):ar;
var i,t:longint;
begin
  t:=0;
  for i:=1 to 400 do begin
    gj2[i]:=e[i]+f[q,i]+t;
    t:=gj2[i] div 10;
    gj2[i]:=gj2[i] mod 10;
  end;
end;
procedure cl;
var i,j,k:integer;
begin
  for i:=3 to n do begin
    gj(i-1,i-2,b);
    for j:=1 to i-1 do begin
      c:=gj2(b,i);
      for k:=1 to 400 do
        f[i,k]:=c[k];
    end;
  end;
end;
begin
  assign(input,'t3.in');reset(input);
  assign(output,'t3.out');rewrite(output);
  readln(n);
  {for i:=1 to n do
  for j:=1 to n do
    read(a[i,j]);}
  f[1,1]:=0;f[2,1]:=1;
  cl;
  for i:=400 downto 1 do
    if f[n,i]<>0
      then begin w:=i; break; end;
  for i:=w downto 1 do
    write(f[n,i]);
  close(input);close(output);
end.
