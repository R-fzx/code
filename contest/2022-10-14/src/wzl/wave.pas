var a,max:array[1..20] of integer;
    i,n,k,m:integer;
    tot,c:longint;
    fi,fo:text;
procedure print;
var j:integer;
begin
  for j:=1 to n do write(fo,a[j],' ');
  writeln(fo);
end;
function same:boolean;
var j:integer;
begin
  for j:=1 to i-1 do
    if a[j]=a[i] then exit(true);
  same:=false;
end;
begin
  assign(fi,'wave.in');reset(fi);
  assign(fo,'wave.out');rewrite(fo);
    readln(fi,m);
  for k:=1 to m do begin
  readln(fi,n,c);
  i:=1;
  a[1]:=0;
  max[1]:=n;
  tot:=0;
  while i>0 do begin
      repeat
        inc(a[i]);
      until (a[i]>max[i]) or not same;
      if a[i]>max[i] then dec(i)
                else if i=n then begin
                       inc(tot);
                       if tot=c then print;
                     end
                else begin
                       if i=1 then begin
                         a[i+1]:=0;
                         max[i+1]:=n;
                       end
                       else if a[i]>a[i-1] then begin
                              a[i+1]:=0;
                              max[i+1]:=a[i]-1;
                            end
                            else begin
                              a[i+1]:=a[i];
                              max[i+1]:=n;
                            end;
                       inc(i);
                     end
  end;
  end;
  close(fi);
  close(fo);
end.

