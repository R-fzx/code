var n,i,j,a1,b1,r,k,s:longint;
    a,b:array[1..320]of longint;
begin
  assign(input,'t2.in');reset(input);
  assign(output,'t2.out');rewrite(output);
  for i:=1 to 32 do begin
    r:=1;
    for j:=1 to 10 do
      if r*i<=2000
        then begin
          inc(k);a[k]:=r*i;b[k]:=j;r:=a[k];
        end
        else break;
  end;
  for i:=1 to 320 do
    write(a[i]);
  repeat
    readln(a1,b1);s:=0;n:=0;
    if (a1=0)and(b1=0) then break;
    for i:=1 to k do
      if (a[k]>=a1)and(a[k]<=b1)
        then begin s:=s+b[k];inc(n); end;
    writeln(s);
    writeln(s+(b1-a1+1));
  until (a1=0)and(b1=0);
  close(input);close(output);
end.
