var x,y:array[1..200000] of 0..1000000;
    i,j,n:longint;
    min,dist:real;
    fi,fo:text;
function dis(a,b:longint):real;
begin
  dis:=sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
end;
begin
  assign(fi,'dark.in');reset(fi);
   readln(fi,n);
   for i:=1 to n do
     readln(fi,x[i],y[i]);
  close(fi);
  min:=-1;
  for i:=1 to n do
    for j:=1 to i-1 do begin
      dist:=dis(i,j);
      if (min>dist) or (min=-1) then min:=dist;
      if min=0 then break;
    end;
  assign(fo,'dark.out');rewrite(fo);
    writeln(fo,min:0:2);
  close(fo);
end.
